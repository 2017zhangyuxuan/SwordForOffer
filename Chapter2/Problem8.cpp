// Problem8.cpp
// Created by 张宇轩 on 2022/2/14.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
//

#include "Structs.h"
/**
 * @brief 给定一棵二叉树和其中一个节点，找出中序遍历序列中该节点的下一个节点
 * @param node 二叉树中的一个节点
 * @return 中序遍历序列中的下一个节点
 */

struct BinaryTreeNode {
    int val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode *parent;
    BinaryTreeNode() : val(0), left(nullptr), right(nullptr) , parent(nullptr) {}
    *BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr), parent(nullptr) {}
    BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right,
                   BinaryTreeNode *parent) : val(x), left(left), right(right), parent(parent) {}
};

BinaryTreeNode* get_next(BinaryTreeNode* node) {
    if (node == nullptr)
        return nullptr;
    // 如果存在右节点
    if (node->right != nullptr) {
        BinaryTreeNode* res = node->right;
        while (res->left != nullptr) {
            res = res->left;
        }
        return res;
    } else {
        BinaryTreeNode* cur = node;
        BinaryTreeNode* parent = cur->parent;
        while (parent != nullptr && parent->right == cur) {
            cur = parent;
            parent = cur->parent;
        }
        return parent;
    }

}

void Problem8() {

}
