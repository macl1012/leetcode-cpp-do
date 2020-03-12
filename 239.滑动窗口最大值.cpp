/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
// 单调队列
// 单调队列的 push 方法依然在队尾添加元素，但是要把前面比新元素小的元素都删掉
class MonotonicQueue {
private:
    deque<int> data;
    
public:
    // 队尾添加元素，队尾往前比新元素小的元素都删除
    void push(int n) {
        while(!data.empty() && data.back() < n)
            data.pop_back();
        data.push_back(n);
    }

    // 队首就是最大值 
    int max() {
        return data.front();
    }

    // 队首如果是n，则删除
    void pop(int n) {
        if(!data.empty() && data.front() == n)
            data.pop_front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 采用单调队列+滑动窗口思想
        MonotonicQueue window;
        vector<int> res; // 结果

        int left = 0, right = 0;
        while(right < nums.size()) {
            window.push(nums[right]);
            right++;

            if(right - left == k) {
                res.push_back(window.max());

                window.pop(nums[left]);
                left++;
            }
        }
        return res;
    }
};
// @lc code=end

