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
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode* current = head;
        while(current != NULL)
        {
            n++;
            current = current->next;
        }
        current = head;
        
        int mid = n/2;
        for(int i=0; i<mid;i++)
        {
            current = current->next;
        }
        return current;
    }
};