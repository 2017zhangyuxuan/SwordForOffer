// Problem24.cpp
// Created by 张宇轩 on 2022/2/26.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
using namespace std;
#include "Util.h"
/**
 * @brief 24、反转链表
 * 定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点
 */

// 测试用例：空指针，只有一个节点，多个节点

ListNode* reverse_list(ListNode* head) {
    if (head == nullptr || head->m_next == nullptr)
        return head;
    ListNode* next = head->m_next;
    ListNode* root = reverse_list(next);
    next->m_next = head;
    head->m_next = nullptr;
    return root;
}


void Problem24() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    print_list(pNode1);
    ListNode* root = reverse_list(pNode5);
    print_list(root);


}