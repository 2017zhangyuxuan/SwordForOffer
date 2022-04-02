// Problem37.cpp
// Created by 张宇轩 on 2022/3/4.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include <string>
#include "Util.h"
#include <sstream>
using namespace std;
/**
 * @brief 37、序列化二叉树
 * 请事先两个函数，分别用来序列化和反序列化二叉树
 */


string serialize(BinaryTreeNode* root) {
    if (root == nullptr) {
        return "$";
    }
    string res = to_string(root->m_value);
    res =  res + " " + serialize(root->m_left);
    res = res + " " + serialize(root->m_right);
    return res;
}

BinaryTreeNode* deserialize(string& str) {
    if (str.empty() || str[0] == '$') {
        if (str.length() >= 2)
            str = str.substr(2, str.length() - 2);
        else
            str = "";
        return nullptr;
    }
    int idx = str.find(",");
    int num = atoi(str.substr(0,idx).data());
    str = str.substr(idx+1, str.length() - idx);


    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_value = num;
    root->m_left = deserialize(str);
    root->m_right = deserialize(str);
    return root;
}

BinaryTreeNode* deserialize(istringstream & is) {
   int num;
   if (is >> num) {
       BinaryTreeNode* root = new BinaryTreeNode;
       root->m_value = num;
       root->m_left = deserialize(is);
       root->m_right = deserialize(is);
       return root;
   } else {
       return nullptr;
   }
   return nullptr;
}

void Problem37() {
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

    string t =  serialize(pNode10);
    cout << t << endl;
    istringstream is(t);
    BinaryTreeNode* root = deserialize(is);
    cout << root->m_left->m_left->m_value<<endl;

}
