// Problem38.cpp
// Created by 张宇轩 on 2022/3/4.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include <string>
using namespace std;
/**
 * @brief 38、字符串的排列
 * 输入一个字符串，打印出该字符串中字符的所有排列
 */

void dfs_print(string& input, bool* mark, int layer, string res) {
    if (input.empty() || mark == nullptr)
        return;
    int len = input.length();
    if (layer == len) {
        cout << res << endl;
        return;
    }
    for (int i = 0; i < len; ++i) {
        if (!mark[i]) {
            mark[i] = true;
            dfs_print(input, mark, layer+1, res+input[i]);
            mark[i] = false;
        }
    }

}

void print_permutation(string input) {
    if (input.empty())
        return;
    int len = input.length();
    bool mark[len];
    memset(mark, false, len);
    for (int i = 0; i < len; ++i) {
        mark[i] = true;

        string res = input.substr(i,1);
        dfs_print(input, mark, 1, res);
        mark[i] = false;
    }

}

void combination(const string& str, int m, string res) {
    if (m > str.length())
        return;
    if (m == str.length()) {
        cout << str + res << endl;
        return;
    }
    combination(str.substr(1),m-1, str[0] + res);
    combination(str.substr(1), m,res);

}

// 求出所有字符的组合
void print_combination(string str) {
    if (str.empty())
        return;

    int len = str.length();
    for (int i = 1; i <= len; ++i) {
        combination(str, i, "");
    }
}
#include <queue>
#include <map>
struct cmp {
    bool operator()(const pair<int,int>&a, const pair<int,int>& b) {
        return a.second > b.second;
    }
};


#include <sstream>
void Problem38() {
//    print_permutation("abc");
//    print_combination("abc");



}