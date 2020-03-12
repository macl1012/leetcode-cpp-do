/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    // nums: [10,9,2,5,3,7,101,18]
    // dp:   [1, 1,1,2,2,3,4,  4]
    // dp[i]: 到nums[i]处得到的最长上升子序列的长度
    // 找到dp[i]中最大值 
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i=1; i<nums.size(); i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        int res = 0;
        for(auto i : dp) {
            res = max(res, i);
        }
        return res;
    }
};
// @lc code=end

