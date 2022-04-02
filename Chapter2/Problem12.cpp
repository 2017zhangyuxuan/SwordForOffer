// Problem12.cpp
// Created by 张宇轩 on 2022/2/21.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
//
#include<string>
#include <iostream>
using namespace std;
/**
 * 12.矩阵中的路径
 * 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，
 * 每一步可以再矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一个，那么该路径不能再次进入该格子
 * 矩阵形式如下：
 * a b t g
 * c f c s
 * j d e h
*/

int moves[4][2] = {
        1,0,
        0,1,
        -1,0,
        0,-1
};

void DFS(char*martix, int rows, int cols, char* str, int row, int col, int index, bool* mark, bool& res) {
    // 已经搜索得到结果
    if (res)
        return;
    // 遍历完字符串
    if (index == strlen(str)) {
        res = true;
        return ;
    }
    // 遍历上下左右四个位置
    for (int m = 0; m < 4; m++) {
        int next_row = row+moves[m][0];
        int next_col = col + moves[m][1];
        int idx = next_row * cols + next_col;
        if (next_row < 0 || next_row >= rows || next_col <0 || next_col >= cols)
            continue;
        if (mark[idx] == false)
            continue;
        if (martix[idx] == str[index]) {
            mark[idx] = false;
            DFS(martix, rows, cols,str, next_row, next_col, index+1,mark, res);
            mark[idx] = true;
        }
    }


}

bool has_path(char*martix, int rows, int cols, char *str) {
    if (martix == nullptr || rows <= 0 || cols <= 0 || str == nullptr) {
        return false;
    }
    bool mark[rows*cols];
    bool res = false;
    for (int i=0; i < rows; i++) {
        for (int j=0; j< cols; j++) {
            mark[i*cols + j] = true;
        }
    }
    for (int i=0; i< rows; i++) {
        for (int j=0; j< cols; j++) {
            DFS(martix,rows, cols,str, i,j,0,mark,res);
            if (res)
                return res;
        }
    }
    return false;

}

void Problem12() {
    char martix[] = {
        'a','b','t','g',
//        'c','f','c','s',
//        'j','d','e','h'
    };
    char martix2[] = {
        'a','a','a','a'
    };

    char str[] = "aaaa";
    std::cout << boolalpha << has_path(martix2,4,1,str)  << std::endl;

    return;
}