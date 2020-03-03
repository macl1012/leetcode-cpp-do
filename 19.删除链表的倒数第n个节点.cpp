/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 一次扫描实现
        ListNode *pre = head, *cur = head;
        for(int i=0; i<n; ++i) {
            cur = cur->next;
        }
        // 如果n为链表长度，则倒数第n个节点为头节点元素
        if(!cur) {
            ListNode *t = head;
            head = head->next;
            t->next = NULL;
            delete t;
            t = NULL;
            return head;
        }

        // 使用cur->next目的是获取到倒数第n+1个元素
        while(cur->next) {
            cur = cur->next;
            pre = pre->next;
        }
        // 当前pre指向倒数第n+1个元素，删除后面的元素
        ListNode *t = pre->next;
        pre->next = pre->next->next;
        t->next = NULL;
        delete t;
        t = NULL;
        return head;
    }
};
// @lc code=end

