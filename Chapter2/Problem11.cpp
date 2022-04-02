// Problem11.cpp
// Created by 张宇轩 on 2022/2/21.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
//
#include <iostream>

/**
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个递增排序的数组的一个旋转，
 * 输出旋转数组的最小元素。
 * 例如，数组{3,4,5,1,2} 为 {1,2,3,4,5} 的一个旋转，该数组最小元素为1
*/
int get_minest(int arr[], int length);

void Problem11() {
    int arr1[] = {3,4,5,1,2};
    int arr2[] = {1,0,1,1,1};
    int arr3[] = {1,1,1,0,1};
    int* arr4 = nullptr;
    int arr5[] = {3,3,4,0,2,2};
    std::cout << get_minest(arr1,5) << std::endl;
    std::cout << get_minest(arr2,5) << std::endl;
    std::cout << get_minest(arr3,5) << std::endl;
    std::cout << get_minest(arr4,5) << std::endl;
    std::cout << get_minest(arr5,6) << std::endl;
}


// 顺序遍历，查找数组中的最小值
int get_min_inorder(int* arr, int length) {
    // 错误处理
    if (arr == nullptr || length <= 0) {
        return -1;
    }
    int min = arr[0];
    for (int i=1; i< length; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int get_minest(int* arr, int length) {
    if (arr == nullptr || length <=0) {
        return -1;
    }
    // 如果数组只有一个元素，或者数组本身依然是有序的
    if (length == 1 || arr[0] < arr[length-1]) {
        return arr[0];
    }
    int left = 0, right = length-1;
    int mid;
    while (right - left > 1) {
        mid = left + (right - left) / 2;
        // 如果左、中、右 指针向的数字都相同，那就无法区分中间指向的数字是位于第一个递增数组中还是第二个
        // 此时就需要使用顺序遍历的方法来查找
        if (arr[mid] == arr[left] && arr[mid] == arr[right]){
            return get_min_inorder(arr, length);
        }
        if (arr[mid] >= arr[left]) {
            left = mid;
        } else if (arr[mid] <= arr[right]) {
            right = mid;
        }

    }
    return arr[right];
}


