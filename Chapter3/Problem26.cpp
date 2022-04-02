// Problem26.cpp
// Created by 张宇轩 on 2022/2/27.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include "Util.h"
#include<math.h>
/**
 * @brief 26、树的子结构
 * 输入两棵二叉树A和B，判断B是不是A的子结构。
 */

// 测试用例：为空；是子结构；不是子结构

bool is_subtree_recursion(BinaryTreeNode *root, BinaryTreeNode *subtree) {
    if (subtree == nullptr)
        return true;
    if (root == nullptr)
        return false;
    bool flag = false;
    if (root->m_value == subtree->m_value) {
        flag = is_subtree_recursion(root->m_left, subtree->m_left)
               && is_subtree_recursion(root->m_right, subtree->m_right);

    }
    return flag;
}

#include<queue>
bool is_subtree(BinaryTreeNode* root, BinaryTreeNode* subtree) {
    if (subtree == nullptr)
        return true;
    if (root == nullptr)
        return false;
    queue<BinaryTreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode* cur = q.front();
        q.pop();
        bool flag = is_subtree_recursion(cur, subtree);
        if (flag)
            return true;
        if (cur->m_left != nullptr)
            q.push(cur->m_left);
        if (cur->m_right != nullptr)
            q.push(cur->m_right);
    }
    return false;
}

void Problem26() {
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

    bool flag =  is_subtree(pNodeA1, nullptr);
    cout << boolalpha << flag << endl;
//    Test("Test1", pNodeA1, pNodeB1, true);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);


}