/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    // 5进来，m[5]++
    // 10进来，m[5]>=1 ? m[10]++, m[5]-- : false
    // 20进来，m[10]>=1 && m[5]>=1 ? m[20]++, m[10]--, m[5]-- : (m[5] >= 3 ? m[20]++, m[5]-=3 : false)
    // bool lemonadeChange(vector<int>& bills) {
    //     unordered_map<int, int> m;
    //     for(auto bill : bills) {
    //         if(bill == 5) {
    //             m[5]++;
    //         } else if(bill == 10) {
    //             if(m[5]>=1) {
    //                 m[10]++; m[5]--;
    //             } else {
    //                 return false;
    //             }
    //         } else if(bill == 20) {
    //             if(m[10]>=1 && m[5]>=1) {
    //                 m[20]++; m[10]--; m[5]--;
    //             } else if(m[5] >= 3) {
    //                 m[20]++; m[5]-=3;
    //             } else {
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(auto bill : bills) {
            if(bill == 5) {
                five++;
            } else if(bill == 10) {
                if(five==0)
                    return false;
                ten++; five--;
            } else if(bill == 20) {
                if(ten>=1 && five>=1) {
                    ten--; five--;
                } else if(five >= 3) {
                    five-=3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

