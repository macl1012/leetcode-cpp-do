/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 前序遍历：根 左子树 右子树
        // 中序遍历：左子树 根 右子树
        if(preorder.size() == 0 || inorder.size() == 0) return nullptr;
        
        unordered_map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++) 
            inMap[inorder[i]] = i;

        return buildTree(preorder, 0, preorder.size()-1,
                        inorder, 0, inorder.size()-1, inMap);
    }

    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
                        vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        int leftTree = inRoot - inStart; // 左子树元素数
        root->left = buildTree(preorder, preStart+1, preStart+leftTree,
                                inorder, inStart, inRoot-1, inMap);
        root->right = buildTree(preorder, preStart+leftTree+1, preEnd,
                                inorder, inRoot+1, inEnd, inMap);
        return root;
    }
};
// @lc code=end

