// Problem33.cpp
// Created by 张宇轩 on 2022/3/2.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
using namespace  std;
/**
 * @brief 33、二叉搜索树的后序遍历序列
 * 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果
 */

// 测试用例：一个节点；空节点；全是左节点；全是右节点；错误的，正确的

bool is_sequence_of_BST(int sequence[], int start, int end) {
    if (sequence == nullptr || end - start <  0)
        return false;
    if (end - start == 0)
        return true;
    int root_value = sequence[end];
    int less = -1, greater = -1;
    for (int i=start; i< end; i++) {
        if (sequence[i] < root_value) {
            less = i;
            break;
        }
    }
    for (int i=start; i< end; i++) {
        if (sequence[i] > root_value) {
            greater = i;
            break;
        }
    }
    bool res;
    // 如果只有一棵子树
    if (less == -1 || greater == -1) {
        res = is_sequence_of_BST(sequence,start, end-1);
    } else if (greater < less) {
        res = false;
    } else {
        res = is_sequence_of_BST(sequence, start, greater-1) &&
                is_sequence_of_BST(sequence, greater, end-1);
    }
    return res;

}

bool is_sequence_of_BST2(int sequence[], int length) {
    if (sequence == nullptr || length == 0)
        return false;
    if (length == 1)
        return true;
    int greater = 0;
    for(; greater < length-1;greater++) {
        if (sequence[greater] > sequence[length-1]) {
            break;
        }
    }
    for (int i = greater; i < length-1; i++) {
        if (sequence[i] < sequence[length-1])
            return false;
    }
    bool left = true;
    if (greater > 0) {
        left = is_sequence_of_BST2(sequence, greater);
    }
    bool right = true;
    if (greater < length-1) {
        right = is_sequence_of_BST2(sequence+greater, length-greater-1);
    }
    return left && right;
}

#include <vector>
void Problem33() {
    int test1[] = {1};
    int test2[] = {1,2,3,4};
    int test3[] = {4,3,2,1};
    int test4[] = {5,7,6,9,11,10,8};
    int test5[] = {7,4,6,5};
    cout << boolalpha << is_sequence_of_BST(test1,0,0) << endl;
    cout << boolalpha << is_sequence_of_BST(test2,0,3) << endl;
    cout << boolalpha << is_sequence_of_BST(test3,0,3) << endl;
    cout << boolalpha << is_sequence_of_BST(test4,0,6) << endl;
    cout << boolalpha << is_sequence_of_BST(test5,0,3) << endl;

    cout << boolalpha << is_sequence_of_BST2(test1,1) << endl;
    cout << boolalpha << is_sequence_of_BST2(test2,4) << endl;
    cout << boolalpha << is_sequence_of_BST2(test3,4) << endl;
    cout << boolalpha << is_sequence_of_BST2(test4,7) << endl;
    cout << boolalpha << is_sequence_of_BST2(test5,4) << endl;

    cout << sizeof(vector<string>) << endl;

}