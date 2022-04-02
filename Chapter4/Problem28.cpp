// Problem28.cpp
// Created by 张宇轩 on 2022/2/28.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>


/**
 * @brief 28、对称的二叉树
 * 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
 */
#include "Util.h"

bool recurse_order(BinaryTreeNode* root1, BinaryTreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr)
        return false;
    if (root1->m_value  == root2->m_value) {
        return recurse_order(root1->m_left,root2->m_right) &&
                recurse_order(root1->m_right,root2->m_left);

    }
    return false;
}

void is_symmetry(BinaryTreeNode* root) {
    recurse_order(root,root);
}
void Problem28() {

}