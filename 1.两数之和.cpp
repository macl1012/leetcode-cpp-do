/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map<int, int> m;
        // for(int i=0; i<nums.size(); i++) 
        //     m[nums[i]] = i;
        
        // for(int i=0; i<nums.size(); i++) {
        //     int temp = target - nums[i];
        //     if(m.count(temp) && m[temp] != i) 
        //         return {i, m[temp]};
        // }
        // return {-1, -1};

        map<int, int> m;
        for(int i=0; i<nums.size(); i++) {
            int temp = target - nums[i];
            if(m.count(temp)) {
                return {m[temp], i};
            }
            m[nums[i]] = i;
        }
        return {-1, -1};
    }
};
// @lc code=end

