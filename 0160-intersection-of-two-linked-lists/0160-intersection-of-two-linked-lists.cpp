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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<int,vector<ListNode*>> table;
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        
        while(curr1)
        {
            table[curr1->val].push_back(curr1);
            curr1 = curr1->next;
        }
        
        while(curr2)
        {
            for(int i=0;i<table[curr2->val].size();i++)
            {
                if(curr2 == table[curr2->val][i])
                {
                    return curr2;
                }
            }
            curr2 = curr2->next;
        }
        return NULL;
    }
};