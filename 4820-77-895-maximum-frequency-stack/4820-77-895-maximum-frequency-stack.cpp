class FreqStack {
private:
    unordered_map<int,int> cnt;
    int maxCnt = 0;
    unordered_map<int,stack<int>> stacks;
    
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        int valCnt = 1;
        if(cnt.count(val)){
            valCnt += cnt[val];
        }
        cnt[val] = valCnt;

        if(valCnt > maxCnt){ 
            maxCnt = valCnt;
            stacks[valCnt] = stack<int>();
        }
        stacks[valCnt].push(val);
    }
    
    int pop() {
        int val = stacks[maxCnt].top();
        stacks[maxCnt].pop();
        cnt[val]--;
        if(stacks[maxCnt].size()==0) maxCnt--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */