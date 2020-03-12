/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    // 递归算法
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     traverse(root, res);
    //     return res;
    // }

    // void traverse(TreeNode* root, vector<int>& res) {
    //     if(!root) return;
    //     res.push_back(root->val);
    //     traverse(root->left, res);
    //     traverse(root->right, res);
    // }

    // 迭代算法
    // 思路：先将根压栈，然后循环：访问当前节点，先后将右子树和左子树放入栈中，利用栈后入先出的原理遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* p = st.top();
            res.push_back(p->val);
            st.pop();
        
            if(p->right) st.push(p->right);
            if(p->left) st.push(p->left);
        }
        return res;
    }
};
// @lc code=end

