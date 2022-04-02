// Problem29.cpp
// Created by 张宇轩 on 2022/2/28.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
using namespace std;
/**
 * @brief 29、顺时针打印矩阵
 * 输入一个矩阵，按照从外向里以顺时针的顺序打印出每一个数字
 */


bool change_direction(int x, int y, const int rows, const int columns, bool*mark) {
    if (x < 0 || x>=rows || y<0|| y>=columns || mark[x*columns + y])
        return true;
    return false;
}

void print_matrix(int* matrix, int rows, int columns) {
    if (matrix == nullptr || rows <= 0 || columns <= 0)
        return;

    bool mark[rows * columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            mark[i*columns + j] = false;
        }
    }

    int step[4][2] = {
            0,1,
            1,0,
            0,-1,
            -1,0
    };

    int index = 0;
    int times = rows * columns;
    int x = 0,y = 0;

    for (int i = 0; i < times; i++) {
        cout << matrix[x * columns + y] << " ";
        mark[x * columns +  y] = true;

        int next_x = x + step[index][0];
        int next_y = y + step[index][1];
        if (change_direction(next_x, next_y, rows, columns, mark)) {
            index = (index+1) % 4;
            next_x = x + step[index][0];
            next_y = y + step[index][1];
        }
        x = next_x;
        y = next_y;
    }

}

void print_matrix_in_circle(int** number, int rows, int columns, int start) {
    int endy = columns-1-start;
    int endx = rows - 1 -start;
    for (int i=start; i <= endy; i++) {
        cout << number[start][i] << " ";
    }

    if (start < endx) {
        for (int i=start+1;i<=endx;i++) {
            cout << number[i][endy];
        }
    }
    if (start < endx && start < endy) {
        for (int i=endy-1; i>=start;i--) {
            cout << number[endx][i];
        }
    }
    if (start < endy && endx - start > 1) {
        for (int i=endx-1;i>=start;i--) {
            cout << number[i][start] << " ";
        }
    }
}


void Problem29() {



}