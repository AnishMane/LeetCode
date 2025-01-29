/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int m = 0;
        while(cur)
        {
            m++;
            cur = cur->next;
        }
        cur = head;
        ListNode* prev = NULL;
        int point = m-n+1;
        while(point>1)
        {
            point--;    
            prev = cur;
            cur = cur->next;
        }
        if(cur == head)
        {
            head = head->next;
            return head;
        }
        prev->next = cur->next;
        delete cur;
        cur = prev->next;
        return head;
    }
};