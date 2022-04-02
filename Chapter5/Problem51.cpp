// Problem51.cpp
// Created by 张宇轩 on 2022/3/10.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

/**
 * @brief 51、数组中的逆序对
 * 在数组的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
 * 输入一个数组，求出这个数组中的逆序对的综述。
 */

void merge_sort(int *arr ,int start, int end, int* res) {
    if (arr == nullptr || start >= end) {
        return;
    }
    int mid = start + (end-start) / 2;
    merge_sort(arr,start, mid, res);
    merge_sort(arr,mid+1, end, res);
    int tmp[end - start + 1];
    int idx = 0;
    int num = 0;        // 记录后面的数组中有多个数字已经排好序了
    int idx1 = start;
    int idx2 = mid+1;
    while (idx1 <= mid && idx2 <= end) {
        if (arr[idx1] <= arr[idx2]) {
            tmp[idx++] = arr[idx1++];
            *res += num;
        } else {
            tmp[idx++] = arr[idx2++];
            num++;
        }
    }
    if (idx1 > mid) {
        while (idx2 <= end) {
            tmp[idx++] = arr[idx2++];
        }
    }
    if (idx2 > end) {
        while (idx1 <= mid) {
            tmp[idx++] = arr[idx1++];
            *res += num;
        }
    }
    for (int i=0; i < idx; i++ ) {
        arr[start+i] = tmp[i];
    }
}

int get_reverse_num (int *arr, int len) {
    if (arr == nullptr || len <= 0) {
        return 0;
    }
    int res = 0;
    merge_sort(arr,0, len-1, &res);
    return res;
}

void Problem51() {
    int arr[] = {7,5,6,4,8};
    std::cout << get_reverse_num(arr, 5) << std::endl;

}