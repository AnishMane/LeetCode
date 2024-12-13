class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n);
        vector<int> maxRight(n);
        maxLeft[0] = 0;
        maxRight[n-1] = 0;
        for(int i=1;i<n;i++){
            maxLeft[i] = max(maxLeft[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            maxRight[i] = max(maxRight[i+1],height[i+1]);
        }
        int total = 0;
        for(int i=0;i<n;i++){
            int trapped = min(maxLeft[i],maxRight[i]) - height[i];
            if(trapped>0)
                total+=trapped;
        }
        return total;
    }
};