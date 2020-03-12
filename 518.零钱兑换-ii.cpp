/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
    // 状态： 总金额amount
    // dp(n)：表示总金额为n，共有多少种硬币组合数。
    // 在coins中，拿出一个coin，则dp(n)=sum(dp(n-coin)), coin 属于coins
    // base case:dp(0)=0 
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1; 
        for(auto coin : coins) {
            for(int i=coin; i<=amount; i++) {
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

