// Problem34.cpp
// Created by 张宇轩 on 2022/3/3.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include "Util.h"
#include <sstream>
using namespace std;
/**
 * @brief 34、二叉树中和为某一值的路径
 * 输入一棵二叉树和一个整数，打印出二叉树中节点值的和作为输入整数的所有路径。
 * 从树的根节点开始往下一直到叶节点所经过的节点形成一条路径
 */

void DFS_print(BinaryTreeNode* root, int sum, string path) {
    if (root == nullptr)
        return ;
    path += to_string(root->m_value) + " ";
    if (root->m_value == sum && root->m_left == nullptr && root->m_right == nullptr) {
        cout << path << endl;
    }
    if (root->m_left) {
        DFS_print(root->m_left, sum - root->m_value, path);
    }
    if (root->m_right) {
        DFS_print(root->m_right, sum-root->m_value, path);
    }
}

void print_sum_path(BinaryTreeNode* root, int sum) {
    if (root == nullptr)
        return;
    string res = "";
    DFS_print(root, sum, res);

}

void Problem34() {
    printf("=====Test1 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(3);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    print_sum_path(pNode8,21);

    DestroyTree(pNode8);

    printf("=====Test2 starts:=====\n");
    BinaryTreeNode* pNode18 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode17 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode15 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode18, pNode17, nullptr);
    ConnectTreeNodes(pNode17, pNode16, nullptr);
    ConnectTreeNodes(pNode16, pNode15, nullptr);
    ConnectTreeNodes(pNode15, pNode14, nullptr);

    print_sum_path(pNode18, 21);
    DestroyTree(pNode18);
}