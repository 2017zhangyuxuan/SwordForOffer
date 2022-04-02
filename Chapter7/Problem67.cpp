// Problem67.cpp
// Created by 张宇轩 on 2022/3/18.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

/**
 * @brief 67、把字符串转换成整数（难度加大的话，换成double）
 */

// 测试用例：
// 功能测试：123、+123、-123
// 边界测试：最大正数、最大负数
// 错误测试：空指针、非法输入、"" 空串

enum Status {
    k_valid = 0,
    k_invalid
} status ;

int str_to_int(const char* str) {
    status = k_valid;
    long num = 0;
    if (str == nullptr || *str == '\0') {
        status = k_invalid;
        return num;
    }
    bool is_positive = true;
    if (*str == '+') {
        str++;
    } else if (*str == '-') {
        is_positive = false;
        str++;
    }
    // 判断只有正负号，也是错误的
    if (*str == '\0') {
        status = k_invalid;
        return num;
    }
    while (*str != '\0') {
        if (*str > '9' || *str < '0') {
            status = k_invalid;
            return num;
        } else {
            num = num * 10 + *str - '0';
            if (is_positive && num > INT32_MAX) {
                status = k_invalid;
                return 0;
            }
            if (!is_positive && -num < INT32_MIN) {
                status = k_invalid;
                return 0;
            }
        }
        str++;
    }
    if (!is_positive) {
        num = -num;
    }
    return num;

}

void Problem67() {

}
