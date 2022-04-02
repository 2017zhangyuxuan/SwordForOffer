// Problem41.cpp
// Created by 张宇轩 on 2022/3/6.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/**
 * @brief 41、数据流中的中位数
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果是偶数个值，那么中位数就是所有数值排序之后中间两个数值的平均值
 */

// 测试用例：0、1、2个数； 多个数（奇偶）

class DynamicArray {
public:
    void push(int num) {
        if (max.size() > min.size()) {
            min.push(num);
        } else {
            max.push(num);
        }
        check();
    }

    double get_medium() {
        if (max.empty() && min.empty()) {
            throw "no data";
        }
        double res  = 0.0;
        if (max.size() == min.size()) {
            res = ((double)max.top() + min.top()) / 2.0;
        } else {
            res = max.top();
        }
        return res ;
    }
private:
    priority_queue<int> max;        // 维护左边的容器
    priority_queue<int, vector<int>, greater<> > min;   // 维护右边的容器

    // 检验，确保max堆顶小于min的堆顶
    void check() {
        if (max.empty() || min.empty())
            return;
        if (max.top() > min.top()) {
            int max_tmp = max.top();
            int min_tmp = min.top();
            max.pop();
            min.pop();
            max.push(min_tmp);
            min.push(max_tmp);
        }
    }
};

void Problem41() {
    DynamicArray arr;
    arr.push(1);
    cout << arr.get_medium() << endl;
    arr.push(-1);
    cout << arr.get_medium() << endl;
    arr.push(3);
//    arr.push(4);
    std::cout << arr.get_medium() << std::endl;


}