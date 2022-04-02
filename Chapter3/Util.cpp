// Util.cpp
// Created by 张宇轩 on 2022/2/27.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include "Util.h"
using namespace std;
ListNode *CreateListNode(int v) {
    return new ListNode(v);
}

void ConnectListNodes(ListNode *n1, ListNode *n2) {
    n1->m_next = n2;
}

void DestroyList(ListNode *head) {
    if (head == nullptr)
        return;
    ListNode *next;
    while (head != nullptr) {
        next = head->m_next;
        delete head;
        head = next;
    }
}

void print_list(ListNode *head) {
    while (head != nullptr) {
        cout << head->m_value << " " ;
        head=head->m_next;
    }
    cout << endl;
}


BinaryTreeNode* CreateBinaryTreeNode(double dbValue)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_value = dbValue;
    pNode->m_left = nullptr;
    pNode->m_right = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_left = pLeft;
        pParent->m_right = pRight;
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_left;
        BinaryTreeNode* pRight = pRoot->m_right;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}