// Problem54.cpp
// Created by 张宇轩 on 2022/3/13.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include "Util.h"

using namespace std;
/**
 * @brief 54、二叉搜索树的第k大节点
 * 给定一棵二叉搜索树，请找出其中第k大的节点。
 */

// 测试用例： 节点数量等于k，小于k，大于k； k=1


#include <stack>
BinaryTreeNode* get_k_node(const BinaryTreeNode* root, int k) {
    if (root == nullptr)
        return nullptr;
    stack<BinaryTreeNode*> s;
    BinaryTreeNode* cur = const_cast<BinaryTreeNode*>(root);
    int num = 0;
    while (cur!= nullptr || !s.empty()) {
        while (cur!= nullptr) {
            s.push(cur);
            cur = cur->m_left;
        }
        cur = s.top();
        s.pop();
        num++;
        if (num == k) {
            return cur;
        }
        cur = cur->m_right;
    }
    return nullptr;
}

// ====================测试代码====================
void Test(const char* testName, const BinaryTreeNode* pRoot, unsigned int k, bool isNull, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    const BinaryTreeNode* pTarget = get_k_node(pRoot, k);
    if((isNull && pTarget == nullptr) || (!isNull && pTarget->m_value == expected))
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void TestA()
{
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

    Test("TestA0", pNode8, 0, true, -1);
    Test("TestA1", pNode8, 1, false, 5);
    Test("TestA2", pNode8, 2, false, 6);
    Test("TestA3", pNode8, 3, false, 7);
    Test("TestA4", pNode8, 4, false, 8);
    Test("TestA5", pNode8, 5, false, 9);
    Test("TestA6", pNode8, 6, false, 10);
    Test("TestA7", pNode8, 7, false, 11);
    Test("TestA8", pNode8, 8, true, -1);

    DestroyTree(pNode8);

    printf("\n\n");
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
void TestB()
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

    Test("TestB0", pNode5, 0, true, -1);
    Test("TestB1", pNode5, 1, false, 1);
    Test("TestB2", pNode5, 2, false, 2);
    Test("TestB3", pNode5, 3, false, 3);
    Test("TestB4", pNode5, 4, false, 4);
    Test("TestB5", pNode5, 5, false, 5);
    Test("TestB6", pNode5, 6, true, -1);

    DestroyTree(pNode5);

    printf("\n\n");
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
void TestC()
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

    Test("TestC0", pNode1, 0, true, -1);
    Test("TestC1", pNode1, 1, false, 1);
    Test("TestC2", pNode1, 2, false, 2);
    Test("TestC3", pNode1, 3, false, 3);
    Test("TestC4", pNode1, 4, false, 4);
    Test("TestC5", pNode1, 5, false, 5);
    Test("TestC6", pNode1, 6, true, -1);

    DestroyTree(pNode1);

    printf("\n\n");
}

// There is only one node in a tree
void TestD()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    Test("TestD0", pNode1, 0, true, -1);
    Test("TestD1", pNode1, 1, false, 1);
    Test("TestD2", pNode1, 2, true, -1);

    DestroyTree(pNode1);

    printf("\n\n");
}

// empty tree
void TestE()
{
    Test("TestE0", nullptr, 0, true, -1);
    Test("TestE1", nullptr, 1, true, -1);

    printf("\n\n");
}


void Problem54() {
    TestA();
    TestB();
    TestC();
    TestD();
    TestE();
}