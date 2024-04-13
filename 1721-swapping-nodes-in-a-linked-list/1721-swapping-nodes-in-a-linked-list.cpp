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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* cur = head;
        int back = 0;
        
        while(cur)
        {
            back++;
            cur = cur->next;
        }
        int point = back-k+1;
        ListNode* A = head;
        ListNode* B = head;
        while(point > 1)
        {
            B = B->next;
            point--;
        }
        while(k>1)
        {
            k--;
            A = A->next;
        }
        int temp = A->val;
        A->val = B->val;
        B->val = temp;
        return head;
    }
};