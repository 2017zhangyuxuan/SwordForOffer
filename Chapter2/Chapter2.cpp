//
// Created by 张宇轩 on 2021/9/15.
//

#include "Chapter2.h"
#include <vector>
#include <iostream>
#include "../cpputil/container/ContainersUtil.h"

using namespace std;

void test_problem2() {
    Problem2();
}
void test_problem3() {
    Problem3();
}
void test_problem4() {
    int martix[4][4] =
            { 1,2,8,9,
              1,4,9,12,
              4,7,10,13,
              6,8,11,15};
    cout << boolalpha << Problem4(nullptr, 4,4, 111                 ) << endl;
}

void test_problem5() {
    char str[] = "asd";
    Problem5(str, 12);
    cout << str << endl;
}

void test_problem6() {
    int arr[] = {4,1,6,3,8,2};
    ListNode* head = ListNode::construct_list(arr, 6);
    Problem6(head);
}

// 前序遍历 递归写法
void preorder_recursion(TreeNode* root, vector<int>& res) {
    if (root == nullptr)
        return;
    res.emplace_back(root->val);
    preorder_recursion(root->left,res);
    preorder_recursion(root->right, res);

}

void inorder_recursion(TreeNode* root, vector<int>& res) {
    if (root == nullptr)
        return;
    inorder_recursion(root->left, res);
    res.push_back(root->val);
    inorder_recursion(root->right, res);
}
using  cpputil::containers::ContainersUtil;
void test_problem7() {
    int preorder[] = {1,2,4,7,3,5,6,8};
    int inorder[] = {4,7,2,1,5,3,8,6};
    TreeNode* root = Problem7(preorder, inorder, 8);
    vector<int> res;
    preorder_recursion(root, res);
    ContainersUtil::print_vector(res);
    res.clear();
    inorder_recursion(root, res);
    ContainersUtil::print_vector(res);
}

void test_problem9() {
    Problem9();
}

void test_problem11() {
    Problem11();
}

int main() {
    Problem15();

    cout << "-------------------------END-------------------------" << endl;
}

