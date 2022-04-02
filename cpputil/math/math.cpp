//
// Created by 张宇轩 on 2021/10/17.
//

#include "math.h"
#include <random>
#include <vector>

namespace cpputil {
    namespace math {
        std::string Math::pow(int x, int n) {
            if (x <= 0 || n < 0)
                return 0;
            std::string res = "1";
            for (int i = 0; i < n; i++) {
                res = pow(res, x);
            }
            return res;
        }

        std::string Math::pow(std::string s, int x) {
            std::vector<char> res(s.length(),'0');
            res.resize(s.length());

            int input[s.length()];
            for (int i=0; i< s.length(); i++) {
                input[i] = s[s.length()-i-1]-'0';
            }
            int n = 0;
            while (x > 0) {
                int num = x % 10;
                int flag = 0;
                for (int i=0; i < s.length(); i++) {
                    int t1 = input[i] * num + flag;
                    if (i+n >= res.size()) {
                        res.push_back('0');
                    }
                    int t2 = ((res[i+n]-'0') + t1);
                    flag = t2 / 10;
                    res[i+n] = char(t2 % 10 + '0');
                }
                if (flag > 0)
                    res.push_back(char(flag + '0'));
                x /= 10;
                n++;
            }
            std::reverse(res.begin(), res.end());
            return {res.begin(),res.end()};
        }

        int Math::randInt(int min, int max) {
            if (min > max ){
                // 错误处理
                throw std::range_error("Min value is bigger than max value !");
            }
            static std::random_device rd;  //Will be used to obtain a seed for the random number engine
            static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
            std::uniform_int_distribution<int> distrib(min, max);
            return distrib(gen);

        }
    }
}