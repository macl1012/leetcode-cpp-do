/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int maxPathSum(TreeNode* root) {
        oneSideMax(root);
        return ans == INT_MIN ? 0 : ans;
    }

    int oneSideMax(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = max(0, oneSideMax(root->left));
        int right = max(0, oneSideMax(root->right));
        ans = max(ans, left + right + root->val);
        return max(left, right) + root->val;
    }

private:
    int ans = INT_MIN;
};
// @lc code=end

