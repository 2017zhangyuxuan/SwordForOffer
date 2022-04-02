//
// Created by 张宇轩 on 2022/2/3.
//

#ifndef CHAPTER2_STRUCTS_H
#define CHAPTER2_STRUCTS_H
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0),next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* p_next) : val(x), next(p_next) {}

    static ListNode*  construct_list(int *arr, int len) {
        if (arr == nullptr || len <= 0) {
            return nullptr;
        }
        ListNode* head = new ListNode(arr[0]);
        ListNode* cur = head;
        for (int i=1; i<len; i++) {
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
        return head;
    }

};




#endif //CHAPTER2_STRUCTS_H
