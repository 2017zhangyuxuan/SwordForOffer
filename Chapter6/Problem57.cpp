// Problem57.cpp
// Created by 张宇轩 on 2022/3/14.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

using namespace std;
/**
 * @brief 57、和为s的数字
 * 题目一：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
 * 如果有多对数字的和等于s，则输出任意一对即可
 */

#include<vector>

// 测试用例：两个数在头部、在尾部、一头一尾、正中间；找不到两个数

vector<int> get_sum_s(vector<int>& vec,int s) {
    vector<int> res;
    if (vec.size() < 2){
        return res;
    }
    int start = 0, end = vec.size()-1;
    while (start < end) {
        int sum = vec[start] + vec[end];
        if (sum > s) {
            end--;
        } else if (sum < s) {
            start++;
        } else {
            res.push_back(vec[start]);
            res.push_back(vec[end]);
            break;
        }
    }
    return res;

}


void Problem57() {

}