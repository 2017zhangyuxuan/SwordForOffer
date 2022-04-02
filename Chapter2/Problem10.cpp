// Problem10.cpp
// Created by 张宇轩 on 2022/2/15.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
//

// 写一个函数，输入n，求斐波那契数列的第n项
// f(0) = 1, f(1) = 1,
// 当 n > 1 , f(n) = f(n-1) + f(n-2）

// 递归实现，包含大量重复计算，效率低
int Fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

// 迭代循环实现
int Fibonacci_loop(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int f1 = 0, f2 = 1;
    int res;
    for (int i=1; i<n; i++) {
        res = f1 + f2;
        f1 = f2;
        f2 = res;
    }
    return res;
}
