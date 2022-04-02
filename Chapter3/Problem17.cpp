// Problem17.cpp
// Created by 张宇轩 on 2022/2/23.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include <cstring>
/**
 * @brief 17、打印从1到最大的n位数
 * 输入数字n，按顺序打印出从1到最大的n位十进制数。比如输入3，则打印出1、2、3 一直到最大的3位数 999
 */

// 测试用例，n为负数，超过 int整型限制，考虑大整数的表示
void print_max_n_digits(char* numbers, int n, int index);
void print_number(char* numbers);

void print_max_n_digits(int n) {
    if (n<=0)
        return;
    char numbers[n+1];
    memset(numbers,'0',n);
    numbers[n] = '\0';
    for (int i=0;i<=9;i++) {
        numbers[0] = i + '0';
        print_max_n_digits(numbers, n, 1);
    }
}
void print_max_n_digits(char* numbers, int n, int index) {
    if (index == n) {
        print_number(numbers);
    } else {
        for (int i=0; i<=9; i++) {
            numbers[index] = i + '0';
            print_max_n_digits(numbers,n,index+1);
        }
    }
}


void print_number(char* numbers) {
    int length = strlen(numbers);
    int not_zero = -1;
    for (int i=0; i<length; i++) {
        if (numbers[i] == '0')
            continue;
        not_zero = i;
        break;
    }
    // 不打印全零
    if (not_zero != -1)
        std::cout << (numbers+not_zero) << std::endl;
}

void print_max_n_digits_with_array(int n) {
    if (n <= 0)
        return;
    char numbers[n+1];
    memset(numbers,'0',n);
    numbers[n] = '\0';
    bool is_overflow = false;
    // 没有溢出的时候一致累加并打印
    while (!is_overflow) {
        int take_over = 1;
        for (int i=n-1; i>=0; i--) {
            int sum = numbers[i] - '0' + take_over;
            if (sum >= 10) {
                // 最高位进1，终止
                if (i == 0) {
                    is_overflow = true;
                    break;
                } else {
                    numbers[i] = sum - 10 + '0';
                }
            } else {
                numbers[i] = sum + '0';
                break;
            }
        }
        if (!is_overflow) {
            print_number(numbers);
        }
    }
}





void Problem17() {
    print_max_n_digits_with_array(3);
}