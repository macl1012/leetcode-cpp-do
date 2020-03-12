/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    // G(n)：整数n，可以构造多少种BST
    // F(i,n)：i为根，可以构造多少种BST，1<=i<=n
    // G(n) = F(1,n) + F(2, n) + ... + F(n,n)
    // F(i,n) = G(i-1) * G(n-i)
    // G(n) = sum(G(i-1) * G(n-i)), i>=1 && i<=n
    // base case: G[0] = 1, G[1] = 1
    // 

    // int numTrees(int n) {
    //     if(n==0 || n==1) return 1;

    //     vector<int> G(n+1, 0);
    //     G[0] = 1;
    //     G[1] = 1;

    //     for(int i=2; i<=n; i++) { // 控制计算每个G[i]，直到G[n]
    //         for(int j=1; j<=i; j++) { // [1,i]
    //             G[i] += G[j-1] * G[i-j];
    //         }
    //     }
    //     return G[n];
    // }

    // G(n)：整数n，可以构造多少种BST
    // 卡塔兰数：
    // G(0) = 1, G(n+1) = 2(2n+1)/(n+2)G(n)
    int numTrees(int n) {
        long G = 1;
        for(int i=0; i<n; i++) {
            G = G*2*(2*i+1)/(i+2);
        }
        return (int)G;
    }
};
// @lc code=end

