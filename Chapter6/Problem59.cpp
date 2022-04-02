// Problem59.cpp
// Created by 张宇轩 on 2022/3/14.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

using namespace std;
/**
 * @brief 59、队列的最大值
 * 题目一：滑动窗口的最大值
 * 给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及
 * 滑动窗口的大小3，那么一共存在6个滑动窗口，它们的最大值分别为{4,4,6,6,6,5}。
 */



#include <vector>
#include <deque>
vector<int> get_max_sliding_window(const vector<int>& window, int size) {
    vector<int> res;
    if (window.size() == 0 || size <= 0) {
        return res;
    }
    if (size == 1) {
        return window;
    }
    deque<int> q;
    for (int i=0;i<window.size();i++) {
        if (q.empty()) {
            q.push_back(i);
        } else {
            if (i - q.front() >= size) {
                q.pop_front();
            }
            while (!q.empty() && window[q.back()] < window[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        if (i >= size-1) {
            res.push_back(window[q.front()]);
        }
    }
    return res;

}

namespace problem59 {
    // ====================测试代码====================
    void Test(const char* testName, const vector<int>& num, unsigned int size, const vector<int>& expected)
    {
        if(testName != nullptr)
            printf("%s begins: ", testName);

        vector<int> result = get_max_sliding_window(num, size);

        vector<int>::const_iterator iterResult = result.begin();
        vector<int>::const_iterator iterExpected = expected.begin();
        while(iterResult < result.end() && iterExpected < expected.end())
        {
            if(*iterResult != *iterExpected)
                break;

            ++iterResult;
            ++iterExpected;
        }

        if(iterResult == result.end() && iterExpected == expected.end())
            printf("Passed.\n");
        else
            printf("FAILED.\n");
    }

    void Test1()
    {
        int num[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
        vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

        int expected[] = { 4, 4, 6, 6, 6, 5 };
        vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

        unsigned int size = 3;

        Test("Test1", vecNumbers, size, vecExpected);
    }

    void Test2()
    {
        int num[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
        vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

        int expected[] = { 3, 3, 5, 5, 6, 7 };
        vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

        unsigned int size = 3;

        Test("Test2", vecNumbers, size, vecExpected);
    }

// 输入数组单调递增
    void Test3()
    {
        int num[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
        vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

        int expected[] = { 7, 9, 11, 13, 15 };
        vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

        unsigned int size = 4;

        Test("Test3", vecNumbers, size, vecExpected);
    }

// 输入数组单调递减
    void Test4()
    {
        int num[] = { 16, 14, 12, 10, 8, 6, 4 };
        vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

        int expected[] = { 16, 14, 12 };
        vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

        unsigned int size = 5;

        Test("Test4", vecNumbers, size, vecExpected);
    }

// 滑动窗口的大小为1
    void Test5()
    {
        int num[] = { 10, 14, 12, 11 };
        vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

        int expected[] = { 10, 14, 12, 11 };
        vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

        unsigned int size = 1;

        Test("Test5", vecNumbers, size, vecExpected);
    }

// 滑动窗口的大小等于数组的长度
    void Test6()
    {
        int num[] = { 10, 14, 12, 11 };
        vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

        int expected[] = { 14 };
        vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

        unsigned int size = 4;

        Test("Test6", vecNumbers, size, vecExpected);
    }

// 滑动窗口的大小为0
    void Test7()
    {
        int num[] = { 10, 14, 12, 11 };
        vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

        vector<int> vecExpected;

        unsigned int size = 0;

        Test("Test7", vecNumbers, size, vecExpected);
    }

// 滑动窗口的大小大于输入数组的长度
    void Test8()
    {
        int num[] = { 10, 14, 12, 11 };
        vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

        vector<int> vecExpected;

        unsigned int size = 5;

        Test("Test8", vecNumbers, size, vecExpected);
    }

// 输入数组为空
    void Test9()
    {
        vector<int> vecNumbers;
        vector<int> vecExpected;

        unsigned int size = 5;

        Test("Test9", vecNumbers, size, vecExpected);
    }
}



void Problem59() {
    problem59::Test1();
    problem59::Test2();
    problem59::Test3();
    problem59::Test4();
    problem59::Test5();
    problem59::Test6();
    problem59::Test7();
    problem59::Test8();
    problem59::Test9();
}
