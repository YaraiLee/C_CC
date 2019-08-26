#CMake 最低版本要求
cmake_minimum_required(VERSION 2.8)

# 项目信息
project(Case_1)

# 源文件
aux_source_directory(. DIR_SRCS)

#指定生成目标case_1
add_executable(case_1 ${DIR_SRCS})