// Problem42.cpp
// Created by 张宇轩 on 2022/3/6.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

using namespace std;
/**
 * @brief 42、连续子数组的最大和
 * 输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。
 * 求所有子数组的和的最大值。要求时间复杂度为O(n)
 */

// 测试用例：0、1个数； 全是正数、全是负数； 有正有负

int get_max_sum(int* arr, int len) {
    if (arr == nullptr || len <=0)
        return 0;
    int sum = 0;
    int res = INT32_MIN;
    for (int i=0; i<len;i++ ) {
        sum += arr[i];
        if (res < sum) {
            res = sum;
        }
        if (sum <= 0) {
            sum = 0;
        }
    }
    return res;

}

void Problem42() {
    int arr[] = {-1,2,3,4,-1};
    int arr1[] = {-1,-2,-1,-2,-3};
    int arr2[] = {1,1,2,3,5};
    int arr3[] = {};
    int arr4[] = {1};
    cout << get_max_sum(arr,5) << endl;     // 9
    cout << get_max_sum(arr1,5) << endl;     //-1
    cout << get_max_sum(arr2,5) << endl;     //12
    cout << get_max_sum(arr3,0) << endl;     //0
    cout << get_max_sum(arr4,1) << endl;     //1
}