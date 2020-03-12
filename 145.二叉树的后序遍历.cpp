/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    // // 递归实现
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     traverse(root, res);
    //     return res;
    // }

    // void traverse(TreeNode* root, vector<int>& res) {
    //     if(!root) return;
    //     traverse(root->left, res);
    //     traverse(root->right, res);
    //     res.push_back(root->val);
    // }

    // 迭代算法
    // 采用前序按照根-右-左遍历实现后，reverse
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* p = st.top();
            res.push_back(p->val);
            st.pop();

            if(p->left) st.push(p->left);
            if(p->right) st.push(p->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

