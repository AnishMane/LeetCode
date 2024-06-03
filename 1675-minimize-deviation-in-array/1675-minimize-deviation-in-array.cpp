class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        int heapMax = 0;
        
        for(int num:nums)
        {
            int temp = num;
            while(num%2 == 0)
            {
                num = num/2;
            }
            minHeap.push(make_pair(num,max(temp, 2*num)));
            heapMax = max(heapMax, num);
        }
        
        int result = INT_MAX;
        while(minHeap.size() == nums.size())
        {
            int n = minHeap.top().first;
            int nMax = minHeap.top().second;
            minHeap.pop();
            result = min(result, heapMax-n);
            
            if(n<nMax)
            {
                minHeap.push(make_pair(n*2, nMax));
                heapMax = max(heapMax, n*2);
            }
        }
        if(result<0)
        {
            result = result * -1;
        }
        return result;
    }
};