// Problem32.cpp
// Created by 张宇轩 on 2022/3/2.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include "Util.h"
/**
 * @brief 32、从上到下打印二叉树
 * 题目一：不分行从上到下打印二叉树，从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印
 * 题目二：分行从上到下打印二叉树
 * 题目三：之字形打印二叉树，即第一行从左到右打印，第二行从右到左打印，第三次再从左到右
 */


// 测试用例：空树；只有一个节点；完全二叉树；满二叉树

#include <queue>
void print_tree(BinaryTreeNode* root) {
    if (root == nullptr)
        return ;
    queue<BinaryTreeNode*> q;
    q.push(root);
    BinaryTreeNode* cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        cout << cur->m_value << " ";
        if (cur->m_left)
            q.push(cur->m_left);
        if (cur->m_right)
            q.push(cur->m_right);
    }
    cout << endl;
}

// 分行打印
void print_tree2(BinaryTreeNode* root) {
    if (root == nullptr)
        return ;
    queue<BinaryTreeNode*> q;
    q.push(root);
    BinaryTreeNode* cur;
    while (!q.empty()) {
        int size = q.size();
        while (size-- > 0) {
            cur = q.front();
            q.pop();
            cout << cur->m_value << " ";
            if (cur->m_left)
                q.push(cur->m_left);
            if (cur->m_right)
                q.push(cur->m_right);
        }
        cout << endl;
    }
}

// 之字形打印二叉树
#include <stack>
void print_tree3(BinaryTreeNode* root) {
    if (root == nullptr)
        return ;
    queue<BinaryTreeNode*> q;
    q.push(root);
    BinaryTreeNode* cur;
    bool reverse = false;
    stack<int> print_stack;
    queue<int> print_queue;
    while (!q.empty()) {
        int size = q.size();
        while (size-- > 0) {
            cur = q.front();
            q.pop();
            if (reverse) {
                print_stack.push(cur->m_value);
            } else {
                print_queue.push(cur->m_value);
            }

            if (cur->m_left)
                q.push(cur->m_left);
            if (cur->m_right)
                q.push(cur->m_right);
        }
        if (reverse) {
            while (!print_stack.empty()) {
                cout << print_stack.top() << " ";
                print_stack.pop();
            }
        } else {
            while (!print_queue.empty()) {
                cout << print_queue.front() << " ";
                print_queue.pop();
            }
        }
        reverse = !reverse;
        cout << endl;
    }
}

void Problem32() {
    printf("=====Test1 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    print_tree(pNode8);
    print_tree2(pNode8);
    print_tree3(pNode8);

    DestroyTree(pNode8);

    printf("=====Test2 starts:=====\n");
    BinaryTreeNode* pNode18 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode17 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode15 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode18, pNode17, nullptr);
    ConnectTreeNodes(pNode17, pNode16, nullptr);
    ConnectTreeNodes(pNode16, pNode15, nullptr);
    ConnectTreeNodes(pNode15, pNode14, nullptr);

    print_tree(pNode18);
    print_tree2(pNode18);
    print_tree3(pNode18);
    DestroyTree(pNode18);
}