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

    ListNode* mergedList(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1) tail->next = l1;
        if(l2) tail->next = l2;

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;

        while(lists.size()>1){
            vector<ListNode*> temp;
            for(int i=0;i<lists.size();i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = NULL;
                if(i+1<lists.size()) l2 = lists[i+1];
                temp.push_back(mergedList(l1,l2));
            }
            lists = temp;
        }
        return lists[0];
    }
};