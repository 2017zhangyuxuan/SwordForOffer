//
// Created by 张宇轩 on 2022/2/3.
//

/**
 * @brief 4、在二维数组中进行查找
 * 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数
 * 1  2  8   9
 * 2  4  9   12
 * 4  7  10  13
 * 6  8  11  15
 *
 *
 * @param martix
 * @param rows
 * @param columns
 * @param number
 * @return
 */

bool Problem4(int (*martix)[4], int rows, int columns, int number) {
    if (martix == nullptr) {
        return false;
    }
    bool flag = false;
    int row = 0, column = columns - 1;
    while (row < rows && column >= 0) {
        if (martix[row][column] == number) {
            flag = true;
            break;
        } else if (martix[row][column] > number) {
            column --;
        } else {
            row ++;
        }
    }

    return flag;
}