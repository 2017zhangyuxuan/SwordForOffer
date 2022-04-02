// Problem58_2.cpp
// Created by 张宇轩 on 2022/3/14.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

using namespace std;
/**
 * @brief 58_2：左旋字符串
 * 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
 * 例如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"
 */

#include<string>

// 测试用例：移动0位、1位、2位、全部位；负数？

string left_reverse_string(string str, int num) {
    if (str.empty() || num < 0) {
        return "";
    }
    num = num % str.length();
    if (num == 0) {
        return str;
    }
    string res;
    int len = str.length();
    res.resize(len);
    int idx = 0;
    for (int i=num; i < len; i++) {
        res[idx++] = str[i];
    }
    for (int i=0; i < num;i++) {
        res[idx++] = str[i];
    }
    return res;

}


void Problem58_2() {
    string str = "abcdefg";
    cout << left_reverse_string(str,8) << endl;
}