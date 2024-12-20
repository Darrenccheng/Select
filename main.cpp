#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

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
        tempset = rdset;
        int num = select(maxfd + 1, &tempset, NULL, NULL, NULL);

        if (FD_ISSET(lfd, &tempset)) {
            // 监听到新的连接了
            // 接受连接请求, 这个调用不阻塞
            struct sockaddr_in cliaddr;
            socklen_t cliLen = sizeof(cliaddr);
            int cfd = accept(lfd, (struct sockaddr*)&cliaddr, &cliLen);

            FD_SET(cfd, &rdset); // cfd下一轮监听，用于通信
            maxfd = cfd > maxfd ? cfd : maxfd;
        }
        for (int i = 0; i <= maxfd; i++) {
            if (i != lfd && FD_ISSET(i, &tempset)) {
                
            }
        }
    }

    return 0;
}