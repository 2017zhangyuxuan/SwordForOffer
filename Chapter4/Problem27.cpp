// Problem27.cpp
// Created by 张宇轩 on 2022/2/28.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include "Util.h"

/**
 * @brief 27、二叉树的镜像
 * 请完成一个函数，输入一棵二叉树，该函数输出它的镜像
 */

// 测试用例：空树；正常的有左右子树；只有左子树或右子树；只有一个根节点
void mirror_tree(BinaryTreeNode* root) {
    if (root == nullptr)
       return ;
    BinaryTreeNode* left = root->m_left;
    BinaryTreeNode* right = root->m_right;
    root->m_left = right;
    root->m_right = left;
    mirror_tree(left);
    mirror_tree(right);
}
#include <queue>
void mirror_tree_iteration(BinaryTreeNode* root) {
    if (root == nullptr)
        return;
    queue<BinaryTreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode* node = q.front();
        q.pop();
        BinaryTreeNode* left = node->m_left;
        BinaryTreeNode* right = node->m_right;
        node->m_left = right;
        node->m_right = left;
        if (left) 
            q.push(left);
        if (right)
            q.push(right);
    }
}


void Test1()
{
    printf("=====Test1 starts:=====\n");
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

    PrintTree(pNode8);

    printf("=====Test1: mirror_tree=====\n");
    mirror_tree(pNode8);
    PrintTree(pNode8);

    printf("=====Test1: mirror_tree_iteration=====\n");
    mirror_tree_iteration(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个左子结点
//            8
//          7
//        6
//      5
//    4
void Test2()
{
    printf("=====Test2 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, pNode7, nullptr);
    ConnectTreeNodes(pNode7, pNode6, nullptr);
    ConnectTreeNodes(pNode6, pNode5, nullptr);
    ConnectTreeNodes(pNode5, pNode4, nullptr);

    PrintTree(pNode8);

    printf("=====Test2: mirror_tree=====\n");
    mirror_tree(pNode8);
    PrintTree(pNode8);

    printf("=====Test2: mirror_tree_iteration=====\n");
    mirror_tree_iteration(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个右子结点
//            8
//             7
//              6
//               5
//                4
void Test3()
{
    printf("=====Test3 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, nullptr, pNode7);
    ConnectTreeNodes(pNode7, nullptr, pNode6);
    ConnectTreeNodes(pNode6, nullptr, pNode5);
    ConnectTreeNodes(pNode5, nullptr, pNode4);

    PrintTree(pNode8);

    printf("=====Test3: mirror_tree=====\n");
    mirror_tree(pNode8);
    PrintTree(pNode8);

    printf("=====Test3: mirror_tree_iteration=====\n");
    mirror_tree_iteration(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// 测试空二叉树：根结点为空指针
void Test4()
{
    printf("=====Test4 starts:=====\n");
    BinaryTreeNode* pNode = nullptr;

    PrintTree(pNode);

    printf("=====Test4: mirror_tree=====\n");
    mirror_tree(pNode);
    PrintTree(pNode);

    printf("=====Test4: mirror_tree_iteration=====\n");
    mirror_tree_iteration(pNode);
    PrintTree(pNode);
}

// 测试只有一个结点的二叉树
void Test5()
{
    printf("=====Test5 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

    PrintTree(pNode8);

    printf("=====Test5: mirror_tree=====\n");
    mirror_tree(pNode8);
    PrintTree(pNode8);

    printf("=====Test5: mirror_tree_iteration=====\n");
    mirror_tree_iteration(pNode8);
    PrintTree(pNode8);
}
void Problem27() {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
}