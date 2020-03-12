/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;

        bool bHasCycle = false;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                bHasCycle = true;
                break;
            }   
        }
        if(!bHasCycle) return NULL;

        slow = head;
        while(slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end

