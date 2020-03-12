/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    // 1, 暴力递归
    // 子问题个数：O(2^N)
    // 每个子问题耗时：O(1)
    // 时间复杂度：O(2^N)
    // int fib(int N) {
    //     if(N == 0) return 0;
    //     if(N == 1 || N == 2) return 1;
    //     return fib(N-1) + fib(N-2);
    // }

    // 2. 带备忘录的递归求解
    // 子问题个数：O(N)
    // 时间复杂度：O(N)
    // int helper(vector<int>& memo, int N) {
    //     if(N == 1 || N == 2) return 1;
    //     if(memo[N] != 0) return memo[N];
    //     memo[N] = helper(memo, N-1) + helper(memo, N-2);
    //     return memo[N]; 
    // }

    // int fib(int N) {
    //     if(N == 0) return 0;
    //     vector<int> memo(N+1, 0);
    //     return helper(memo, N);
    // }

    // 3. 使用dp数组的迭代解法 时间复杂度：O(N)
    // int fib(int N) {
    //     if(N == 0) return 0;
    //     if(N == 1 || N == 2) return 1;
    //     vector<int> dp(N+1, 0);
    //     dp[1] = dp[2] = 1;
    //     for(int i=3; i<=N; i++) {
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[N];
    // }

    // 4. 优化空间复杂度：每次只存储前两个状态
    // 时间复杂度：O(N)，空间复杂度：O(1)
    int fib(int N) {
        if(N == 0) return 0;
        if(N == 1 || N == 2) return 1;
        int prev = 1, curr = 1;
        for(int i=3; i<=N; i++) {
            int sum = prev + curr;
            prev = curr;
            curr = sum;
        }
        return curr;
    }
};
// @lc code=end

