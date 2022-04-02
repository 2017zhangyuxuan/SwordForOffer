// Problem56_2.cpp
// Created by 张宇轩 on 2022/3/13.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

/**
 * @brief 56_2
 * 题目二：数字中唯一只出现一次的数字
 * 在一个数组中除一个数字只出现一次外，其他数字都出现了三次。请找出那个只出现一次的数字
 */

bool flag;
int get_only_once_num(int *arr, int len) {
    if (arr == nullptr || len <= 0) {
        flag = false;
        return 0;
    }
    int bit_sum[32];
    for (int i=0;i<32;i++){
        bit_sum[i] = 0;
    }
    for (int i=0;i<len;i++) {
        int num = arr[i];
        for (int i=0;i<32;i++) {
            if ( (num & (1 << i)) > 0) {
                bit_sum[i]++;
            }
        }
    }
    int res = 0;
    for (int i=0;i<32;i++) {
        if (bit_sum[i] % 3 != 0) {
            res |= (1 << i);
        }
    }
    return res;

}



#include <vector>

using namespace std;
void Problem56_2() {
    int arr[] = {10,10,11,1,2,3,3,3,2,2,1,1,10};
    std::cout << get_only_once_num(arr,13) << std::endl;

}