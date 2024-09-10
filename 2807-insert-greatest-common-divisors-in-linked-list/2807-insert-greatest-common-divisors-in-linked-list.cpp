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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = NULL;
        if(!cur->next){
            return head;
        }
        while(cur->next){
            prev = cur;
            cur = cur->next;
            
            int gcd = min(prev->val, cur->val);
            while(gcd > 0){
                if(prev->val%gcd == 0 && cur->val%gcd == 0){
                    break;
                }
                gcd--;
            }
             
            ListNode* newNode = new ListNode(gcd, cur);
            prev->next = newNode;
        }
        return head;
    }
};