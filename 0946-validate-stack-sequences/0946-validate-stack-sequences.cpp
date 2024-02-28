class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j =0;
        for(int num:pushed)
        {
            
            if(num!= popped[j])
            {
                s.push(num);
            }
            else{
                j++;
            }
            while(!s.empty() && s.top()==popped[j])
            {
                s.pop();
                j++;
            }
        }
        while(j<popped.size())
        {
            if(!s.empty() &&s.top() == popped[j]){
                s.pop();
            }
            j++;
        }
        if(s.empty()){
            return true;
        }
        return false;
    }
};