/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // 采用滑动窗口框架思想
        int left = 0, right = 0;
        unordered_map<char, int> needs;
        unordered_map<char, int> window;
        for(char c : s1) needs[c]++;

        int match = 0;
        
        while(right < s2.size()) {
            //window.add(s2[right]);
            char c1 = s2[right];
            if(needs.count(c1)) {
                window[c1]++;
                if(window[c1] == needs[c1])
                    match++;
            }
            right++;

            while(match == needs.size()) {
                // 更新res
                if(right - left == s1.size()) {
                    return true;
                }
                //window.remove(s2[left]);
                char c2 = s2[left];
                if(needs.count(c2)) {
                    window[c2]--;
                    if(window[c2] < needs[c2])
                        match--;
                }
                left++;
            }
        }
        return false;
    }
};
// @lc code=end

