//
// Created by 张宇轩 on 2022/1/24.
//

#include "ContainersUtil.h"
#include <iostream>
using namespace std;
namespace cpputil {
    namespace containers {
        // TODO: 为什么这个模板无法使用，调用的时候会报错 undefined symbols；但是直接在头文件里定义函数实现的话又是可行的？
//        template<class Type>
//        void ContainersUtil::print_vector(const std::vector<Type> &vec) {
//            cout << "[ " ;
//            for (auto value : vec) {
//                cout << value << ", ";
//            }
//            cout << "]" << endl;
//        }

        // int 特化
        template<>
        void ContainersUtil::print_vector<int>(const std::vector<int> &vec) {
            cout << "[ " ;
            for (auto value : vec) {
                cout << value << ", ";
            }
            cout << "]" << endl;
        }
    } // namespace containers
} // namespace cpputil