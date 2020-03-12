/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 中序遍历：左子树 根 右子树
        // 后序遍历：左子树 右子树 根
        if(inorder.size() == 0 || postorder.size() == 0)
            return nullptr;
        
        unordered_map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++)
            inMap[inorder[i]] = i;
        
        return buildTree(inorder, 0, inorder.size()-1, inMap,
                        postorder, 0, postorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap,
                        vector<int>& postorder, int postStart, int postEnd) {
        if(inStart > inEnd || postStart > postEnd) return nullptr;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[root->val];
        int leftTree = inRoot - inStart;
        root->left = buildTree(inorder, inStart, inRoot-1, inMap, 
                                postorder, postStart, postStart+leftTree-1);
        root->right = buildTree(inorder, inRoot+1, inEnd, inMap,
                                postorder, postStart+leftTree, postEnd-1);
        return root;
    }
};
// @lc code=end

