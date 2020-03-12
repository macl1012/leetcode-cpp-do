/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
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
    // vector<int> postorder(Node* root) {
    //     vector<int> res;
    //     traverse(root, res);
    //     return res;
    // }

    // void traverse(Node* root, vector<int>& res) {
    //     if(!root) return;
    //     for(auto child : root->children)
    //         traverse(child, res);
    //     res.push_back(root->val);
    // }

    // 迭代实现
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(!root) return res;

        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node* p = st.top();
            res.push_back(p->val);
            st.pop();

            for(auto child : p->children) {
                st.push(child);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

