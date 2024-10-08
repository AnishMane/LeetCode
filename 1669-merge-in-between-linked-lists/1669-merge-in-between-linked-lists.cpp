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
        int i = 0;
        while(i < a-1){
            current = current->next;
            i++;
        }
        ListNode* head = current;
        
        while(i <= b){
            current = current->next;
            i++;
        }
        head->next = list2;
        while(list2->next){
            list2 = list2->next;
        }
        list2->next = current;
        return list1;
    }
};