//
// Created by 张宇轩 on 2021/9/15.
//

#ifndef SWORDFOROFFER_CHAPTER2_H
#define SWORDFOROFFER_CHAPTER2_H
#include "Structs.h"

// 单例模式
void Problem2();

// 数组中重复的数字
void Problem3();

// 在二维数组中进行查找
bool Problem4(int (*martix)[4], int rows, int columns, int number);

// 字符串中替换空格为 %20，在原字符串上进行替换
void Problem5(char str[], int length);

// 从尾到头打印链表
void Problem6(ListNode* head);

// 根据前序遍历和中序遍历重建二叉树
TreeNode* Problem7(int *preorder, int *inorder, int length);

// 用队列实现栈
void Problem9();

// 旋转数组的最小数字
void Problem11();

// 矩阵中的路径
void Problem12();

// 问题13：机器人的运动范围
int moving_count(int threshold, int rows, int cols);

// 14、剪绳子
void Problem14();

// 15、二进制中 1 的个数
void Problem15();

#endif //SWORDFOROFFER_CHAPTER2_H
