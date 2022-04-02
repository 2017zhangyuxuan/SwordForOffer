// Problem15.cpp
// Created by 张宇轩 on 2022/2/22.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
//
#include<iostream>

/**
 * @brief 15、二进制中 1 的个数
 * 请实现一个函数，输入一个整数，输出该二进制数表示中1的个数
 */

int get_num_of_one(int num) {
    if (num == 0)
        return 0;
    int cnt = 0;
    while (num != 0) {
        num = num & (num-1);
        cnt ++ ;
    }
    return cnt;
}
void Problem15() {
    std::cout << get_num_of_one(0x80000000) << std::endl;

}