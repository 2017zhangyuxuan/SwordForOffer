//
// Created by 张宇轩 on 2022/2/3.
//
#include "Structs.h"

TreeNode* reconstruct(int *preorder, int ps, int pe, int *inorder, int is, int ie) {
    if (preorder == nullptr || ps > pe || ps < 0 ||
        inorder == nullptr || is > is || is < 0 || (pe-ps) != (ie -is)) {
        return nullptr;
    }
    // 先序遍历的第一个节点是根节点
    TreeNode* root = new TreeNode(preorder[ps]);
    int index = is;
    for (int i=is; i <= ie ;i ++) {
        if (preorder[ps] == inorder[i]) {
            index = i;
        }
    }
    int left_len = index - is;
    root->left = reconstruct(preorder, ps+1, ps+left_len, inorder, is, index-1);
    root->right = reconstruct(preorder,ps+left_len+1, pe, inorder, index+1, ie);
    return root;
}

// 根据前序遍历和中序遍历重建二叉树
TreeNode* Problem7(int *preorder, int *inorder, int length) {
    if (preorder == nullptr || inorder == nullptr || length <= 0) {
        return nullptr;
    }
    return reconstruct(preorder, 0, length-1, inorder, 0, length -1);

}

