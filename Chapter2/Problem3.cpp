#include<iostream>
#include<vector>
using namespace std;

namespace p3 {

    void print_vector(const std::vector<int> &vec) {
        cout << "[ " ;
        for (auto value : vec) {
            cout << value << ", ";
        }
        cout << "]" << endl;
    }

    bool test1(int arr[], int n, vector<int>& res) {
        if (arr == nullptr || n <= 1) {
            return false;
        }

        for (int i=0; i<n; i++) {
            // 输入的数据小于0 或者 大于等于n ，属于无效输入
            if (arr[i] < 0 || arr[i] >= n) {
                return false;
            }
        }
        bool is_dup = false;
        int index = 0;
        while (index < n) {
            while (arr[index] != index) {
                if (arr[index] == -1)
                    break;
                // 找到重复数字
                if (arr[index] == arr[arr[index]]) {
                    res.push_back(arr[index]);
                    is_dup = true;
                    arr[index] = -1;
                    break;
                }
                swap(arr[index], arr[arr[index]]);
            }
            index++;
        }
        return is_dup;
    }

    int count(int arr[], int n, int min, int max) {
        if (arr == nullptr || n <= 0 || min > max) {
            return 0;
        }
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (arr[i] >= min && arr[i] <= max ) {
                cnt++;
            }
        }
        return cnt;
    }
    // 数组有n个元素，数组元素取值范围 1~n-1
    bool test2(int arr[], int n, int& duplicate) {
        if (arr == nullptr || n <= 1) {
            return false;
        }
        bool is_dup = false;
        int min = 1;
        int max = n - 1;
        while (max >= min) {
            int middle = (max-min) / 2  + min;
            int cnt = count(arr, n, min, middle);
            if (max == min && cnt > 1) {
                duplicate = min;
                is_dup = true;
                break;
            }
            if (cnt > (middle - min +1)) {
                max = middle;
            } else {
                min = middle + 1;
            }
        }
        return is_dup;
    }

}


/**
 * @brief 在一个长度为n的数组里的所有数字都在0~n-1范围内。数组中的某些数字是重复的，但不知道有几个数字
 * 重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
 * 如 {2,3,1,0,2,5,3} 对应输出为 2 或 3
 */

// 数组中重复的数字
void Problem3(){
    int arr[] = {0,7,5,4,7,2,6,7};
    int dup;
    vector<int> vec;
    cout << boolalpha << p3::test1(arr, 8, vec) << endl;
    p3::print_vector(vec);
}
