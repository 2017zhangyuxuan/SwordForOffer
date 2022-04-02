// Problem57_2.cpp
// Created by 张宇轩 on 2022/3/14.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

using namespace std;
/**
 * @brief 57_2：和为s的连续正数序列
 * 输入一个整数s，打印出所有和为s的连续正数序列（至少含有两个数）。例如输入15，由于
 * 1+2+3+4+5= 4+5+6=7+8 = 15，所以打印出3个连续序列1~5，4~6，7~8
 */

#include <queue>
void print_deque(const deque<int>& q) {
    for (int i : q) {
        cout << i << " ";
    }
    cout << endl;
}

void print_sum(int s) {
    if (s < 3) {
        return;
    }
    int end = s / 2 + 1;
    int sum = 0;
    int start = 0;
    deque<int> q;
    while (start <= end) {
        start++;
        if (sum == s) {
            print_deque(q);
            sum -= q.front();
            q.pop_front();
        } else if (sum > s) {
            while (!q.empty() && sum > s) {
                sum -= q.front();
                q.pop_front();
            }
            if (sum == s) {
                print_deque(q);
                sum -= q.front();
                q.pop_front();
            }
        }
        q.push_back(start);
        sum += start;

    }

}

void PrintContinuousSequence(int small, int big);

void FindContinuousSequence(int sum)
{
    if(sum < 3)
        return;

    int small = 1;
    int big = 2;
    int middle = (1 + sum) / 2;
    int curSum = small + big;

    while(small < middle)
    {
        if(curSum == sum)
            PrintContinuousSequence(small, big);

        while(curSum > sum && small < middle)
        {
            curSum -= small;
            small ++;

            if(curSum == sum)
                PrintContinuousSequence(small, big);
        }

        big ++;
        curSum += big;
    }
}

void PrintContinuousSequence(int small, int big)
{
    for(int i = small; i <= big; ++ i)
        printf("%d ", i);

    printf("\n");
}

// ====================测试代码====================
void Test(const char* testName, int sum)
{
    if(testName != nullptr)
        printf("%s for %d begins: \n", testName, sum);

    FindContinuousSequence(sum);
}



void Problem57_2() {
    Test("test1", 1);
    print_sum(1);
    Test("test2", 3);
    print_sum(3);
    Test("test3", 4);
    print_sum(4);
    Test("test4", 9);
    print_sum(9);
    Test("test5", 15);
    print_sum(15);
    Test("test6", 100);
    print_sum(100);
}