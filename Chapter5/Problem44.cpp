// Problem44.cpp
// Created by 张宇轩 on 2022/3/7.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

/**
 * @brief 44、数字序列中某一位的数字
 * 数字以012345678910111213···· 的格式序列化到一个字符序列中，第5位（从0开始计数）是5，
 * 第13位是1，第19位是4。请编写一个函数，求任意第n位对应的数字
 */

int get_n_num(int n) {
    if (n < 0)
        return -1;
    if (n < 10) {
        return n;
    }
    int res =0 ;
    n -= 9;
    int nums = 9;
    int chars = 2;
    int digit = 10;
    while (n / chars > nums * digit) {
        n -= chars * nums * digit;
        chars++;
        digit*=10;
    }

    int business = n / chars;
    int reminder = n % chars;
    if (reminder == 0) {
        int num = digit + business -1;
        res = num % 10;
    } else {
        int num = digit + business;
        int divisor = digit;
        for (int i=1; i< reminder;i++) {
            divisor /= 10;
        }
        res = num / divisor % 10;
    }
    return res;
}
#include <string>
void Problem44() {
    std::cout << get_n_num(1001) << std::endl;

}
