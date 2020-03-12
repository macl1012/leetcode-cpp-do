/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // 采用滑动窗口框架思想
        int left = 0, right = 0;
        int start = 0, minLen = INT_MAX; // 记录最短子串的开始位置和长度

        unordered_map<char, int> needs;
        unordered_map<char, int> window;
        for(char c : t) needs[c]++;
        
        int match = 0;

        while(right < s.size()) {
            //window.add(s[right]);
            char c1 = s[right];
            if(needs.count(c1)) {
                window[c1]++;
                if(needs[c1] == window[c1])
                    match++;
            }
            right++;

            while(match == needs.size()) {
                // 更新res
                if(right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }

                //window.remove(s[left]);
                char c2 = s[left];
                if(needs.count(c2)) {
                    window[c2]--;
                    if(window[c2] < needs[c2])
                        match--;
                }
                left++;
            }
        }
        return minLen==INT_MAX ? "" : s.substr(start, minLen);
    }
};
// @lc code=end

