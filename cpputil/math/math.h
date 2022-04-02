//
// Created by 张宇轩 on 2021/10/17.
//

#ifndef LEARNC_MATH_H
#define LEARNC_MATH_H

#include <string>

namespace cpputil{
    namespace math {
        class Math {
        public:
            /*
             * 求x的n次幂，要求x、n为正整数，输出结果为字符串
             */
            static std::string pow(int x, int n);

            /*
             * int 随机数，左右都是闭区间
             */
            static int randInt(int min, int left);

        private:
            // pow实现的私有函数
            static std::string pow(std::string s, int x);
        };

    }
}

#endif //LEARNC_MATH_H
