/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    // 递归实现
    // vector<int> inorderTraversal(TreeNode* root) {
    //     traverse(root);
    //     return res;
    // }

    // void traverse(TreeNode* root) {
    //     if(!root) return;

    //     traverse(root->left);
    //     if(root) res.push_back(root->val);
    //     traverse(root->right);
    // }
    // private:
    //     vector<int> res;

    // 迭代算法
    // 思路：当前节点有左子节点时，将当前节点压栈，并将左子节点设为当前节点；
    // 当前节点没有左子节点时，表示左子树已经遍历完，此时访问弹出当前节点，然后
    // 将右子节点设为当前节点。
    vector<int> inorderTraversal(TreeNode* root) {
        // 左子树-根-右子树
        vector<int> res;
        if(!root) return res;
        
        TreeNode* p = root;
        stack<TreeNode*> st;
        while(p || !st.empty()) {
            if(p) {
                st.push(p);
                p = p->left;
            } else {
                p = st.top();
                res.push_back(p->val);
                st.pop();
                p = p->right;
            }
        }
        return res;
    }
};
// @lc code=end

