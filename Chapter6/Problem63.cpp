// Problem63.cpp
// Created by 张宇轩 on 2022/3/17.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>

/**
 * @brief 63、股票的最大利润
 * 假设把某股票的价格按照时间先后顺序存储在数组汇总，请问买卖该股票一次可能获得的最大利润是多少？
 * 例如，一只股票在某些时间节点的价格为{9,11,8,5,7,12,16,14}。如果我们能在价格为5的时候买入并在
 * 价格为16时卖出，则能收获最大的利润为11.
 */


// 测试用例：边界情况，最小值和最大值相邻，在两侧；错误情况：价格一直下跌

int get_max_profit(int *prices, int len) {
    if (prices == nullptr || len <= 1) {
        return 0;
    }
    int profit = 0;
    int min = prices[0];
    for (int i=1;i <len; i++) {
        if (prices[i] - min > profit) {
            profit = prices[i] - min;
        }
        if (prices[i] < min) {
            min = prices[i];
        }
    }
    return profit;
}

void Problem63() {
    int prices[] = {1,1,8,5,7,12,1,14};
    std::cout << get_max_profit(prices,8) << std::endl;
    std::max(1,1);
}