// Problem21.cpp
// Created by 张宇轩 on 2022/2/26.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

/**
 * @brief 21、调整数组顺序使奇数位于偶数前面
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，
 * 所有偶数位于数组的后半部分
 */

void partition(int* arr, int length) {
    if (arr == nullptr || length <=0 )
        return ;
    int start = 0, end = length - 1;
    while (start < end) {
        // 找到第一个偶数
        while (start < end && (arr[start] & 1) ) {
            start ++;
        }
        // 找到第一个奇数
        while (start < end && ((arr[end] & 1) == 0)) {
            end --;
        }
        std::swap(arr[start], arr[end]);
    }
}


void Problem21() {
    int arr[] = {9,1,2,2,2,3,4,5,9};
    partition(arr,9);
    for (int i : arr) {
        std::cout << i << " ";
    }
}