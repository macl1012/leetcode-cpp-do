/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    // 1. 暴力递归穷举
    // 确定状态：总金额
    // 确定dp函数的定义：给定一个总金额n，至少需要dp(n)个硬币凑出总金额
    // 确定选择并择优：从coins中选择一个硬币，总金额就会减少。dp[n] = min{1 + dp(n-coin)|coin 属于coins}, n>0
    // base case: n=0,return 0, n<0, return -1
    // 时间复杂度：子问题个数：递归树节点个数O(n^k)  *  每个问题耗时：O(k) ===> O(k*n^k)

    // int coinChange(vector<int>& coins, int amount) {
    //     return dp(coins, amount);
    // }

    // int dp(vector<int>& coins, int n) {
    //     if(n < 0) return -1;
    //     if(n == 0) return 0;
    //     int res = INT_MAX;
    //     for(auto coin : coins) {
    //         int subproblem = dp(coins, n - coin);
    //         if(subproblem == -1) continue;
    //         res = min(res, 1 + subproblem);
    //     }
    //     return res == INT_MAX ? -1 : res;
    // }

    // 2. 带备忘录的递归解法
    // 时间复杂度：O(n) * O(k) ===> O(k*n)
    // int coinChange(vector<int>& coins, int amount) {
    //     unordered_map<int, int> memo;
    //     return dp(coins, amount, memo);
    // }

    // int dp(vector<int>& coins, int n, unordered_map<int, int>& memo) {
    //     if(memo.count(n)) return memo[n];
         
    //     if(n == 0) return 0;
    //     if(n < 0) return -1;
        
    //     int res = INT_MAX;
    //     for(auto coin : coins) {
    //         int subproblem = dp(coins, n - coin, memo);
    //         if(subproblem == -1) continue;
    //         res = min(res, 1 + subproblem);
    //     }
    //     memo[n] = (res == INT_MAX ? -1 : res);
    //     return memo[n];
    // }

    // 3. 使用dp数组的迭代解法
    // 时间复杂度：O(k*n)
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(amount < 0) return -1;

        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i=0; i<=amount; i++) {
            for(auto coin : coins) {
                if(i-coin < 0) continue;
                dp[i] = min(dp[i], 1 + dp[i-coin]);
            }
        }
        return (dp[amount] == amount+1) ? -1 : dp[amount];
    }
};
// @lc code=end

