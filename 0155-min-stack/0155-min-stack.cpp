class MinStack {
private:
    stack<int> s;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(!s.empty()){
            s.push(val);
            minStack.push(min(minStack.top(), val));
        }
        else{
            s.push(val);
            minStack.push(val);
        }
    }
    
    void pop() {
       if(!s.empty()){
           s.pop();
           minStack.pop();
       }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */