// Problem56.cpp
// Created by 张宇轩 on 2022/3/13.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

using namespace std;
/**
 * @brief 56、数组中数字出现的次数
 * 题目一：数组中只出现一次的两个数字
 * 一个整数型数组里除两个数字之外，其他数字都出现了两次，请求写程序找出这个两个只出现一次的数字。
 * 要求时间复杂度O(n)，空间复杂度O(1)
 */

#include <vector>
vector<int> get_one_time_num(vector<int>& vec) {
    vector<int> res;
    if (vec.size() == 0 || vec.size() % 2 == 1)
        return res;
    int x_y = 0;
    for (int n : vec) {
        x_y ^= n;
    }
    if (x_y == 0) {
        return res;
    }

    // 保留最右侧的1 bit
    int n_bit = (x_y ^ (x_y-1)) & x_y;
    int x = 0, y = 0;
    for (int n : vec) {
        if ((n & n_bit) > 0) {
            x ^= n;
        } else {
            y ^= n;
        }
    }
    res.push_back(x);
    res.push_back(y);
    return res;
}



void Problem56() {
    vector<int> vec {4,6,1,1,1,1};
    vector<int> res = get_one_time_num(vec);
    for (int i : res) {
        cout << i << " ";
    }
}