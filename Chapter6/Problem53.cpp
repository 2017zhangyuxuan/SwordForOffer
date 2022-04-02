// Problem53.cpp
// Created by 张宇轩 on 2022/3/12.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

using namespace std;
/**
 * @brief 53、在排序数组中查找数字
 * 题目一：数字在排序数组中出现的次数
 * 统计一个数字在排序数组中出现的次数，例如{1,2,3,3,3,3,4,5}，其中3出现了4次
 *
 * 题目二：0 ~ n-1中缺失的数字
 * 一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0~n-1之内。
 * 在范围0~n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字
 *
 * 题目三：数组中数值和下标相等的元素
 * 假设一个单调递增的数组里的每个元素都是整数并且是唯一的，请编程实现一个函数，找出数组中
 * 任意一个数值等于其下标的元素
 */

// 测试用例：边界：{1,1,1}找1  错误测试：{1,2,3} 找4


int get_first_num(int*arr, int start, int end, int num) {
    if (arr == nullptr || start > end) {
        return -1;
    }
    int mid;
    while (start < end) {
        mid = start + (end-start) / 2;
        if (arr[mid] >= num) {
            end = mid;
        } else {
            start = mid+1;
        }
    }
    if (arr[start] == num){
        return start;
    }
    return -1;

}

int get_last_num(int *arr, int start, int end, int num) {
    if (arr == nullptr || start > end) {
        return -1;
    }
    int mid;
    while (start < end) {
        mid = (end + start + 1 ) / 2;
        if (arr[mid] <= num) {
            start = mid;
        } else {
            end = mid-1;
        }
    }
    if (arr[start] == num){
        return start;
    }
    return -1;
}

int get_show_times(int*arr, int len, int num) {
    if (arr == nullptr || len <= 0) {
        return 0;
    }
    int first = get_first_num(arr,0, len-1, num);
    if (first == -1) {
        return 0;
    }
    int last = get_last_num(arr, first, len-1, num);
    return last - first + 1;
}

int get_lost_num(int* arr, int len) {
    if (arr == nullptr || len <=0) {
        return -1;
    }
    int start = 0, end = len-1;
    int mid;
    while (start < end) {
        mid = (start + end) / 2;
        if (arr[mid] == mid) {
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    if (arr[start] == start) {
        return start+1;
    }
    return start;

}

int get_equal_index_num(int *arr, int start, int end) {
    if (arr == nullptr || start > end) {
        return -1;
    }
    int mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] == mid) {
            return mid;
        } else if (arr[mid] > mid) {
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    return -1;
}

#include <set>
#include <queue>
void Problem53() {
    int arr[] = {1,2,3,3,3,3,4,5};
    int arr1[] = {1,1,1};
    int arr2[] = {1,2,3};
    int arr4[] = {0,1,2};
    int arr5[] = {-3,-1,0,4,5};
    std::cout << get_show_times(arr,8,3) << std::endl;
    std::cout << get_show_times(arr1,3,1) << std::endl;
    std::cout << get_show_times(arr2,3,4) << std::endl;
    std::cout << get_lost_num(arr4,3) << std::endl;
    std::cout << get_equal_index_num(arr5,0,4) << std::endl;

}
