// Problem14.cpp
// Created by 张宇轩 on 2022/2/22.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
//
#include <iostream>


/**
 * @brief 14、剪绳子
 * 给你一根长度为n的绳子，请把绳子剪成m段（m、n都是整数，n>1并且m>1），每段绳子的长度记为
 * k[0],k[1],...,k[m]。请问k[0] * k[1] *... * k[m] 可能的最大乘积是多少？
 */

int get_max_product(int length) {
    if (length<= 1)
        return 0;
    if (length == 2)
        return 1;
    if (length == 3) {
        return 2;
    }

    int product[length+1];
    product[0] = 0;
    product[1] = 1;
    product[2] = 2;
    product[3] = 3;
    for (int i = 4; i <= length; i++) {
        int max = 0;
        for (int j=1; j<=i/2;j++) {
            if (max < product[j] * product[i-j]){
                max = product[j] * product[i-j];
            }
        }
        product[i] = max;
    }
    return product[length];
}

int get_max_product2(int length) {
    if (length<= 1)
        return 0;
    if (length == 2)
        return 1;
    if (length == 3) {
        return 2;
    }
    int m = length / 3;
    int n = length % 3;

    int res = 1;
    while (m > 0) {
        res *= 3;
        m--;
    }
    if (n == 1) {
        res = res / 3 * 4;
    } else if (n == 2) {
        res *= n;
    }
    return res;
}

void Problem14() {
    std::cout << get_max_product(4) << std::endl;
    std::cout << get_max_product2(4) << std::endl;

}
