// Problem59_2.cpp
// Created by 张宇轩 on 2022/3/14.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

using namespace std;
/**
 * @brief 59_2
 * 题目二：队列的最大值
 * 请定义一个队列并实现函数max得到队列里的最大值，要求函数max，push_back和pop_front的时间复杂度都是O(1)
 */

#include <queue>
template<class T>
class MaxQueue {
public:

    MaxQueue() : cur_index(0){

    }
    T max_number() const  {
        return max.front().number;
    }

    void push_back(T number) {
        while (!max.empty() && number >=max.back().number) {
            max.pop_back();
        }
        IndexData index_data(number, cur_index);
        max.push_back(index_data);
        data.push_back(index_data);
        cur_index ++ ;
    }

    void pop_front() {
        if (max.empty() || data.empty()) {
            throw "Empty Queue!";
        }
        if (data.front().index == max.front().index) {
            max.pop_front();
        }
        data.pop_front();
    }

private:
    int cur_index;
    struct IndexData {
        T number;
        int index;
        IndexData(T num, int idx) {
            number = num;
            index = idx;
        }
    };
    deque<IndexData> data;
    deque<IndexData> max;




};

namespace problem59_2{
    // ====================测试代码====================
    void Test(const char* testName, const MaxQueue<int>& queue, int expected)
    {
        if(testName != nullptr)
            printf("%s begins: ", testName);

        if(queue.max_number() == expected)
            printf("Passed.\n");
        else
            printf("FAILED.\n");
    }

    void test59()
    {
        MaxQueue<int> queue;
        // {2}
        queue.push_back(2);
        Test("Test1", queue, 2);

        // {2, 3}
        queue.push_back(3);
        Test("Test2", queue, 3);

        // {2, 3, 4}
        queue.push_back(4);
        Test("Test3", queue, 4);

        // {2, 3, 4, 2}
        queue.push_back(2);
        Test("Test4", queue, 4);

        // {3, 4, 2}
        queue.pop_front();
        Test("Test5", queue, 4);

        // {4, 2}
        queue.pop_front();
        Test("Test6", queue, 4);

        // {2}
        queue.pop_front();
        Test("Test7", queue, 2);

        // {2, 6}
        queue.push_back(6);
        Test("Test8", queue, 6);

        // {2, 6, 2}
        queue.push_back(2);
        Test("Test9", queue, 6);

        // {2, 6, 2, 5}
        queue.push_back(5);
        Test("Test9", queue, 6);

        // {6, 2, 5}
        queue.pop_front();
        Test("Test10", queue, 6);

        // {2, 5}
        queue.pop_front();
        Test("Test11", queue, 5);

        // {5}
        queue.pop_front();
        Test("Test12", queue, 5);

        // {5, 1}
        queue.push_back(1);
        Test("Test13", queue, 5);

    }
}

void Problem59_2() {
    problem59_2::test59();

}
