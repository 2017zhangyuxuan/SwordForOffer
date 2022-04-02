// Problem68.cpp
// Created by 张宇轩 on 2022/3/20.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include "Util.h"
#include <stack>
#include <queue>

using namespace std;
/**
 * @brief 68、树中两个节点的最低公共祖先
 * 难度一：二叉搜索树
 * 难度二：不是二叉搜索树，节点带有指向父节点的指针
 * 难度三：就是一棵普通的树
 */

// 测试用例：链状树、空指针、异常情况：树中没有对应的节点


// TODO：使用list直接记录更好，不用栈来反序
bool get_node_path(BinaryTreeNode *root, BinaryTreeNode *node, stack<BinaryTreeNode *> &q) {
    if (root == nullptr || node == nullptr) {
        return false;
    }
    q.push(root);
    if (root == node) {
        return true;
    }
    bool flag1 = get_node_path(root->m_left, node, q);
    if (flag1)
        return true;
    bool flag2 = get_node_path(root->m_right, node, q);
    if (flag2)
        return true;
    q.pop();
    return false;
}

// 找到某节点的路径
ListTreeNode *get_node_path(BinaryTreeNode *root, BinaryTreeNode *node) {
    if (root == nullptr || node == nullptr) {
        return nullptr;
    }
    ListTreeNode *head = nullptr;
    ListTreeNode *cur = nullptr;
    stack<BinaryTreeNode *> s;
    bool flag = get_node_path(root, node, s);
    if (flag) {
        while (!s.empty()) {
            if (head == nullptr) {
                head = new ListTreeNode(s.top());
                s.pop();
                cur = head;
            } else {
                cur->next = new ListTreeNode(s.top());
                cur = cur->next;
                s.pop();
            }
        }
    } else {
        return nullptr;
    }
    return head;
}

// 两个链表的公共节点
ListTreeNode *get_common_node(ListTreeNode *node1, ListTreeNode *node2) {
    if (node1 == nullptr || node2 == nullptr) {
        return nullptr;
    }
    int count = 0;
    ListTreeNode* p1 = node1;
    ListTreeNode* p2 = node2;
    ListTreeNode* res= nullptr;
    while (true) {
        p1 = p1->next;
        p2 = p2->next;
        if (p1 == nullptr){
            count ++;
            p1 = node2;
        }
        if (p2 == nullptr) {
            count ++;
            p2 = node1;
        }
        if (p1->tree_node == p2->tree_node) {
            res = p1;
            break;
        }
        // 没有相交节点
        if (count > 2) {
            break;
        }

    }
    return res;
}

// 两个节点的最低公共祖先（这里节点本身也可以是自己的祖先，但是给的示例代码好像不行）
BinaryTreeNode* get_first_ancestor(BinaryTreeNode *root,
                                   BinaryTreeNode *node1, BinaryTreeNode *node2) {
    if (root == nullptr || node1 == nullptr || node2 == nullptr) {
        return nullptr;
    }
    ListTreeNode* path1 = get_node_path(root, node1);
    ListTreeNode* path2 = get_node_path(root, node2);
    ListTreeNode* common_node = get_common_node(path1, path2);
    BinaryTreeNode* res = nullptr;
    if (common_node != nullptr) {
        res = common_node->tree_node;

    }
    DestroyList(path1);
    DestroyList(path2);
    return res;
}


void Problem68() {
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
    cout << get_first_ancestor(pNodeA1,pNodeA1,pNodeA1)->m_value << endl;
}

