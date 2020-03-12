/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // 采用滑动窗口框架思想
        int left = 0, right = 0;
        vector<int> res; // 起始索引，结果

        // 两个计数器
        unordered_map<char, int> needs;
        unordered_map<char, int> window;
        for(char c : p) needs[c]++;

        // 记录已经有多少个字符匹配了
        int match = 0;

        while(right < s.size()) {
            // window.add(s[right]);
            char c1 = s[right];
            if(needs.count(c1)) {
                window[c1]++;
                if(window[c1] == needs[c1])
                    match++;
            }
            right ++;

            while(match == needs.size()) {
                // 更新res
                if(right - left == p.size())
                    res.push_back(left);

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
        return res;
    }
};
// @lc code=end

