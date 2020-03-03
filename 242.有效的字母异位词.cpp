/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 * 
 * 有效的字母异位词：每个字母出现个数相同
 * 边界：
 * "" 和 "" 是
 * "a"和"a" 是
 * 排序前相同 是
 * 排序后相同 是
 * 
 * 方法1：直接sort排序-排序后相同
 * 方法2：计数-长度相同，26个字母，s出现字母+1，t字母出现-1，
 *      s和t是字母异位词，即每个字母出现的次数相同，则所有字母计数为0
 * 
 * 总结：
 * 关键是弄清楚什么是有效的字母异位词，自然会想到两个方法，后者更加高效，O(n)完成
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {

        // 方法1：直接sort排序
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // if(s == t)
        //     return true;
        // return false;


        // 方法2：计数
        if(s.length() != t.length())
            return false;

        int num[26] = {0};
        for(int i=0; i<s.length(); ++i) {
            ++num[s[i] - 'a'];
            --num[t[i] - 'a'];
        }

        for(int i=0; i<26; ++i) {
            if(num[i] != 0)
            return false;
        }
        return true;
    }
};
// @lc code=end

yiweici