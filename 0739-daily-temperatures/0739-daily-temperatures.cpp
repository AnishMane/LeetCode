class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<pair<int,int>> s;
        for(int i=0;i<temperatures.size();++i){
            while(!s.empty() && s.top().first < temperatures[i]){
                result[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temperatures[i],i});
        }
        while(!s.empty()){
            result[s.top().second] = 0;;
            s.pop();
        }
        return result;
    }
};