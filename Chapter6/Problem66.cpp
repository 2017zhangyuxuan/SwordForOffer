// Problem66.cpp
// Created by 张宇轩 on 2022/3/18.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief 66、构建乘积数组
 * 给定一个数组A[0,1,..,n-1]，请构建一个数组B[0,1,...,n-1]，其中B中的元素
 * B[i] = A[0]×A[1]×...×A[i-1]×A[i+1]×...×A[n-1]。不能使用除法
 */


vector<int> get_multiply_matrix(vector<int>& A) {
    vector<int> B;
    int size = A.size();
    if (size <=1) {
        return B;
    }
    int forward[size];
    int backward[size];
    forward[0] = A[0];
    backward[size-1] = A[size-1];
    for (int i=1;i<size;i++) {
        forward[i] = forward[i-1] * A[i];
        backward[size-1 -i] = backward[size-i] * A[size-1-i];
    }
    B.resize(size);
    B[0] = backward[1];
    B[size-1] = forward[size-2];
    for (int i=1;i<size-1;i++) {
        B[i] = forward[i-1] * backward[i+1];
    }
    return B;

}

void Problem66() {
    vector<int> arr{1,2,3,4,5};
    vector<int> res = get_multiply_matrix(arr);
    for (int i : res) {
        cout<< i << endl;
    }
    int a = atoi("a123");
    if (errno != 0) {
        cout <<"error" << a ;
    }
    cout << a;
}