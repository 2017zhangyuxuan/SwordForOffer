//
// Created by 张宇轩 on 2022/2/3.
//


/**
 * @brief 5、替换空格
 * 请实现一个函数，把字符串中的每个空格替换成 "%20"。例如，输入"We are happy." 输出 "We%20are%20happy."
 * @param str
 * @param length
 */
void Problem5(char str[], int length) {
    if (length <= 0 || str == nullptr) {
        return;
    }

    // 计数空格的数量
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            count ++;
        }
    }
    // 原字符串的末端
    int p1 = length;
    // 新字符串的末端
    int p2 = length + count*2;

    while (p1 != p2) {
        if (str[p1] != ' ') {
            str[p2--] = str[p1--];
        } else {
            p1--;
            str[p2--] = '0';
            str[p2--] = '2';
            str[p2--] = '%';
        }
    }


}