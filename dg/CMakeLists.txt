cmake_minimum_required(VERSION 3.28)
project(dg)

set(CMAKE_CXX_STANDARD 17)

add_executable(dg main.cpp
        递归/汉诺塔.cpp
        递归/合并两个有序链表.cpp
        递归/反转链表.cpp
        递归/两两交换链表中的结点.cpp
        "递归/Pow(x,n).cpp"
)
