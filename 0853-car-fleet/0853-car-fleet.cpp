class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> ps;
        stack<double> s;
        for(int i=0;i<position.size();++i){
            ps.push_back({position[i], speed[i]});
        }
        sort(ps.begin(),ps.end());
        
        for(int i=ps.size()-1;i>=0;--i){
            double temp = (double(target - ps[i].first)/double(ps[i].second));
            if(s.empty()){
                s.push(temp);
            }
            else{
                if(s.top() >= temp){
                    continue;
                }else{
                    s.push(temp);
                }
            }
        }
        return s.size();
    }
};