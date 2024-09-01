class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sw;
        for(int i=sandwiches.size()-1;i>=0;--i){
            sw.push(sandwiches[i]);
        }
        queue<int> st;
        for(int i=0;i<students.size();++i){
            st.push(students[i]);
        }
        int count = 0;
        while(!st.empty() && count < sw.size()){
            if(sw.top() == st.front()){
                sw.pop();
                st.pop();
                count = 0;
            }
            else{
                int temp = st.front();
                st.pop();
                st.push(temp);
                count++;
            }
        }
        return st.size();
    }
};