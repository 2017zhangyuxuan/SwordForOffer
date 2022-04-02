// Problem47.cpp
// Created by 张宇轩 on 2022/3/8.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

/**
 * @brief 47、礼物的最大价值
 * 在一个 m × n 的棋盘上的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于0）。
 * 你可以从棋盘的左上角开始拿格子里额礼物，并每次向左或者向下移动一格，直到到达棋盘的右下角。
 * 给定一个棋盘及其上面的礼物，请计算你最多能拿到多少价值的礼物？
 */

// 测试用例：走两侧的；走中间的

int get_max_value(int *arr, int rows, int cols) {
    if (arr == nullptr || rows <= 0 || cols <= 0) {
        return 0;
    }
    int value[rows][cols];
    value[0][0] = arr[0];
    for (int i = 1; i < cols; i++) {
        value[0][i] = value[0][i - 1] + arr[i];
        value[i][0] = value[i-1][0] + arr[i * cols];
    }
    for (int i=1; i<rows; i++) {
        for (int j=1; j< cols; j++) {
            value[i][j] = std::max(value[i-1][j],value[i][j-1]) + arr[i*cols + j];
        }
    }
    return value[rows-1][cols-1];

}

int get_max_value2(int *arr, int rows, int cols) {
    if (arr == nullptr || rows <= 0 || cols <= 0) {
        return 0;
    }
    int value[cols];
    for (int i=0; i<rows; i++) {
        for (int j=0;j<cols;j++) {
            int val = arr[i * cols + j];
            if (i == 0 && j == 0) {
                value[j] = val;
                continue;
            }
            if (i == 0) {
                value[j] = value[j-1] + val;
                continue;
            }
            if (j == 0) {
                value[j] = value[j] + val;
                continue;
            }
            value[j] = std::max(value[j-1],value[j]) + val;
        }
    }
    return value[cols-1];
}

void Problem47() {
    int arr[] = {
        1,10,3,8,
        12,2,9,6,
        5,7,4,11,
        3,7,16,5
    };
    std::cout << get_max_value(arr,4,4) << std::endl;
    std::cout << get_max_value2(arr,4,4) << std::endl;
}