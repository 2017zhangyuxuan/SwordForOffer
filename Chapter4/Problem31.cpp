// Problem31.cpp
// Created by 张宇轩 on 2022/3/1.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
using namespace std;
/**
 * @brief 31、栈的压入、弹出序列
 * 输入两个证书序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等
 */

// 测试用例：正例 和 负例

#include <stack>
#include <unordered_map>
bool is_match(int* push, int* pop, int len) {
    if (push == nullptr || pop == nullptr || len <=0)
        return false;

    stack<int> push_stack;
    stack<int> pop_stack;
    int index = 0;
    for (int i=0; i< len; i++) {
        if (push_stack.empty() || push_stack.top() != pop[i]) {
            while (index < len && push[index] != pop[i]) {
                push_stack.push(push[index]);
                index++;
            }
            index++;
            if (index > len)
                return false;
        } else {
//            if (!push_stack.empty())
                push_stack.pop();
        }
    }
    return true;

}

// 假设前提：push 和 pop 里的元素是一样的
bool is_match2(int* push, int* pop, int len) {
    if (push == nullptr || pop == nullptr || len <= 0)
        return false;

    // key是push数组中的数字， value为 对应的下标
    unordered_map<int, int> map;
    for (int i=0;i<len;i++) {
        map[push[i]] = i;
    }
    for (int i=0; i< len; i++) {
        int index = map[pop[i]];
        int min = INT32_MAX;
        for (int j=i+1; j< len; j++) {
            if (map[pop[j]] < index) {
                if (min > map[pop[j]]) {
                    min = map[pop[j]];
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

void Problem31() {
    int push[] = {1,2,3,4,5};
    int pop1[] = {4,5,3,2,1};
    int pop2[] = {1,2,3,4,6};
    cout << boolalpha << is_match2(push, pop1,5) << endl;
    cout << boolalpha << is_match(push, pop2,5) << endl;


}