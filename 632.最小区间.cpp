/*
 * @lc app=leetcode.cn id=632 lang=cpp
 *
 * [632] 最小区间
 */

// @lc code=start

class Node {
public:
    int index;
    int value;
    Node(int id, int val) {
        index = id;
        value = val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // K个整数数组合并到一个数组中
        const int k = nums.size();

        vector<Node> all;
        for(int i=0; i<k; i++) {
            auto& knum = nums[i];
            for(auto num : knum)
                all.push_back(Node(i, num));
        }            
        
        // 对数组按照值排序
        sort(all.begin(), all.end(), [](const Node& l, const Node& r) {
            return l.value < r.value;
        });

        // 按照双指针+滑动窗口框架思想
        int start = 0, end = all.size()-1;
        int left = 0, right = 0;
        vector<int> window(k, 0);
        int match = 0;

        while(right < all.size()) {
            Node n1 = all[right];
            window[n1.index]++;
            if(window[n1.index] == 1)
                match++;
            right++;

            while(match == k) {
                //更新: right前面++了，应该取前面的
                if(n1.value - all[left].value < all[end].value - all[start].value) {
                    end = right-1;
                    start = left;
                }

                Node n2 = all[left];
                window[n2.index]--;
                if(window[n2.index] < 1)
                    match--;
                left++;
            }
        }

        return { all[start].value, all[end].value };
        
    }
};
// @lc code=end

