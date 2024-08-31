class Solution {
public:
    int maxScore(string s) {
        int prefixSum1[s.size()];
        int count =0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i] == '1')
            {
                count++;
            }
            prefixSum1[i] = count;
        }
        count = 0;
        int maxSum = 0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i] == '0')
            {
                count++;
            }
            if(maxSum < count+prefixSum1[i+1])
            {
                maxSum = count+prefixSum1[i+1];
            }
        }
        return maxSum;
    }
};