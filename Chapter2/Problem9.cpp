// Problem9.cpp
// Created by 张宇轩 on 2022/2/14.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
//
using namespace std;
#include <stack>
#include <iostream>
#include <queue>

// 用两个栈实现队列
template <typename T>
class CQueue {
public:
    CQueue() {}
    ~CQueue() {}

    void append_tail(const T& node);
    T delete_head();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
void CQueue<T>::append_tail(const T &node) {
    stack1.push(node);
}

template <typename T>
T CQueue<T>::delete_head() {

    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    if (stack2.empty()) {
        throw string("Error");
    }
    T res = stack2.top();
    stack2.pop();
    return res;
}


// 用两个队列来实现栈
template <typename T>
class CStack {
public:
    CStack() {}
    ~CStack() {}

    void push(const T& n);
    T pop();

private:
    queue<T> q1;
    queue<T> q2;

};

template <typename T>
void CStack<T>::push(const T &n) {
    if (!q1.empty()) {
        q1.push(n);
    } else {
        q2.push(n);
    }
}

template <typename T>
T CStack<T>::pop() {
    if (q1.empty() && q2.empty()) {
        throw string("all empty");
    }
    if (q1.size() > 0 && q2.size() > 2) {
        throw ("all not empty");
    }
    T res;
    if (!q1.empty()) {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        res = q1.front();
        q1.pop();
    } else {
        while (q2.size() > 1) {
            q1.push(q2.front());
            q2.pop();
        }
        res = q2.front();
        q2.pop();
    }

    return res;
}



void Problem9() {
//    CQueue<int> q;
//    q.append_tail(1);
//    q.append_tail(2);
//    q.append_tail(3);
//    try {
//        std::cout << q.delete_head() << std::endl;
//        std::cout << q.delete_head() << std::endl;
//        std::cout << q.delete_head() << std::endl;
//        std::cout << q.delete_head() << std::endl;
//    } catch (string s) {
//        std::cout << s << std::endl;
//
//    }


    CStack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    try {
        std::cout << s.pop() << std::endl;
        std::cout << s.pop() << std::endl;
        std::cout << s.pop() << std::endl;
        std::cout << s.pop() << std::endl;
    } catch (string s) {
        std::cout << s << std::endl;

    }





}