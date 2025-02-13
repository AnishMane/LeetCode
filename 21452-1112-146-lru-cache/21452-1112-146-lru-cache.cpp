class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int x, int y){
        key = x;
        val = y;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*> hashMap;
    Node* left;
    Node* right;
    int cap;
    void remove(Node* node){
        Node* pre = node->prev;
        Node* nxt = node->next;
        pre->next = nxt;
        nxt->prev = pre;
    }

    void insert(Node* node){
        Node* pre = right->prev;
        pre->next = node;
        node->prev = pre;
        node->next = right;
        right->prev = node;
    }

    LRUCache(int capacity) {
        cap = capacity;
        hashMap.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(hashMap.find(key)!=hashMap.end()){
            Node* node = hashMap[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hashMap.find(key)!=hashMap.end()) remove(hashMap[key]);

        Node* newNode = new Node(key,value);
        hashMap[key] = newNode;
        insert(newNode);

        if(hashMap.size()>cap){
            Node* lru = left->next;
            remove(lru);
            hashMap.erase(lru->key);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */