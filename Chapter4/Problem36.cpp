// Problem36.cpp
// Created by 张宇轩 on 2022/3/4.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include "Util.h"

/**
 * @brief 36、二叉搜索树与双向链表
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的节点，
 * 只能调整树中节点指针的指向。
 */


// 测试输入：空树；单个节点；只有左节点；只有右节点；正常的一棵树

void dfs_convert(BinaryTreeNode* cur, BinaryTreeNode** last) {
    if (cur == nullptr)
        return ;
    if (cur->m_left) {
        dfs_convert(cur->m_left, last);
    }
    cur->m_left = *last;
    if (*last != nullptr)
        (*last)->m_right = cur;
    *last = cur;

    if (cur->m_right) {
        dfs_convert(cur->m_right, last);
    }


}

BinaryTreeNode* convert(BinaryTreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    BinaryTreeNode* last = nullptr;
    dfs_convert(root, &last);
    BinaryTreeNode* head = last;
    while (head->m_left != nullptr) {
        head = head->m_left;
    }
    return head;

}
// ====================测试代码====================
void PrintDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;

    printf("The nodes from left to right are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_value);

        if(pNode->m_right == nullptr)
            break;
        pNode = pNode->m_right;
    }

    printf("\nThe nodes from right to left are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_value);

        if(pNode->m_left == nullptr)
            break;
        pNode = pNode->m_left;
    }

    printf("\n");
}

void DestroyList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;
    while(pNode != nullptr)
    {
        BinaryTreeNode* pNext = pNode->m_right;

        delete pNode;
        pNode = pNext;
    }
}

namespace p36 {
    void Test(char* testName, BinaryTreeNode* pRootOfTree)
    {
        if(testName != nullptr)
            printf("%s begins:\n", testName);

        PrintTree(pRootOfTree);

        BinaryTreeNode* pHeadOfList = convert(pRootOfTree);



        PrintDoubleLinkedList(pHeadOfList);
    }

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
    void Test1()
    {
        BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
        BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
        BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
        BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
        BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
        BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
        BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

        ConnectTreeNodes(pNode10, pNode6, pNode14);
        ConnectTreeNodes(pNode6, pNode4, pNode8);
        ConnectTreeNodes(pNode14, pNode12, pNode16);

        Test("Test1", pNode10);

        DestroyList(pNode4);
    }

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
    void Test2()
    {
        BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
        BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
        BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
        BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
        BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

        ConnectTreeNodes(pNode5, pNode4, nullptr);
        ConnectTreeNodes(pNode4, pNode3, nullptr);
        ConnectTreeNodes(pNode3, pNode2, nullptr);
        ConnectTreeNodes(pNode2, pNode1, nullptr);

        Test("Test2", pNode5);

        DestroyList(pNode1);
    }

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
    void Test3()
    {
        BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
        BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
        BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
        BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
        BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

        ConnectTreeNodes(pNode1, nullptr, pNode2);
        ConnectTreeNodes(pNode2, nullptr, pNode3);
        ConnectTreeNodes(pNode3, nullptr, pNode4);
        ConnectTreeNodes(pNode4, nullptr, pNode5);

        Test("Test3", pNode1);

        DestroyList(pNode1);
    }

// 树中只有1个结点
    void Test4()
    {
        BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
        Test("Test4", pNode1);

        DestroyList(pNode1);
    }

// 树中没有结点
    void Test5()
    {
        Test("Test5", nullptr);
    }

}

void Problem36() {
    p36::Test1();
    p36::Test2();
    p36::Test3();
    p36::Test4();
    p36::Test5();

}

