#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

struct FDInfo {
    int fd;
    fd_set* rdset;
    int* maxfd;
};

void acceptFunc(FDInfo* info) {
    // 监听到新的连接了
    // 接受连接请求, 这个调用不阻塞
    struct sockaddr_in cliaddr;
    socklen_t cliLen = sizeof(cliaddr);
    int cfd = accept(info->fd, (struct sockaddr*)&cliaddr, &cliLen);
    if (cfd >= 0) {
        printf("新客户端连接: fd=%d\n", cfd);
        mtx.lock();
        FD_SET(cfd, info->rdset); // cfd下一轮监听，用于通信

        *(info->maxfd) = cfd > *(info->maxfd) ? cfd : *(info->maxfd);
        mtx.unlock();
    }
    else {
        perror("accept");
    }

    delete info;
    return;
}

void communication(FDInfo* info) {
    // 接收数据
    printf("准备从客户端 fd=%d 读取数据...\n", info->fd); // 调试信息
    char buf[1024] = {0};
    // 一次只能接收10个字节, 客户端一次发送100个字节
    // 一次是接收不完的, 文件描述符对应的读缓冲区中还有数据
    // 下一轮select检测的时候, 内核还会标记这个文件描述符缓冲区有数据 -> 再读一次
    // 	循环会一直持续, 知道缓冲区数据被读完位置
    int len = read(info->fd, buf, sizeof(buf) - 1);
    if(len == 0)
    {
        printf("客户端 fd=%d 已关闭连接。\n", info->fd);
        // 将检测的文件描述符从读集合中删除
        mtx.lock();
        FD_CLR(info->fd, info->rdset);
        mtx.unlock();
        close(info->fd);

        delete info;
        return;
    }
    else if(len > 0)
    {
        // 收到了数据
        // 发送数据
        buf[len] = '\0'; // 确保字符串以 '\0' 结尾
        printf("从客户端接收到: %s\n", buf);
        int res = write(info->fd, buf, strlen(buf)+1);
        if (res == -1) {
            perror("write");
            delete info;
            exit(1);
        }
    }
    else
    {
        // 异常
        perror("read");
        delete info;
        exit(1);
    }
    delete info;
    return;
}

int main()
{
    // 1. 创建监听的fd
    int lfd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. 绑定
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    addr.sin_addr.s_addr = INADDR_ANY;
    bind(lfd, (struct sockaddr*)&addr, sizeof(addr));

    // 3. 设置监听
    listen(lfd, 128);

    int maxfd = lfd;
    fd_set rdset;
    fd_set tempset;
    FD_ZERO(&rdset);
    FD_SET(lfd, &rdset);

    // 通过select委托内核检测读集合中的文件描述符状态, 检测read缓冲区有没有数据
    // 如果有数据, select解除阻塞返回
    // 应该让内核持续检测
    while (1)
    {
        mtx.lock();
        tempset = rdset;
        mtx.unlock();
        int num = select(maxfd + 1, &tempset, NULL, NULL, NULL);

        if (FD_ISSET(lfd, &tempset)) {
           FDInfo* info = new FDInfo;
            info->fd = lfd;
            info->rdset = &rdset;
            info->maxfd = &maxfd;
            thread t(acceptFunc, info);
            t.detach();
        }
        for (int i = 0; i <= maxfd; i++) {
            if (i != lfd && FD_ISSET(i, &tempset)) {
                FDInfo* info = new FDInfo;
                info->fd = i;
                info->rdset = &rdset;

                thread t(communication, info);
                t.detach();
            }
        }
    }

    close(lfd);
    return 0;
}