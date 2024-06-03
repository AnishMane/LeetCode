class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        for(int num:arr)
        {
            freq[num]++;
        }
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto num:freq)
        {
            minHeap.push(num.second);
        }
        int result = minHeap.size();
        while(k>0 && !minHeap.empty()){
            int check = minHeap.top();
                if(k>= check)
                {
                    minHeap.pop();
                    k -=check;
                    result-=1;
                }
            else{
                break;
            }
        }
        return result;
    }
};