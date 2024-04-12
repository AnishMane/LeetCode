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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,bool> table;
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr!=NULL)
        {
            if(table[curr->val])
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else{
                table[curr->val] = true;
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};