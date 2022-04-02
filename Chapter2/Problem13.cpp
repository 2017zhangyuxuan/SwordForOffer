// Problem13.cpp
// Created by 张宇轩 on 2022/2/22.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
//

/**
 * 13.机器人的运动范围
 * 地上有一个m行n列的方格，一个机器人从坐标(0,0)的格子开始移动，他每次可以向左、右、上、下移动一格，
 * 但不能进入行坐标和列坐标的数位之和大于k的格子。请问该机器人能够到达多少格子
*/

extern int moves[4][2];

int get_sum(int num) {
    int res = 0;
    while (num > 0) {
        res += num % 10;
        num /= 10;
    }
    return res;
}

bool check(int threshold, int row, int col) {
    return threshold >= (get_sum(row) + get_sum(col));
}

int moving(int threshold, int rows, int cols, int row, int col, bool* mark) {
    int count = 1 ;
    for (int i=0;i<4;i++) {
        int next_row = row + moves[i][0];
        int next_col = col + moves[i][1];
        if (next_row < 0 || next_row >= rows || next_col < 0 || next_col >= cols)
            continue;
        if (mark[next_row * cols + next_col])
            continue;
        if (check(threshold, next_row, next_col)) {
            mark[next_row * cols + next_col] = true;
            count += moving(threshold,rows,cols,next_row,next_col,mark);
        }
    }
    return count;
}


int moving_count(int threshold, int rows, int cols) {
    if (threshold < 0 || rows <= 0 || cols <= 0)
        return 0;
    bool mark[rows * cols];
    for (int i=0; i<rows; i++) {
        for (int j = 0; j < cols; ++j) {
            mark[i*cols + j] = false;
        }
    }
    mark[0] = true;
    return moving(threshold,rows,cols,0,0, mark);
}

