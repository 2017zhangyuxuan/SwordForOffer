// Problem30.cpp
// Created by 张宇轩 on 2022/3/1.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
using namespace std;
/**
 * @brief 30、包含min函数的栈
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数。
 * 在该栈中，调用min、push 及 pop 的时间复杂度都是 O（1）
 */

#include <stack>
template<class T>
class MinStack {
public:

    T min() {
        return s_min.top();
    }

    T& top() {
        return s.top();
    }
    void push(T t) {
        s.push(t);
        if (s_min.empty() || s_min.top() > t)
            s_min.push(t);
        else {
            s_min.push(s_min.top());
        }
    }
    void pop() {
        s.pop();
        s_min.pop();
    }
private:
    stack<T> s;
    stack<T> s_min;
};

void Problem30() {
    stack<int> min;
    min.pop();
}