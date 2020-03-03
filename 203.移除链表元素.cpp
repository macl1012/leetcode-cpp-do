/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        // 递归实现
        // if(!head) return head;

        // head->next = removeElements(head->next, val);
        // return (head->val == val) ? head->next : head;
        
        // 迭代实现
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;

        while(cur->next) {
            if(cur->next->val == val) {
                cur->next = cur->next->next;
            }
            else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

