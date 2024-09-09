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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* current = list1;
        ListNode* prev = current;
        ListNode* result = prev;
        int k = 0;
        while(current!= NULL){
            if(k == a){
                prev->next = list2;
                while(prev->next!=NULL){
                    prev = prev->next;
                }
            }
            else if(k == b+1){
                prev->next = current;
                return result;
            }
            
            if(k<a){
                prev = current;
            }
            current = current->next;
            k++;
        }
        return result;;
    }
};