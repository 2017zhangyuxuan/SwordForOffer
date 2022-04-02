// Problem18.cpp
// Created by 张宇轩 on 2022/2/25.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

/**
 * @brief 18、删除链表的节点
 * 给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内删除该节点
 */

#include "Util.h"

// 测试，删除节点在头部、尾部、中间，为空
// 注意：因为头指针可能也要被删除，所需要修改函数外部头指针的值，所以传入的参数应该是指针的指针

void delete_node(ListNode** header, ListNode* del_node) {
    if (header == nullptr || *header == nullptr || del_node == nullptr)
        return;
    // 如果要删除的就是头结点
    if (*header == del_node) {
        *header = (*header)->m_next;
        delete del_node;
    } else if (del_node->m_next != nullptr) {
        ListNode* next = del_node->m_next;
        del_node->m_value = next->m_value;
        del_node->m_next = next->m_next;
        delete next;
        next = nullptr;
    } else {
        ListNode* pre = *header;
        while(pre->m_next != del_node) {
            pre = pre->m_next;
        }
        pre->m_next = nullptr;
        delete del_node;
        del_node = nullptr;
    }

}

// 删除重复节点，不保留重复节点
// 比如1->2->3->3->4->4->5 ，变成 1->2->5
void delete_duplicate_nodes(ListNode** header) {
    if (header == nullptr || *header == nullptr)
        return;

    ListNode* pre = nullptr;
    ListNode* cur = *header;
    ListNode* next = cur->m_next;
    while (cur != nullptr && next != nullptr) {
        if (cur->m_value == next->m_value) {
            while (next != nullptr && cur->m_value == next->m_value) {
                delete cur;
                cur = next;
                next = next->m_next;
            }
            delete cur;
            if (pre == nullptr) {
                *header = next;
            } else {
                pre->m_next = next;
            }
            cur = next;
            if (cur != nullptr)
                next = cur->m_next;
        } else {
            pre = cur;
            cur = next;
            if (cur != nullptr)
                next = cur->m_next;
        }
    }
}

void Problem18() {
    ListNode* header = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(6);
    ListNode* node6 = new ListNode(7);
    header->m_next = node1;
    node1->m_next = node2;
    node2->m_next = node3;
    node3->m_next = node4;
    node4->m_next = node5;
    node5->m_next = node6;
    print_list(header);
//    delete_duplicate_nodes(&header);
//    print_lists(header);
    delete_node(&header, header);
    print_list(header);

}

