/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    // 思路：BST前序遍历，结果保存到res数组中，每添加一个数，判断数组中是否存在值：目标结果-当前数
//     bool findTarget(TreeNode* root, int k) {
//         vector<int> res;
//         preorder(root, res, k);
//         return bFind;
//     }

// private:
//     bool bFind = false;
//     void preorder(TreeNode* root, vector<int>& res, int k) {
//         if(!root) return;
//         if(bFind) return;
//         if(find(res.begin(), res.end(), k - root->val) != res.end()) {
//             bFind = true;
//             return;
//         }
//         res.push_back(root->val);
//         preorder(root->left, res, k);
//         preorder(root->right, res, k);
//     }

//     使用unordered_set，减小查找的时间复杂度为O(1)
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> res;
        preorder(root, res, k);
        return bFind;
    }

private:
    bool bFind = false;
    void preorder(TreeNode* root, unordered_set<int>& res, int k) {
        if(!root) return;
        if(bFind) return;
        if(res.count(k - root->val)) {
            bFind = true;
            return;
        }
        res.insert(root->val);
        preorder(root->left, res, k);
        preorder(root->right, res, k);
    }

//     使用unordered_map，减小查找的时间复杂度为O(1)
//     bool findTarget(TreeNode* root, int k) {
//         unordered_map<int, int> res;
//         preorder(root, res, k);
//         return bFind;
//     }
// private:
//     bool bFind = false;
//     void preorder(TreeNode* root, unordered_map<int, int>& res, int k) {
//         if(!root) return;
//         if(bFind) return;
//         if(res.count(k - root->val)) {
//             bFind = true;
//             return;
//         }
//         res[root->val]++;
//         preorder(root->left, res, k);
//         preorder(root->right, res, k);
//     }
};
// @lc code=end

