/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // 采用滑动窗口的框架思想
        if(words.size() == 0) return {};

        int lenWord = words[0].length();
        int lenWords = lenWord * words.size();
        if(lenWord == 0 || lenWords > s.size()) return {};

        vector<int> res; // 起始位置索引

        unordered_map<string, int> needs;
        unordered_map<string, int> window;
        for(string str : words) needs[str]++;

        for(int i=0; i<lenWord; i++) {
            int left = i, right = i;
            int match = 0;
            window.clear();

            while(right < s.size()) {
                string s1 = s.substr(right, lenWord);
                if(needs.count(s1)) {
                    window[s1]++;
                    if(needs[s1] == window[s1])
                        match++;
                }
                right += lenWord;

                while(match == needs.size()) {
                    if(right - left == lenWords)
                        res.push_back(left);
                    
                    string s2 = s.substr(left, lenWord);
                    if(needs.count(s2)) {
                        window[s2]--;
                        if(window[s2] < needs[s2])
                            match--;
                    }
                    left += lenWord;
                }
            }
        }

        return res;
    }
};
// @lc code=end

