/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        // 方法1：哈希
        

        // 方法2：快慢指针
        // 快指针每次走两步，慢指针每次走1步，如果没有环，
        // 则快指针先到链表尾，如果有环，则快指针会追上慢指针
        // if(!head || !head->next)
        //     return false;

        // ListNode *fast = head->next, *slow = head;
        // while(fast != slow) {
        //     if(!fast || !fast->next)
        //         return false;
        //     slow = slow->next;
        //     fast = fast->next->next; 
        // }
        // return true;
    }
};
// @lc code=end

