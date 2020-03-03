/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
// 方法1：完全递归方式求解
// 计算高度的时候每次都递归求一遍它的高度
//     bool isBalanced(TreeNode* root) {
//         if(!root) return true;

//         if(isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1) {
//             return true;
//         }

//         return false;
//     }
// private:
//     int height(TreeNode* root) {
//         if(!root) return 0;
//         return (max(height(root->left), height(root->right)) + 1);
//     }

// 优化方法，递归一次计算左右子树高度的过程中，
// 如果左右子树高度差大于1，则可直接判定非平衡二叉树
//     bool isBalanced(TreeNode* root) {
//         height(root);
//         return ret;
//     }

// private:
//     int height(TreeNode* root) {
//         if(!ret) return 0; // 已经判断子树非平衡二叉树后，直接返回0中断递归
//         if(!root) return 0;
//         int lh = height(root->left);
//         int rh = height(root->right);
//         if(abs(lh - rh) > 1)
//             ret = false;
//         return max(lh, rh) + 1;
//     }

//     bool ret = true;

// 改进，不使用类成员变量
    bool isBalanced(TreeNode* root) {
        // 如果子树平衡，返回它的高度，
        // 如果子树不平衡，返回-1
        if(!root) return true;
        return height(root) != -1;
    }

private:
    int height(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int l = height(root->left);
        if(l < 0) return -1;
        int r = height(root->right);
        if(r < 0) return -1;
        if(abs(l - r) > 1) return -1;
        return max(l, r) + 1;
    }
};
// @lc code=end

