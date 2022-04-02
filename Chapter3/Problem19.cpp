// Problem19.cpp
// Created by 张宇轩 on 2022/2/25.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

/**
 * @brief 19、正则表达式匹配
 * 请实现一个函数用来匹配包含'.' 和 '*' 的正则表达式。模式中的字符 '.' 表示任意一个字符，
 * 而 '*' 表示它前面的字符可以出现任意次（含0次）。在本题中，匹配是指字符串的所有字符匹配整个模式
 */

// 测试用例： str:aaa   pattern: a.a  ab*ac*a  - true |   aa.a   ab*a   - false
// 建立非确定有限状态自动机

bool match_core(char* str, char* pattern) {
    if (*str == '\0' && *pattern == '\0')
        return true;
    if (*str != '\0' && *pattern == '\0')
        return false;

    if (*(pattern+1) == '*') {
        if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
            return  match_core(str, pattern+2) ||       // 忽略，并前进状态
                    match_core(str+1, pattern) ||          // 保持状态
                    match_core(str+1,pattern+2);    // 前进状态
        } else {
            return match_core(str, pattern+2);
        }
    } else {
        if (*str == *pattern || (*pattern =='.' && *str != '\0'))
            return match_core(str+1, pattern+1);
    }
    return false;
}

bool match(char* str, char* pattern) {
    if (str == nullptr || pattern == nullptr)
        return false;
    return match_core(str,pattern);
}

void Problem19() {
    char str[] = "aaa";
    char pattern[] = "ab*a";
    std::cout << std::boolalpha << match(str, pattern) << std::endl;

}