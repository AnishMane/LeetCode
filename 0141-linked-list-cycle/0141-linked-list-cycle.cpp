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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> checker;
        
        while(head != NULL)
        {
            if(checker.find(head) != checker.end())
            {
                return true;
            }

            checker.insert(head);

            head = head->next;
        }
        return false;
    }
};