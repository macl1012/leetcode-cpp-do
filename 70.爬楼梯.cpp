/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    // dp[0] = 1, dp[1] = 1
    // dp[n] = dp[n-1] + dp[n-2]
    // int climbStairs(int n) {
    //     vector<int> dp(n+1, 0);
    //     dp[0] = 1; dp[1] = 1;
    //     for(int i=2; i<=n; i++) {
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }

    int climbStairs(int n) {
        if(n<2) return 1;
        int pre2 = 1, pre = 1;
        int cur = 0;
        for(int i=2; i<=n; i++) {
            cur = pre + pre2;
            pre2 = pre;
            pre = cur;
        }
        return cur;
    }
};
// @lc code=end

