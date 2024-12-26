class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> sorted;
        stack<double> st;
        for(int i=0;i<position.size();i++){
            sorted.push_back({position[i],speed[i]});
        }
        sort(sorted.begin(),sorted.end());
        
        for(int i=sorted.size()-1;i>=0;--i){
            double timeTaken = double(target-sorted[i].first)/double(sorted[i].second);
            
            if(st.empty()){
                st.push(timeTaken);
            }else{
                if(st.top() < timeTaken){
                    st.push(timeTaken);
                }
            }
        }
        return st.size();
    }
};