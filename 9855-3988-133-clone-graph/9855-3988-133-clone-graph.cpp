/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* dfs(Node* node, unordered_map<Node*,Node*>&hashmap){
        if(hashmap.find(node)!=hashmap.end()) return hashmap[node];

        Node* copy = new Node(node->val);
        hashmap[node] = copy;

        for(auto nei:node->neighbors){
            copy->neighbors.push_back(dfs(nei,hashmap));
        }
        return copy;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> hashmap;
        if(!node) return NULL;
        return dfs(node,hashmap);
    }
};