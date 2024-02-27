class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string c:tokens)
        {
            if(c == "+")
            {
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.pop();
                s.push(temp2+temp1);
                continue;
            }
            else if(c == "-")
            {
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.pop();
                s.push(temp2-temp1);
                continue;
            }
            else if(c == "*")
            {
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.pop();
                s.push(temp2*temp1);
                continue;
            }
            else if(c == "/")
            {
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.pop();
                int div = temp2/temp1;
                s.push(div);
                continue;
            }
            else{
                int temp = stoi(c);
                s.push(temp);
                continue;
            }
        }
        return s.top();
    }
};