/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        
        unordered_map<Node*,Node*> hashMap;
        Node* cur = head;
        Node* head2 = new Node(cur->val);
        hashMap[cur] = head2;
        cur=cur->next;
        while(cur!=NULL){
            Node* temp = new Node(cur->val);
            hashMap[cur] = temp;
            cur=cur->next;
        }

        cur = head;
        Node* cur2 = head2;
        while(cur!=NULL){
            cur2->next = hashMap[cur->next];
            cur2->random = hashMap[cur->random];
            cur = cur->next;
            cur2=cur2->next;
        }
        return head2;
    }
};