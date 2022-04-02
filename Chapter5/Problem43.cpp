// Problem43.cpp
// Created by 张宇轩 on 2022/3/6.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

using namespace std;
/**
 * @brief 43、1 ~ n 整数中 1 出现的次数
 * 输入一个整数n，求 1 ~ n 这n个整数的十进制表示中 1 出现的次数。
 * 例如，输入12，1~12这些整数包含1的数字有 1、10、11和12，一共出现5次1
 */


// 原本书上的解法感觉不太好理解
// 可以参考：https://www.cnblogs.com/wangkundentisy/p/8946858.html
// https://blog.csdn.net/xiao_count/article/details/106742561

int get_one_times(int num) {
    if (num < 1)
        return 0;
    int digit = 1;      // digit 表示当前位数（个位、十位。。）
    int sum = 0;
    int high = num / 10,low = 0,cur = num % 10;   // high 表示高位数字，low表示低位数字，cur表示当前位数字
    while (high != 0 || cur != 0) {
        if (cur < 1) {
            sum += high * digit;
        } else if (cur == 1) {
            sum += (high * digit + low + 1);
        } else {
            sum += (high + 1) * digit;
        }

        low = cur * digit + low;
        cur = high % 10;
        high /= 10;
        digit *= 10;
    }
    return sum;
}

void Problem43() {
    cout << get_one_times(1000) << endl;
}
