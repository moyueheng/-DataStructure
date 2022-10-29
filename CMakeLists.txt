
# 存在一些环境变量
cmake_minimum_required(VERSION 3.16.3 )
# cmake version 3.16.3
# Set the project name
project ( DataStructure )

include_directories(include) # 添加头文件路径
aux_source_directory(src SRCS) # 添加

# 在终端打印
# message( STATUS "CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}" )
# message( STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}" )

# Add an executable
add_executable( ${CMAKE_PROJECT_NAME} ${SRCS} main.c)