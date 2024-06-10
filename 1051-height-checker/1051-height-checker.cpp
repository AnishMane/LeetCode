class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int expected[heights.size()];
        for(int i=0;i<heights.size();i++)
        {
            expected[i] = heights[i];
        }

        for(int i=0;i<heights.size()-1;i++)
        {
            for(int j=i+1;j<heights.size();j++)
            {
                if(expected[i] > expected[j])
                {
                    int temp = expected[i];
                    expected[i] = expected[j];
                    expected[j] = temp;
                }
            }
        }
        int count =0;
        for(int i=0;i<heights.size();i++)
        {
            if(expected[i] != heights[i])
            {
                count++;
            }
        }
        return count;
    }
};