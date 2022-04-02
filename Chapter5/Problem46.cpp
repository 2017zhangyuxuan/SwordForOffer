// Problem46.cpp
// Created by 张宇轩 on 2022/3/8.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include <string>

using namespace std;
/**
 * @brief 46、把数字翻译成字符串
 * 给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻译成"b" ，，，，25 翻译成"z"。
 * 一个数字可能有多个翻译，例如12258有5种不同的翻译，分别是"bccfi"，"bwfi"，"bczi"，"mcfi"，"mzi"
 * 请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法
 */

// 测试用例：11258， 1000，负数，11111

int get_diff_translate(string num) {
    if (num.empty() || num.size() == 1)
        return 1;
    int res = get_diff_translate(num.substr(1));
    string tmp = num.substr(0, 2);
    if (atoi(tmp.c_str()) <= 25) {
        res += get_diff_translate(num.substr(2));
    }
    return res;
}

int get_diff_translate(int num) {
    if (num < 0)
        return 0;
    string str = to_string(num);
    int res = get_diff_translate(str);
    return res;
}

int get_diff_translate2(int num) {
    if (num < 0)
        return 0;
    string str = to_string(num);
    int len = str.length();
    int count[len + 1];       // 多申请一个
    for (int i = 0; i < len + 1; i++) {
        count[i] = 1;
    }

    for (int i = len - 1; i >= 0; i--) {
        if (i == len - 1) {
            count[i] = 1;
        } else {
            string tmp = str.substr(i, 2);
            if (atoi(tmp.c_str()) <= 25) {
                count[i] = count[i + 1] + count[i + 2];
            } else {
                count[i] = count[i + 1];
            }
        }
    }
    return count[0];
}

void Problem46() {
    cout << get_diff_translate(11111) << endl;
    cout << get_diff_translate2(11111) << endl;
}
