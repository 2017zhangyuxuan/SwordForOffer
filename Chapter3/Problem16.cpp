// Problem16.cpp
// Created by 张宇轩 on 2022/2/23.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
//
#include<iostream>
/**
 * @brief 16、数值的整数次方
 * 实现函数 double Power(double base, int exponent), 求base的exponent次方。
 * 不得使用库函数，同时不需要考虑大数问题
 */

// 测试用例：底数和指数 分别为 0、正数、负数的情况
double power_with_unsigned_int(double base, unsigned int exponent) ;

double Power(double base, int exponent) {
    if (base == 1.0) {
        return 1;
    }
    if (base == 0) {
        if (exponent >= 0)
            return 0;
        else
            throw "error!";
    }
    double res;
    if (exponent < 0) {
        res = power_with_unsigned_int(base, -exponent);
        res = 1.0 / res;
    } else {
        res = res = power_with_unsigned_int(base, exponent);
    }
    return res;

}

double power_with_unsigned_int(double base, unsigned int exponent) {
    if (exponent == 0) {
        return 1.0;
    }
    if (exponent == 1) {
        return base;
    }
    double ans = 1.0;
    while (exponent > 0) {
        if (exponent & 1) {
            ans *= base;
        }
        base *= base;
        exponent >>= 1;
    }
    return ans;

}

void Problem16() {
    std::cout << Power(0,1) << std::endl;
    std::cout << Power(3,-2) << std::endl;
}