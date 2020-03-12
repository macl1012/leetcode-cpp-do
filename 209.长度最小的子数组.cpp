/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 * 
 * 算法

初始化 left 指向 0 且初始化 sum 为 0
遍历 nums 数组：
    将 nums[i] 添加到 sum
    当 sum 大于等于 ss 时：
        更新 ans=min(ans,i+1−left) ，其中 i+1−left是当前子数组的长度
        然后我们可以移动左端点，因为以它为开头的满足 sum≥s 条件的最短子数组已经求出来了
        将 sum 减去 nums[left] 然后增加 left
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // if(nums.size() == 0) return 0;
        // if(nums.size() == 1 && nums[0] < s) return 0;

        // int sum = 0;
        // int minSub = INT_MAX;
        // int left = 0;
        // for(int i=0; i<nums.size(); ++i) {
        //     sum += nums[i];
        //     while(sum >= s) {
        //         minSub = min(minSub, i-left+1);
        //         sum -= nums[left];
        //         left ++;
        //     }
        // }
        // return minSub==INT_MAX ? 0 : minSub;


        // 重新按照滑动窗口框架思想
        if(nums.size() == 0) return 0;

        int sum = 0, minLen = INT_MAX;
        int left = 0, right = 0;
        while(right < nums.size()) {
            // add
            sum += nums[right];
            right++;

            while(sum >= s) {
                // 更新
                minLen = min(minLen, right-left);

                // remove
                sum -= nums[left];
                left++;
            }
        }
        return minLen==INT_MAX ? 0 : minLen;
    }
};
// @lc code=end

