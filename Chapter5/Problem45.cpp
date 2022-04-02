// Problem45.cpp
// Created by 张宇轩 on 2022/3/7.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
/**
 * @brief 45、把数组排成最小的数
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中的最小的一个
 */

// 获取数字的最高位
int get_first(int num) {
    int res = num;
    num /= 10;
    while (num > 0) {
        res = num;
        num /= 10;
    }
    return res;
}


void print_min_num(int* arr, int len) {
    if (arr == nullptr || len <= 0) {
        return ;
    }

    // 首先按首位分组
    vector<vector<string> > vec(10);
    for (int i=0; i<len;i++) {
        int first = get_first(arr[i]);
        vec[first].push_back(to_string(arr[i]));
    }

    // 分组内进行排序
    for (int i=1;i<10;i++) {
        int num = i;
        sort(vec[i].begin(),vec[i].end(), [num](string&num1, string& num2) ->bool {
            string n1 = num1;
            string n2 = num2;
            reverse(n1.begin(),n1.end());
            reverse(n2.begin(),n2.end());
            int idx1 =0, idx2 = 0;
            while (idx1 != n1.size() && idx2 != n2.size()) {
                if (n1[idx1] != n2[idx2]) {
                    return n1[idx1] < n2[idx2];
                }
                idx1++;
                idx2++;
            }
            bool res = true;
            if (idx1 == n1.size()) {
                while (idx2 != n2.size() && n2[idx2]-'0' == num) {
                    idx2++;
                }
                if (idx2 < n2.size()) {
                    res = n2[idx2]-'0' > num;
                }
            }
            if (idx2 == n2.size()) {
                while (idx1 != n1.size() && n1[idx1]-'0' == num) {
                    idx1++;
                }
                if (idx1 < n1.size()) {
                    res = n1[idx1]-'0' < num;
                }
            }
            return res;
        });
    }

    ostringstream os;
    // 进行拼接
    for (int i=1; i< 10; i++) {
        for (string s : vec[i]) {
            os << s;
        }
    }
    cout << os.str() << endl;

}

void Problem45(){
    int arr[] = {1,3,5,2,1};
    print_min_num(arr, 5);

}

