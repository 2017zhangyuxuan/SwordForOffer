// Problem20.cpp
// Created by 张宇轩 on 2022/2/25.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

/**
 * @brief 20、表示数值的字符串
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）
 */

// 测试用例：+100，5e2, -123, 3.1416 , -1E-16 是
// 反例：12e, 1a3.14, 1.2.3, +-5, 12e+5.4
// 表示数值的字符串遵循模式 A[.[B]][e|EC] 或者 .B[e|EC]
// 其中  A 和 C 都是可能以 '+'或'-' 开头的0~9的数位串；B也是0~9的数位串，但前面不能有符号

bool scan_unsigned_integer(const char** str) {
    const char* before = *str;
    while (**str != '\0' && **str >= '0' && **str <='9')
        (*str)++;
    return *str > before;
}

bool scan_integer(const char** str) {
    if (**str == '\0')
        return false;
    if (**str == '+' || **str =='-') {
        (*str)++;
    }
    return scan_unsigned_integer(str);
}


bool is_number(const char* str) {
    if (str == nullptr)
        return false;

    bool numberic = scan_integer(&str);
    if (*str == '.') {
        str++;
        numberic =  scan_unsigned_integer(&str) || numberic;
    }
    if (*str == 'e' || *str=='E') {
        str++;
        numberic = scan_integer(&str) && numberic;
    }
    return numberic && *str == '\0';

}


void Problem20() {
    char s1[] = "+100";
    char s2[] ="5e2";
    char s3[] = "-123";
    char s4[] = "3.1416";
    char s5[] = "-1E-16";
    char s6[] = "12e";
    char s7[] = "1a3.14";
    char s8[] = "1.2.3";
    char s9[] = "+-5";
    char s10[] = "12e+5.4";
    std::cout << std::boolalpha << is_number(s1) << std::endl;
    std::cout << std::boolalpha << is_number(s2) << std::endl;
    std::cout << std::boolalpha << is_number(s3) << std::endl;
    std::cout << std::boolalpha << is_number(s4) << std::endl;
    std::cout << std::boolalpha << is_number(s5) << std::endl;
    std::cout << std::boolalpha << is_number(s6) << std::endl;
    std::cout << std::boolalpha << is_number(s7) << std::endl;
    std::cout << std::boolalpha << is_number(s8) << std::endl;
    std::cout << std::boolalpha << is_number(s9) << std::endl;
    std::cout << std::boolalpha << is_number(s10) << std::endl;


}