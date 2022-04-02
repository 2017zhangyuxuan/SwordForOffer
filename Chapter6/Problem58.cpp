// Problem58.cpp
// Created by 张宇轩 on 2022/3/14.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

using namespace std;
/**
 * @brief 58、翻转字符串
 * 题目一：翻转单词顺序
 * 输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
 * 例如输入字符串 "I am a student." 则输出 "student. a am I"
 */

#include <string>
#include <stack>
string reverse_words(char* words, int len) {
    if (words == nullptr || len <=0)
        return "";
    string res,word;
    stack<string> s;
    for (int i=0; i< len; i++) {
        if (words[i] != ' ') {
            word.push_back(words[i]);
        } else {
            s.push(word);
            word.clear();
        }
    }
    if (!word.empty()) {
        s.push(word);
    }
    while (!s.empty()) {
        res += s.top();
        s.pop();
        if (s.size() > 0) {
            res += " ";
        }
    }
    return res;

}

void Problem58() {
    char* words = "I am a student.";
    int len = 15;
    cout << reverse_words(words,15) << endl;
}