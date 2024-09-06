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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> hashSet;
        for(int num:nums){
            hashSet.insert(num);
        }
        ListNode* current = head;
        ListNode* prev = NULL;
        while(current!= NULL){
            if(hashSet.find(current->val) != hashSet.end()){
                if(prev == NULL){
                    head = head->next;
                    current = head;
                    continue;
                }
                prev->next = current->next;
                current = current->next;
            }
            else{
                prev = current;
                current = current->next;
            }

        }
        return head;
    }
};