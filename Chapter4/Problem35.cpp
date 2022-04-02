// Problem35.cpp
// Created by 张宇轩 on 2022/3/3.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include "Util.h"
/**
 * @brief 35、复杂链表的复制
 * 请实现函数 ComplexListNode* Clone(ComplexListNode* pHead)，复制一个复杂链表。
 * 在复杂链表中，每个节点除了有一个m_pNext指针指向下一个节点，还有一个m_pSibling指针
 * 指向链表中的任意节点或者nullptr
 */

void copy_next(ComplexListNode* head) {
    if (head == nullptr)
        return;
    ComplexListNode* cur = head;
    while (cur != nullptr) {
        ComplexListNode* back = new ComplexListNode(cur->m_nValue);
        back->m_pNext = cur->m_pNext;
        cur->m_pNext = back;
        cur = back->m_pNext;
    }
}

void copy_sibling(ComplexListNode* head) {
    if (head == nullptr)
        return;
    ComplexListNode* cur = head;
    ComplexListNode* back;
    while (cur != nullptr) {
        back = cur->m_pNext;
        if (cur->m_pSibling != nullptr) {
            back->m_pSibling = cur->m_pSibling->m_pNext;
        }
        cur = back->m_pNext;
    }

}

ComplexListNode* detach_list(ComplexListNode* head) {
    if (head == nullptr)
        return nullptr;
    ComplexListNode* copy_head = head->m_pNext;
    ComplexListNode* cur = copy_head;
    while (head != nullptr) {
        head->m_pNext = cur->m_pNext;
        head = head->m_pNext;

        if (head == nullptr)
            break;
        cur->m_pNext = head->m_pNext;
        cur = cur->m_pNext;
    }
    return copy_head;
}

ComplexListNode* Clone(ComplexListNode* head) {
    if (head == nullptr)
        return nullptr;
    copy_next(head);
    copy_sibling(head);
    return detach_list(head);

}

namespace p35 {
    // ====================测试代码====================
    void Test(const char* testName, ComplexListNode* pHead)
    {
        if(testName != nullptr)
            printf("%s begins:\n", testName);

        printf("The original list is:\n");
        PrintList(pHead);

        ComplexListNode* pClonedHead = Clone(pHead);

        printf("The cloned list is:\n");
        PrintList(pClonedHead);
    }

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
    void Test1()
    {
        ComplexListNode* pNode1 = CreateNode(1);
        ComplexListNode* pNode2 = CreateNode(2);
        ComplexListNode* pNode3 = CreateNode(3);
        ComplexListNode* pNode4 = CreateNode(4);
        ComplexListNode* pNode5 = CreateNode(5);

        BuildNodes(pNode1, pNode2, pNode3);
        BuildNodes(pNode2, pNode3, pNode5);
        BuildNodes(pNode3, pNode4, nullptr);
        BuildNodes(pNode4, pNode5, pNode2);

        Test("Test1", pNode1);
    }

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
    void Test2()
    {
        ComplexListNode* pNode1 = CreateNode(1);
        ComplexListNode* pNode2 = CreateNode(2);
        ComplexListNode* pNode3 = CreateNode(3);
        ComplexListNode* pNode4 = CreateNode(4);
        ComplexListNode* pNode5 = CreateNode(5);

        BuildNodes(pNode1, pNode2, nullptr);
        BuildNodes(pNode2, pNode3, pNode5);
        BuildNodes(pNode3, pNode4, pNode3);
        BuildNodes(pNode4, pNode5, pNode2);

        Test("Test2", pNode1);
    }

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
    void Test3()
    {
        ComplexListNode* pNode1 = CreateNode(1);
        ComplexListNode* pNode2 = CreateNode(2);
        ComplexListNode* pNode3 = CreateNode(3);
        ComplexListNode* pNode4 = CreateNode(4);
        ComplexListNode* pNode5 = CreateNode(5);

        BuildNodes(pNode1, pNode2, nullptr);
        BuildNodes(pNode2, pNode3, pNode4);
        BuildNodes(pNode3, pNode4, nullptr);
        BuildNodes(pNode4, pNode5, pNode2);

        Test("Test3", pNode1);
    }

// 只有一个结点
    void Test4()
    {
        ComplexListNode* pNode1 = CreateNode(1);
        BuildNodes(pNode1, nullptr, pNode1);

        Test("Test4", pNode1);
    }

// 鲁棒性测试
    void Test5()
    {
        Test("Test5", nullptr);
    }
}


#include <queue>
#include <list>
void Problem35() {
//    p35::Test1();
//    p35::Test2();
//    p35::Test3();
//    p35::Test4();
//    p35::Test5();
    deque<int> d;
    queue<int> q;
    vector<int> v;
    list<int> l;
    queue<int,vector<int>> qq;
    qq.size();
    qq.push(10);

    cout << sizeof(d) << endl;
}