//
// Created by 张宇轩 on 2021/9/15.
//

#include "Chapter2.h"
#include <iostream>

using namespace std;

class A {
public:
    int num;
    static int ss;
    static std::mutex mutex;
};

int A::ss = 10;
std::mutex A::mutex;
int main() {
    Problem2();
}
