/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        // 方法1：迭代实现
        // ListNode *prev = NULL;
        // ListNode *curr = head, *next = curr;
        // while(curr) {
        //     next = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = next;
        // }
        // return prev;

        // 方法2：递归实现
        if(!head || !head->next)
            return head;
        
        ListNode* newHead = reverseList(head->next);
        // 反转连接
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};
// @lc code=end

