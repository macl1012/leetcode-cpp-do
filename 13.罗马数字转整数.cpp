/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        // unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"V", 5}, {"IX", 8}, {"X", 10},  {"XL", 30}, {"L", 50}, {"XC", 80}, {"C", 100}, {"CD", 300}, {"D", 500}, {"CM", 800}, {"M", 1000}};
        // int r = m[s.substr(0, 1)];
        // for(int i=1; i<s.size(); i++) {
        //     string two = s.substr(i-1, 2);
        //     string one = s.substr(i, 1);
        //     r += (m[two] ? m[two] : m[one]);
        // }
        // return r;

        unordered_map<string, int> m = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10},  {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
        int r = 0;
        for(int i=0; i<s.size(); i++) {
            string two = s.substr(i, 2);
            string one = s.substr(i, 1);
            r += (m[two] ? m[two] : m[one]);
            if(m[two]) i++;
        }
        return r;
    }
};
// @lc code=end

