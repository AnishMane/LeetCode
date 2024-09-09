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
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode* curr = head;
        while(curr!=NULL){
            while(!st.empty() && curr->val > st.top()){
                st.pop();
            }
            st.push(curr->val);
            curr = curr->next;
        }
        vector<int> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        ListNode* dummy = new ListNode();
        curr = dummy;
        for(int i=temp.size()-1;i>=0;--i){
            curr->next = new ListNode(temp[i]);
            curr = curr->next;
        }
        return dummy->next;
    }
};