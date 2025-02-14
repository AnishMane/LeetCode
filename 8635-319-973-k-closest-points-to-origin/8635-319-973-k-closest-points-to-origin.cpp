class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(int i=0;i<points.size();i++){
            int dist = pow(points[i][0],2) + pow(points[i][1],2);
            pq.push({dist,i});
        }
        vector<vector<int>> result;
        while(k>0){
            int ind = pq.top().second;
            result.push_back(points[ind]);
            pq.pop();
            k--;
        }
        return result;
    }
};