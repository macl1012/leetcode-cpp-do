/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, track);
        return res;
    }

    // 路径：记录在track中
    // 选择列表：nums中不在track中出现的元素
    // 结束条件：nums元素全部出现在track中（track长度==nums长度）
    void backtrack(vector<int>& nums, vector<int>& track) {
        // 触发结束条件
        if(track.size() == nums.size()) {
            res.push_back(track);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            // 排除不合法的选择
            if(find(track.begin(), track.end(), nums[i]) != track.end())
                continue;
            // 做选择：添加选择到路径中
            track.push_back(nums[i]);
            // 进入下一层决策树
            backtrack(nums, track);
            // 撤销选择: 将选择从路径中删除
            track.pop_back();
        }
    }

private:
    vector<vector<int>> res;
};
// @lc code=end

