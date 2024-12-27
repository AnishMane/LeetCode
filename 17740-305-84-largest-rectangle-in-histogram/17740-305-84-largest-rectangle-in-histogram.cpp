class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int maxArea = 0;
        for(int i=0;i<heights.size();++i){
            int start = i;
            while(!st.empty() && st.top().second > heights[i]){
                int index = st.top().first;
                int height = st.top().second;
                maxArea = max(maxArea,(i-index)*height);
                st.pop();
                start = index;
            }
            st.push({start,heights[i]});
        }
        
        while(!st.empty()){
            int index = st.top().first;
            int height = st.top().second;
            st.pop();
            maxArea = max(maxArea,height*(int(heights.size())-index));
        }
        return maxArea;
    }
};