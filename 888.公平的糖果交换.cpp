/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */

// @lc code=start
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sa = 0;
        int sb = 0;
        for(int i=0; i<A.size(); i++)
            sa += A[i];
        for(int i=0; i<B.size(); i++)
            sb += B[i];
        
        int delta = (sb - sa) / 2;
        
        unordered_set<int> setB;
        for(int i=0; i<B.size(); i++)
            setB.insert(B[i]);

        for(int i=0; i<A.size(); i++) {
            if(setB.find(A[i] + delta) != setB.end()) {
                return {A[i], A[i] + delta};
            }
        }
        return {};
    }
};
// @lc code=end

