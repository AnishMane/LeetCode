class LRUCache {
private:
    struct ListNode{
        int key;
        int val;
        ListNode* next;
        ListNode* prev;
        ListNode(int key, int val,ListNode*next=nullptr,ListNode*prev=nullptr){
            this->key = key;
            this->val = val;
            this->next = next;
            this->prev = prev;
        }
    };
    unordered_map<int,ListNode*>cache;
    ListNode* left;
    ListNode* right;
    int cap;

    void remove(ListNode* node){
        ListNode* prev = node->prev;
        ListNode* next = node->next;
        prev->next =next;
        next->prev = prev;
    }

    void insert(ListNode* node){
        ListNode* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new ListNode(0,0);
        right = new ListNode(0,0,nullptr,left);
        left->next = right;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            ListNode* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            remove(cache[key]);
        }
        ListNode* node = new ListNode(key,value);
        cache[key] = node;
        insert(node);

        if(cache.size()>cap){
            ListNode* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
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