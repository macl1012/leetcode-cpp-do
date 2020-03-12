/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 先序遍历构造二叉树
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // 先序遍历：根-左子树-右子树
        // 左子树的value都小于根value，右子树的value都大于根value
        return buildTree(preorder, 0, preorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& preorder, int inStart, int inEnd) {
        if(inStart > inEnd || inStart >= preorder.size()) return nullptr;

        TreeNode* root = new TreeNode(preorder[inStart]);
        int lenLeft = 1;
        while(inStart + lenLeft < preorder.size() && 
            preorder[inStart + lenLeft] < preorder[inStart]) {
            lenLeft++;
        }
        
        root->left = buildTree(preorder, inStart+1, inStart+lenLeft-1);
        root->right = buildTree(preorder, inStart+lenLeft, inEnd);
        return root;
    }
};
// @lc code=end

