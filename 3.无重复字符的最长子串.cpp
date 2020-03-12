/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int maxLength = 1;
        // string sub = s.substr(0,1);
        // auto it = s.begin() +1;
        // while(it != s.end()) {
        //     string::size_type pos = sub.find(*it);
        //     if(pos == string::npos) { // 没有重复，添加字符
        //         sub += *it;
        //         if(sub.length() > maxLength)
        //             maxLength = sub.length();
        //         ++it;
        //     } else { // 出现重复，调整sub为从pos+1开始
        //         //sub = sub.substr(pos+1);
        //         sub.erase(0, pos);
        //     }
        // }
        // return maxLength;

        // if(s.size() == 0) return 0;
        // unordered_set<char> lookup;
        // int left = 0;
        // int maxStr = 0;
        // for(int i=0; i<s.size(); ++i) {
        //     while(lookup.find(s[i]) != lookup.end()){
        //         // 找到重复出现的，移动窗口
        //         lookup.erase(s[left]);
        //         left ++;
        //     }
        //     maxStr = max(maxStr, i-left+1);
        //     lookup.insert(s[i]);
        // }
        // return maxStr;


        // 使用滑动窗口框架思想
        int left = 0, right = 0;
        int res = 0; // 长度
        unordered_map<char, int> window;

        while(right < s.size()) {
            // window.add(s[right]);
            char c1 = s[right];
            window[c1]++;
            right++;

            while(window[c1] > 1) {
                // window.remove(s[left]);
                char c2 = s[left];
                window[c2]--;
                left++;
            }

            res = max(res, right-left);
        }
        return res;
    }
};
// @lc code=end

