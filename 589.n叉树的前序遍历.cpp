/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    // 递归实现
    // vector<int> preorder(Node* root) {
    //     vector<int> res;
    //     traverse(root, res);
    //     return res;
    // }

    // void traverse(Node* root, vector<int>& res) {
    //     if(!root) return;
    //     res.push_back(root->val);
    //     for(Node* child : root->children) {
    //         traverse(child, res);
    //     }
    // }

    // 迭代实现
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root) return res;

        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node* p = st.top();
            res.push_back(p->val);
            st.pop();

            for(auto it = p->children.rbegin(); it!=p->children.rend(); it++) {
                st.push(*it);
            }
        }
        return res;
    }
};
// @lc code=end

