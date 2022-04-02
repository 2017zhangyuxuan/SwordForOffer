//
// Created by 张宇轩 on 2022/2/3.
//
#include "Structs.h"
#include <stack>
using namespace std;
// 从尾到头打印链表
void Problem6(ListNode* head) {
    if (head == nullptr) {
        return;
    }
    ListNode* cur = head;
    stack<ListNode*> s;
    while (cur != nullptr) {
        s.emplace(cur);
        cur = cur->next;
    }
    while (!s.empty()) {
        cur = s.top();
        s.pop();
        printf("%d ", cur->val);
    }
    printf("\n");
}