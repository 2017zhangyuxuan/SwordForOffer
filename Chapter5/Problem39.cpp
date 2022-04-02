// Problem39.cpp
// Created by 张宇轩 on 2022/3/5.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief 39、数组中出现次数超过一半的数字
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字
 */

// 测试用例：没有这样的数字怎么办？   正常例子；全是相同的数

#include <unordered_map>

int get_over_half_num(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) {
        return 0;
    }
    int res = 0;
    unordered_map<int, int> m;
    for (int num : nums) {
        m[num]++;
        if (m[num] > len/2) {
            res = num;
            break;
        }
    }
    return res;
}

int get_half_num(vector<int>& nums) {
    int len = nums.size();
    if (len == 0) {
        return 0;
    }
    int res = nums[0];
    int count = 1;
    for (int i=1; i< len; i++) {
        if (nums[i] == res) {
            count ++;
        } else {
            count --;
            if (count == 0) {
                res = nums[i];
                count = 1;
            }

        }
    }
    return res;

}

void Problem39() {
    vector<int> vec = {1,1,1,2,2,1,2};
    cout << get_half_num(vec) << endl;
    cout << get_over_half_num(vec) << endl;
}