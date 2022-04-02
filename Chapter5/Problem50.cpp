// Problem50.cpp
// Created by 张宇轩 on 2022/3/9.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include <string>

using namespace std ;

/**
 * @brief 第一个只出现一次的字符
 * 题目一：字符串中第一个只出现一次的字符。
 */


char get_first_char(string s) {
    if (s.empty()){
        return '\0';
    }
    int count[26];
    int index[26];
    for (int i=0;i<26;i++) {
        count[i] = 0;
        index[i] = s.size();
    }
    int idx ;
    char res = '\0';
    for (int i=0; i< s.length();i++) {
        idx = s[i]-'a';
        count[idx]++;
        if (index[idx] > i) {
            index[idx] = i;
        }
    }
    for (int i=0;i<26;i++) {
        if (count[i] == 1) {
            if (res == 0 || index[res-'a'] > index[i]) {
                res = i + 'a';
            }
        }
    }
    return res;

}


void Problem50() {
    cout << get_first_char("aaaaaa") << endl;

}
