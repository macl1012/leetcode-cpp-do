/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 
 * 方案1：头插法：每个区间，依次把head的每个元素移动到头部
 * 过程如下：
 * cur
 * pre
 * dummy 1   2   3   4   5 
 * pre
 * dummy 1   2   3   4   5
 *      cur  t
 * pre
 * dummy 2   1   3   4   5
 *       t  cur
 * pre
 * dummy 2   1   3   4   5
 *          cur  t
 * pre
 * dummy 3   2   1   4   5
 *       t      cur
 *              pre
 * dummy 3   2   1   4   5
 *              cur  t         
 * 
 * 方案2：递归法：
 * 区间k个元素进行元素反转
 * 不足k个元素，保持不变
 * k=3:    a              b
 * NULL -> 1 -> 2 -> 3 -> 4 -> 5
 * pre   cur
 *      next  
 * NULL <- 1 -> 2 -> 3 -> 4 -> 5
 *       pre  next
 *            cur
 * NULL <- 1 <- 2 -> 3 -> 4 -> 5
 *             pre  next
 *                  cur
 * NULL <- 1 <- 2 <- 3 -> 4 -> 5
 *                  pre  next
 *                       cur
 *         a       newHead
 */
class Solution {
public:
    // 1. 头插法
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     ListNode *dummy = new ListNode(-1);
    //     ListNode *pre = dummy, *cur = pre; 
    //     dummy->next = head;

    //     // 计算链表的长度
    //     int num = 0;
    //     while(cur = cur->next) ++num;

    //     while(num >= k) {
    //         cur = pre->next;
    //         // 依次将t移动到pre后
    //         for(int i=1; i<k; ++i) {
    //             ListNode *t = cur->next;
    //             cur->next = t->next;
    //             t->next = pre->next;
    //             pre->next = t;
    //         }
    //         pre = cur;
    //         num -= k;
    //     }
    //     return dummy->next;
    // }

    // 2.递归法
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        // 区间[a,b)包含k个待反转元素
        ListNode *a = head, *b = a;
        for(int i=0; i<k; ++i) {
            // 不足k个元素，保持不变
            if(!b) return head;
            b = b->next;
        }
        // 反转前k个元素
        ListNode *newHead = reverse(a, b);
        // 递归反转后续链表并连接起来
        a->next = reverseKGroup(b, k);
        return newHead;
    }
private:
    // 区间[a,b)元素反转，注意是左闭右开
    ListNode* reverse(ListNode* a, ListNode* b) {
        ListNode *pre = NULL, *cur = a, *next = a;
        while(cur != b) {
            // 逐个反转
            next = cur->next;
            cur->next = pre;
            // 更新指针位置
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
// @lc code=end
