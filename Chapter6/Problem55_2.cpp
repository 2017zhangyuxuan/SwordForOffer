// Problem55_2.cpp
// Created by 张宇轩 on 2022/3/13.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include "Util.h"
/**
 * @brief 55、二叉树的深度
 *
 * 题目二：输入一棵二叉树的根节点，判断该树是不是一棵平衡二叉树，如果某二叉树中任意节点的左、右子树的深度
 * 相差不超过1，那么它就是一棵平衡二叉树
 */


bool balance_tree(BinaryTreeNode* root, int* depth) {
    if (root == nullptr)
        return true;
    int left = 0,right = 0;
    bool flag = balance_tree(root->m_left,&left) && balance_tree(root->m_right, &right);
    if (!flag) {
        return false;
    }
    flag = abs(left - right) <= 1;
    *depth = max(left,right) + 1;
    return flag;
}

bool is_balance_tree(BinaryTreeNode* root) {
    if (root == nullptr)
        return true;
    int depth = 0;
    return balance_tree(root,&depth);
}

namespace p55_2{
    // ====================测试代码====================
    void Test(const char* testName, const BinaryTreeNode* pRoot, bool expected)
    {
        if(testName != nullptr)
            printf("%s begins:\n", testName);

        printf("Solution1 begins: ");
        if(is_balance_tree(const_cast<BinaryTreeNode*>(pRoot)) == expected)
            printf("Passed.\n");
        else
            printf("Failed.\n");

//    printf("Solution2 begins: ");
//    if(IsBalanced_Solution2(pRoot) == expected)
//        printf("Passed.\n");
//    else
//        printf("Failed.\n");
    }

// 完全二叉树
//             1
//         /      \
//        2        3
//       /\       / \
//      4  5     6   7
    void Test1()
    {
        BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
        BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
        BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
        BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
        BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
        BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
        BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

        ConnectTreeNodes(pNode1, pNode2, pNode3);
        ConnectTreeNodes(pNode2, pNode4, pNode5);
        ConnectTreeNodes(pNode3, pNode6, pNode7);

        Test("Test1", pNode1, true);

        DestroyTree(pNode1);
    }

// 不是完全二叉树，但是平衡二叉树
//             1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
    void Test2()
    {
        BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
        BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
        BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
        BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
        BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
        BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
        BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

        ConnectTreeNodes(pNode1, pNode2, pNode3);
        ConnectTreeNodes(pNode2, pNode4, pNode5);
        ConnectTreeNodes(pNode3, nullptr, pNode6);
        ConnectTreeNodes(pNode5, pNode7, nullptr);

        Test("Test2", pNode1, true);

        DestroyTree(pNode1);
    }

// 不是平衡二叉树
//             1
//         /      \
//        2        3
//       /\
//      4  5
//        /
//       6
    void Test3()
    {
        BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
        BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
        BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
        BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
        BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
        BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);

        ConnectTreeNodes(pNode1, pNode2, pNode3);
        ConnectTreeNodes(pNode2, pNode4, pNode5);
        ConnectTreeNodes(pNode5, pNode6, nullptr);

        Test("Test3", pNode1, false);

        DestroyTree(pNode1);
    }


//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
    void Test4()
    {
        BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
        BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
        BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
        BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
        BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

        ConnectTreeNodes(pNode1, pNode2, nullptr);
        ConnectTreeNodes(pNode2, pNode3, nullptr);
        ConnectTreeNodes(pNode3, pNode4, nullptr);
        ConnectTreeNodes(pNode4, pNode5, nullptr);

        Test("Test4", pNode1, false);

        DestroyTree(pNode1);
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
    void Test5()
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

        Test("Test5", pNode1, false);

        DestroyTree(pNode1);
    }

// 树中只有1个结点
    void Test6()
    {
        BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
        Test("Test6", pNode1, true);

        DestroyTree(pNode1);
    }

// 树中没有结点
    void Test7()
    {
        Test("Test7", nullptr, true);
    }

}


void Problem55_2() {
    p55_2::Test1();
    p55_2::Test2();
    p55_2::Test3();
    p55_2::Test4();
    p55_2::Test5();
    p55_2::Test6();
    p55_2::Test7();
}