/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        // 前序遍历：根-左子树-右子树
        // 后序遍历：左子树-右子树-根
        unordered_map<int, int> postMap;
        for(int i=0; i<post.size(); i++) 
            postMap[post[i]] = i;
        return buildTree(pre, 0, pre.size()-1, 
                        post, 0, post.size()-1, postMap);
    }

    TreeNode* buildTree(vector<int>& pre, int preStart, int preEnd, 
                        vector<int>& post, int postStart, int postEnd, 
                        unordered_map<int, int>& postMap) {
        if(preStart > preEnd || postStart > postEnd) return nullptr;
        if(preStart == preEnd) return new TreeNode(pre[preStart]);
        if(postStart == postEnd) return new TreeNode(post[postEnd]);

        TreeNode* root = new TreeNode(pre[preStart]);
        int postLeft = postMap[pre[preStart+1]];
        int lenLeft = postLeft - postStart + 1;

        root->left = buildTree(pre, preStart+1, preStart+lenLeft, 
                                post, postStart, postLeft, postMap);
        root->right = buildTree(pre, preStart+lenLeft+1, preEnd, 
                                post, postLeft+1, postEnd-1, postMap);
        return root;
    }
};
// @lc code=end

