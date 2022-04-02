// Problem48.cpp
// Created by 张宇轩 on 2022/3/8.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

/**
 * @brief 48、最长不重复的子字符串
 * 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 * 假设字符串中只包含'a'~'z'的字符。例如，在字符串"arabcacfr"中，最长的不含重复字符的子字符串是"acfr"，长度为4
 */

void reset(bool* mark, int len) {
    for (int i=0;i<len;i++) {
        mark[i] = false;
    }
}

int get_max_no_duplicate_substr(char* str, int len) {
    if (str == nullptr || len <= 0)
        return 0;
    int res = 1;
    int count[len];
    bool mark[26];
    int index[26];
    reset(mark,26);
    for (int i = 0; i < len; ++i) {
        int idx = str[i]-'a';
        if (i == 0) {
            count[i] = 1;
            mark[idx] = true;
            continue;
        }
        if (!mark[idx]) {
            mark[idx] = true;
            count[i] = count[i-1]+1;
            index[idx] = i;
        } else {
            count[i] = i - index[idx];
            for (int j = i- count[i-1];j < index[idx];j++){
                mark[str[j]-'a'] = false;
            }
            index[idx] = i;
        }
        if (res < count[i]) {
            res = count[i];
        }

    }
    return res;

}


void Problem48(){
    char* str= "arabcacfr";
    std::cout << get_max_no_duplicate_substr(str,9) << std::endl;

}