class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        vector<int> temp;
        for(int i=0;i<arr.size();i++)
        {
            if(temp.size() == 3)
            {
                return true;
            }
            if(arr[i] % 2 != 0)
            {
                temp.push_back(arr[i]);
            }
            else{
                temp.clear();
            }
        }
        if(temp.size() == 3)
            {
                return true;
            }
        return false;
    }
};