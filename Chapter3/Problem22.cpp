// Problem22.cpp
// Created by 张宇轩 on 2022/2/26.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include "Util.h"
/**
 * @brief 22、链表中倒数第k个节点
 * 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从 1 开始计数，
 * 即链表的尾结点是倒数第一个节点
 */

// 考虑节点数量小于 k 个怎么办
ListNode* find_last_k(ListNode* header, int k) {
    if (header == nullptr || k <= 0) {
        return nullptr;
    }
    ListNode* ahead = header;
    ListNode* behind = header;
    for (int i=0; i<k-1;i++) {
        ahead = ahead->m_next;
        // 表示链表的数量小于k个，则直接返回空指针
        if (ahead == nullptr)
            return nullptr;
    }
    while(ahead->m_next != nullptr) {
        ahead = ahead->m_next;
        behind = behind->m_next;
    }
    return behind;
}

void Problem22() {

}