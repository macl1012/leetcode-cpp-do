/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    // 递归框架
    // base case: i走完s1或者j走完s2，返回另外一个字符串剩下的长度
    // 对于每对字符比较：
    // if s1[i] == s2[j]
    //    skip
    //    i,j同时往前走
    // else
    //  三选一   min
    //    插入操作：
    //    删除操作
    //    替换操作
    // 
    // dp(i, j)：s1[0..i]和s2[0..j]的最小编辑距离
    // if s1[i] == s2[j]
    //    return dp(i-1, j-1)
    // else
    //    return min(
    //        dp(i, j-1), // 插入字符，i还未处理，j已处理，前移
    //        dp(i-1, j), // 删除字符，i处理完，前移，j还未处理    
    //        dp(i-1, j-1) // 替换字符，i和j都处理完，前移
    //    )
    // vector<vector<int>> memo;
    // int minDistance(string word1, string word2) {
    //     memo = vector<vector<int>>(word1.size(), vector<int>(word2.size(), 0));
    //     return dp(word1, word2, word1.length()-1, word2.length()-1);
    // }

    // int dp(string s1, string s2, int i, int j) {
    //     // base case
    //     if(i == -1) return j+1;
    //     if(j == -1) return i+1;

    //     if(memo[i][j] > 0)
    //         return memo[i][j];
        
    //     if(s1[i] == s2[j])
    //         memo[i][j] = dp(s1, s2, i-1, j-1);
    //     else
    //         memo[i][j] = min3(
    //             dp(s1, s2, i, j-1) + 1, // 插入
    //             dp(s1, s2, i-1, j) + 1, // 删除
    //             dp(s1, s2, i-1, j-1) + 1 // 替换
    //         );
    //     return memo[i][j];
    // }

    // int min3(int a, int b, int c) {
    //     return min(a, min(b, c));
    // }

    // 动态规划DPTable
    // dp[i-1][j-1]   dp[i-1][j]
    // dp[i][j-1]    dp[i][j]
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // base case
        for(int i=1; i<=m; i++)
            dp[i][0] = i;
        for(int i=1; i<=n; i++)
            dp[0][i] = i;
        // 自底向上求解
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min3(dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]+1);
                }
            }
        }
        return dp[m][n];
    }

    int min3(int a, int b, int c) {
        return min(a, min(b, c));
    }
};
// @lc code=end

