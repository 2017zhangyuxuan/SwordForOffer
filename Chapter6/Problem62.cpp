// Problem62.cpp
// Created by 张宇轩 on 2022/3/15.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

using namespace std;

/**
 * @brief 62、圆圈中最后剩下的数字
 * 0,1,...,n-1 这n个数字排成一个圈，从数字0开始，每次从这个圆圈里删除第m个数字。
 * 求出这个圆圈里剩下的最后一个数字
 */


#include <list>
int delete_m(int n, int m) {
    list<int> round;
    if (n <= 0 || m <= 0) {
        return -1;
    }
    if (n==1) {
        return 0;
    }
    for (int i=0;i<n;i++) {
        round.push_back(i);
    }

    int offset = 0;
    auto iter = round.begin();
    while (round.size() > 1) {
        offset = (m-1) % round.size();
        for (int i=0;i<offset;i++) {
            iter++;
            if (iter == round.end()) {
                iter = round.begin();
            }
        }
        iter = round.erase(iter);
        if (iter == round.end()) {
            iter = round.begin();
        }
    }
    return round.front();

}

int get_last_number(int n, int m)  {
    if (n <=0 || m <=0)
        return -1;
    if (n==1)
        return 0;
    int last = 0;
    for (int i = 2; i<=n;i++) {
        last = (last + m) % i;
    }
    return last;
}

namespace problem62 {
    // ====================测试代码====================
    void Test(const char* testName, unsigned int n, unsigned int m, int expected)
    {
        if(testName != nullptr)
            printf("%s begins: \n", testName);

        if(delete_m(n, m) == expected)
            printf("Solution1 passed.\n");
        else
            printf("Solution1 failed.\n");

        if(get_last_number(n, m) == expected)
            printf("Solution2 passed.\n");
        else
            printf("Solution2 failed.\n");

        printf("\n");
    }

    void Test1()
    {
        Test("Test1", 5, 3, 3);
    }

    void Test2()
    {
        Test("Test2", 5, 2, 2);
    }

    void Test3()
    {
        Test("Test3", 6, 7, 4);
    }

    void Test4()
    {
        Test("Test4", 6, 6, 3);
    }

    void Test5()
    {
        Test("Test5", 0, 0, -1);
    }

    void Test6()
    {
        Test("Test6", 4000, 997, 1027);
    }


}


#include <queue>
#include <map>
void Problem62() {
    problem62::Test1();
    problem62::Test2();
    problem62::Test3();
    problem62::Test4();
    problem62::Test5();
    problem62::Test6();
    
    


}
