class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> minHeap;
        for(int num:nums){
            minHeap.push(num);
        }
        int result = 0;
        while(!minHeap.empty() && minHeap.top()<k){
            long long x = minHeap.top();
            minHeap.pop();
            long long y = minHeap.top();
            minHeap.pop();

            long long temp = min(x,y) * 2 + max(x,y);
            minHeap.push(temp);
            result++;
        }
        return result;
    }
};