/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 第一版
        // ListNode *p1 = l1, *p2 = l2;
        // bool bCarry = false;
        // ListNode *dummy = new ListNode(0);
        // ListNode *cur = dummy;
        // while(p1 || p2) {
        //     int val = (bCarry ? 1 : 0);
        //     if(p1) val += p1->val;
        //     if(p2) val += p2->val;
        //     bCarry = (val >= 10) ? true : false;
            
        //     ListNode *t = new ListNode(val % 10);
        //     cur->next = t;
        //     // 更新指针
        //     if(p1) p1 = p1->next;
        //     if(p2) p2 = p2->next;
        //     cur = cur->next;
        // }
       
        // // 最高位有进位
        // if(bCarry) {
        //     ListNode *t = new ListNode(1);
        //     cur->next = t;
        //     // 更新指针
        //     cur = cur->next;
        // }
        // return dummy->next;

        // 代码改进后
        bool bCarry = false;
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(l1 || l2) {
            int val = (bCarry ? 1 : 0);
            if(l1) val += l1->val;
            if(l2) val += l2->val;
            bCarry = (val >= 10) ? true : false;
            
            cur->next = new ListNode(val % 10);;
            // 更新指针
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            cur = cur->next;
        }
       
        // 最高位有进位
        if(bCarry) {
            cur->next = new ListNode(1);
        }
        return dummy->next;
    }
};
// @lc code=end

