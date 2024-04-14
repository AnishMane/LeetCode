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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode* forward = head->next;
        ListNode* cur = head;
        while(forward)
        {
            int temp = cur->val;
            cur->val = forward->val;
            forward->val = temp;
            if(forward->next && forward->next->next)
            {
                forward = forward->next->next;
            }
            else
            {
                forward = NULL;
            }
            
            if(cur->next && cur->next->next)
            {
                cur = cur->next->next;
            }             
            else
            {
                break;
            }
        }
        return head;
    }
};