// Util.h
// Created by 张宇轩 on 2022/2/27.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
using namespace std;
#ifndef CHAPTER3_UTIL_H
#define CHAPTER3_UTIL_H


// 链表相关数据结构
struct ListNode {
    int m_value;
    ListNode *m_next;

    ListNode(int v) : m_value(v), m_next(nullptr) {}
};

ListNode *CreateListNode(int v);

void ConnectListNodes(ListNode *n1, ListNode *n2);

void DestroyList(ListNode *head);

void print_list(ListNode *head);


// 二叉树相关数据结构
struct BinaryTreeNode {
    double m_value;
    BinaryTreeNode* m_left;
    BinaryTreeNode* m_right;
};

BinaryTreeNode* CreateBinaryTreeNode(double dbValue);

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);

void DestroyTree(BinaryTreeNode* pRoot);





#endif //CHAPTER3_UTIL_H
