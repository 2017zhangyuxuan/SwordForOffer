//
// Created by 张宇轩 on 2022/1/24.
//

#ifndef LEARNC_CONTAINERSUTIL_H
#define LEARNC_CONTAINERSUTIL_H
#include <vector>
#include <iostream>

namespace cpputil {
    namespace containers{
        class ContainersUtil {
        public :
            template<class Type>
            static void print_vector(const std::vector<Type>& vec);


        };
    }   // namespace containers
}   // namespace cpputil



#endif //LEARNC_CONTAINERSUTIL_H
