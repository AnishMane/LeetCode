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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k,NULL);
        ListNode* current = head;
        int n=0;
        while(current!=NULL){
            n++;
            current = current->next;
        }
        
        int partSize = n/k;
        int remainder = n%k;
        current = head;
        for(int i=0;i<k && current!=NULL;++i){
            int currPart = partSize + (i<remainder ? 1:0);
            result[i] = current;
            for(int j=1;j<currPart;++j){
                current = current->next;               
            }
            ListNode* next = current->next;
            current->next = NULL;
            current = next;
        }
        return result;
    }
};