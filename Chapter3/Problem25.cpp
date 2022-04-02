// Problem25.cpp
// Created by 张宇轩 on 2022/2/27.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
/**
 * @brief 25、合并两个排序的链表
 * 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的
 */

#include "Util.h"

// 测试用例：一个为空，一个不为空；两个都为空；两个都不为空
// 还要询问是否能够修改链表，还是新建一条链表

ListNode* merge_sorted_lists(ListNode* head1, ListNode* head2) {
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;
    ListNode* root = nullptr, * cur = nullptr;
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->m_value < head2->m_value) {
            if (root == nullptr) {
                root = head1;
                cur = root;
            }
            else {
                cur->m_next = head1;
                cur = head1;
            }
            head1 = head1->m_next;
        } else {
            if (root == nullptr) {
                root = head2;
                cur = root;
            }
            else {
                cur->m_next = head2;
                cur = head2;
            }
            head2 = head2->m_next;
        }
    }
    while (head1 != nullptr) {
        cur->m_next = head1;
        cur = head1;
        head1 = head1->m_next;
    }
    while (head2 != nullptr) {
        cur->m_next = head2;
        cur = head2;
        head2 = head2->m_next;
    }


    return root;


}

void Problem25() {
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(3);
    ListNode *pNode3 = CreateListNode(5);
    ListNode *pNode4 = CreateListNode(2);
    ListNode *pNode5 = CreateListNode(4);
    ListNode *pNode6 = CreateListNode(6);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
//    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ListNode* root = merge_sorted_lists(pNode1, pNode4);
    print_list(root);
}
