class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(string c:operations)
        {
            if(c == "C")
            {
                s.pop();
                continue;
            }
            else if(c == "D")
            {
                s.push(2*s.top());
                continue;
            }
            else if(c == "+")
            {
                int temp1 = s.top();
                s.pop();
                int temp2 = temp1 + s.top();
                s.push(temp1);
                s.push(temp2);
                continue;
            }
            else{
                s.push(stoi(c));
            }
        }
        int sum = 0;
        while(!s.empty())
        {
            sum = sum + s.top();
            s.pop();
        }
        return sum;
    }
};