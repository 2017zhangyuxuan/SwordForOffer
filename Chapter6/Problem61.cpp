// Problem61.cpp
// Created by 张宇轩 on 2022/3/15.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

using namespace std;
/**
 * @brief 61、扑克牌中的顺子
 * 从扑克牌中随机抽取5张牌，判断是不是一个顺子，即这5张是不是连续的。2~10为数字本身，A为1，
 * J为11，Q为12，K为13，而大、小王可以看成是任意数字
 */


bool is_shunzi(int *arr , int len) {
    if (arr == nullptr)
        return false;

    int wang = 0;
    int gap = 0;
    sort(arr, arr+len);
    while (arr[wang] == 0) {
        wang++;
    }
    for (int i=wang; i<len-1;i++) {
        if (arr[i] == arr[i+1]) {
            return false;
        }
        gap += arr[i+1] - arr[i] - 1;
    }

    return gap <= wang;
}

namespace problem61 {
    // ====================测试代码====================
    void Test(const char* testName, int* numbers, int length, bool expected)
    {
        if(testName != nullptr)
            printf("%s begins: ", testName);

        if(is_shunzi(numbers, length) == expected)
            printf("Passed.\n");
        else
            printf("Failed.\n");
    }

    void Test1()
    {
        int numbers[] = { 1, 3, 2, 5, 4 };
        Test("Test1", numbers, sizeof(numbers) / sizeof(int), true);
    }

    void Test2()
    {
        int numbers[] = { 1, 3, 2, 6, 4 };
        Test("Test2", numbers, sizeof(numbers) / sizeof(int), false);
    }

    void Test3()
    {
        int numbers[] = { 0, 3, 2, 6, 4 };
        Test("Test3", numbers, sizeof(numbers) / sizeof(int), true);
    }

    void Test4()
    {
        int numbers[] = { 0, 3, 1, 6, 4 };
        Test("Test4", numbers, sizeof(numbers) / sizeof(int), false);
    }

    void Test5()
    {
        int numbers[] = { 1, 3, 0, 5, 0 };
        Test("Test5", numbers, sizeof(numbers) / sizeof(int), true);
    }

    void Test6()
    {
        int numbers[] = { 1, 3, 0, 7, 0 };
        Test("Test6", numbers, sizeof(numbers) / sizeof(int), false);
    }

    void Test7()
    {
        int numbers[] = { 1, 0, 0, 5, 0 };
        Test("Test7", numbers, sizeof(numbers) / sizeof(int), true);
    }

    void Test8()
    {
        int numbers[] = { 1, 0, 0, 7, 0 };
        Test("Test8", numbers, sizeof(numbers) / sizeof(int), false);
    }

    void Test9()
    {
        int numbers[] = { 3, 0, 0, 0, 0 };
        Test("Test9", numbers, sizeof(numbers) / sizeof(int), true);
    }

    void Test10()
    {
        int numbers[] = { 0, 0, 0, 0, 0 };
        Test("Test10", numbers, sizeof(numbers) / sizeof(int), true);
    }

// 有对子
    void Test11()
    {
        int numbers[] = { 1, 0, 0, 1, 0 };
        Test("Test11", numbers, sizeof(numbers) / sizeof(int), false);
    }

// 鲁棒性测试
    void Test12()
    {
        Test("Test12", nullptr, 0, false);
    }


}

void Problem61() {
    problem61::Test1();
    problem61::Test2();
    problem61::Test3();
    problem61::Test4();
    problem61::Test5();
    problem61::Test6();
    problem61:: Test7();
    problem61:: Test8();
    problem61::Test9();
    problem61::Test10();
    problem61::Test11();
    problem61::Test12();
}