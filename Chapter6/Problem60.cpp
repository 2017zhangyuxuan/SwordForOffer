// Problem60.cpp
// Created by 张宇轩 on 2022/3/15.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include <math.h>

using namespace std;
/**
 * @brief 60、n个骰子的点数
 * 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值的出现概率
 */

#define MAX_NUM 6


void print_probability(int n) {
    const int max_num = n * MAX_NUM;
    int probability[2][max_num+1];
    for (int i=0; i<= max_num; i++) {
        probability[0][i] = 0;
        probability[1][i] = 0;
    }
    int flag = 0;
    for (int i=1;i<=MAX_NUM;i++) {
        probability[flag][i] = 1;
    }
    for (int i=2; i<=n;i++) {
        for (int j=0; j <= (i * MAX_NUM) ; j++) {
            probability[1-flag][j] = 0;
        }
        for (int j = i; j <= i * MAX_NUM; j++) {
            for (int k =1 ; j >=k && k<=MAX_NUM;k++) {
                probability[1-flag][j] += probability[flag][j-k];
            }
        }

        flag = 1 - flag;
    }
    double total = pow(MAX_NUM, n);
    for (int i = n; i <= max_num;i++) {
        cout << i << " : " << probability[flag][i] / total << endl;
    }
}

void Problem60() {
    print_probability(2);
}
//0.0277778 0.0555556 0.0833333 0.111111 0.138889 0.166667 0.138889 0.111111 0.0833333 0.0555556 0.0277778