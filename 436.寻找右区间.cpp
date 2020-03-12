/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // 1. 暴力解法 时间复杂度O(n^2)
        // 0个或一个区间，返回-1
        int len = intervals.size();
        if(len <= 1) return {-1};

        vector<int> res(len, -1);
        for(int i=0; i<len; i++) {
            vector<int> interval = intervals[i];
            for(int j=i+1; j<len; j++) {
                vector<int> rightInterval = intervals[j];
                if(rightInterval[0] >= interval[1]) {
                    if(res[i] == -1) {
                        res[i] = j;
                    } else {
                        if(intervals[res[i]][0] > intervals[j][0] )
                            res[i] = j;
                    }
                } else if(interval[0] >= rightInterval[1]) {
                    if(res[j] == -1) {
                        res[j] = i;
                    } else {
                        if(intervals[res[j]][0] > intervals[i][0])
                            res[j] = i;
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

