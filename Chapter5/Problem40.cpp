// Problem40.cpp
// Created by 张宇轩 on 2022/3/5.
// Copyright (c) 2022 zhangyuxuan. All rights reserved.
// 
#include <iostream>
#include <vector>
using namespace std;
/**
 * @brief 40、最小的k个数
 * 输入n个整数，找出其中最小的k个数
 */

void swap(int& num1, int& num2) {
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}

int partition(int* arr, int start, int end) {
    if (arr == nullptr || start > end)
        return -1;
    if (start == end)
        return start;
    int num = arr[start];
    int left = start;
    int right = end;
    while (left < right) {
        while (left < right && arr[right] >= num) {
            right--;
        }
        swap(arr[left], arr[right]);
        while (left < right && arr[left] < num) {
            left++;
        }
        swap(arr[left], arr[right]);
    }
    arr[left] = num;
    return left;
}

vector<int> get_min_k(int* arr, int length, int k) {
    vector<int> res;
    if (arr == nullptr)
        return res;
    if (k >= length) {
        res.insert(res.begin(),arr,arr+length);
        return res;
    }
    int start = 0, end = length-1;
    while (start <= end) {
        int index = partition(arr,start, end);
        if (index == k) {
            res.insert(res.begin(),arr,arr+k);
            break;
        } else if(index > k) {
            end = index-1;
        } else {
            start = index+1;
        }
    }
    return res;
}
#include <queue>
#include <set>

vector<int> get_k_num(vector<int>& nums,int k) {
    int size = nums.size();
    vector<int> res;
    if (size <= k) {
        res = nums;
        return res;
    }
    multiset<int, greater<> > s;

    for (int num : nums) {
        s.insert(num);
        if (s.size() > k) {
            s.erase(s.begin());
        }
    }
    for (int num : s) {
        res.push_back(num);
    }
    return res;
}

#include <map>
void Problem40() {
    int arr[] = {4,4,4,4,1,7,3,8};
    vector<int> res = get_min_k(arr,8,7);
    for (int num : res) {
        cout <<  num << " " << endl;
    }

}