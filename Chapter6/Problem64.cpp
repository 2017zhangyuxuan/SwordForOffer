// Problem64.cpp
// Created by 张宇轩 on 2022/3/18.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

/**
 * @brief 64、 求 1+2+3+...+n
 * 求1+2+3...+n，要求不能使用乘除法，for、while、if、else、switch、case等关键字及条件判断语句（A?B:C)
 */


class Temp {
public:
    Temp() {
        n++;
        sum += n;
    }

    static int n;
    static int sum;
};

int Temp::n = 0;
int Temp::sum = 0;

// 利用构造函数
int get_sum_n_ctor(int n) {
    Temp* tmp = new Temp[n];
    int sum = Temp::sum;
    delete[] tmp;
    return sum;
}

// 利用虚函数
class A{
public:
    virtual int get_sum(int) {
        return 0;
    }
};
A* arr[2];

class B : public A{
public:
    virtual int get_sum(int n) {
        return arr[!!n]->get_sum(n-1) + n;
    }
};
int get_sum_n_virtual(int n) {
    A a;
    B b;
    arr[0] =&a;
    arr[1] = &b;
    return arr[1]->get_sum(n);
}

// 利用函数指针求解
int (*func[2])(int);

int ctrl_fun(int) {
    return 0;
}

int compute_func(int n) {
    return func[!!n](n-1) + n;
}

int get_sum_n_funcptr(int n) {
    func[0] = ctrl_fun;
    func[1] = compute_func;
    return compute_func(n);
}

template<int n>
struct KK {
    enum Value {
        N = KK<n-1>::N + n
    };
};
template<>
struct KK<1>{
    enum Value {
        N = 1
    };
};


void Problem64() {
    std::cout << get_sum_n_ctor(10) << std::endl;
    std::cout << get_sum_n_funcptr(10) << std::endl;
    std::cout << get_sum_n_virtual(10) << std::endl;

    std::cout << KK<10>::N << std::endl;


}