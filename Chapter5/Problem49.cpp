// Problem49.cpp
// Created by 张宇轩 on 2022/3/9.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include <vector>
#include <set>

using namespace std;

/**
 * @brief 49、丑数
 * 我们把只包含因子2、3和5的数称作丑数。求从小到大的顺序的第1500个丑数。
 * 例如6、8都是丑数，但14不是，因为它包含因子7.习惯上我们把1当做第一个丑数。
 */


int min(int num1,int num2, int num3) {
    int tmp = num1 > num2 ? num2 : num1;
    return tmp > num3 ? num3 : tmp;
}

int get_ugly_num (int x) {
    if (x <= 0)
        return -1;
    int *arr = new int[x];
    arr[0] = 1;
    int next_ugly = 1;
    int p2=0,p3=0,p5=0;
    while (next_ugly < x) {
        arr[next_ugly] = min(arr[p2]*2, arr[p3] *3, arr[p5] * 5);
        while (arr[p2]*2 <= arr[next_ugly])
            p2++;
        while (arr[p3] * 3 <= arr[next_ugly])
            p3++;
        while (arr[p5]*5 <= arr[next_ugly])
            p5++;
        next_ugly++;
    }
    int res = arr[x-1];
    delete []arr;
    return res;
}

void Problem49() {
    cout << get_ugly_num(12) << endl;
}
