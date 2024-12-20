cmake_minimum_required(VERSION 3.17)
project(SelectDemo)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(Select_Server select_server.cpp)
add_executable(SelectClient select_client.cpp)

target_link_libraries(Select_Server pthread)