// Problem65.cpp
// Created by 张宇轩 on 2022/3/18.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

using namespace std;
/**
 * @brief 65、不用加减乘除做加法
 * 写一个函数，求两个整数之和，要求再函数体内不得用"+"、"-"、"×"、"÷"四则运算符号
 */

int compute_sum(int num1, int num2) {
    int exclusive_or = num1 ^ num2;
    int and_with = num1 & num2;

    int add = 2;
    while (and_with != 0) {
        while ((and_with & 1 )== 0) {
            and_with >>= 1;
            add <<= 1;
        }
        and_with &= ~1;     // 把进位置0
        int tmp = add;
        // 找到左侧第一个不为0的位置
        while ((exclusive_or & tmp) != 0) {
            exclusive_or &= ~tmp;       // 当前位置0
            tmp <<= 1;
        }
        exclusive_or |= tmp;

    }
    return exclusive_or;
}


int add(int num1, int num2) {
    int sum ;
    int carry ;
    do {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    } while (carry != 0);
    return sum;
}

void Problem65() {
    cout << compute_sum(-21321301,2132130) << endl;
    cout << add(21321301,-2132130) << endl;
}