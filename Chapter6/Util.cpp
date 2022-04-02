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

void PrintTreeNode(const BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->m_value);

        if(pNode->m_left != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_left->m_value);
        else
            printf("left child is nullptr.\n");

        if(pNode->m_right != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_right->m_value);
        else
            printf("right child is nullptr.\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}

void PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->m_left != nullptr)
            PrintTree(pRoot->m_left);

        if(pRoot->m_right != nullptr)
            PrintTree(pRoot->m_right);
    }
}


ComplexListNode* CreateNode(int nValue)
{
    ComplexListNode* pNode = new ComplexListNode();

    pNode->m_nValue = nValue;
    pNode->m_pNext = nullptr;
    pNode->m_pSibling = nullptr;

    return pNode;
}

void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    if(pNode != nullptr)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}

void PrintList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("The value of this node is: %d.\n", pNode->m_nValue);

        if(pNode->m_pSibling != nullptr)
            printf("The value of its sibling is: %d.\n", pNode->m_pSibling->m_nValue);
        else
            printf("This node does not have a sibling.\n");

        printf("\n");

        pNode = pNode->m_pNext;
    }
}
