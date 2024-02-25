class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int>flowerbed2;
        flowerbed2.push_back(0);
        for(int i=0;i<flowerbed.size();i++)
        {
                flowerbed2.push_back(flowerbed[i]);
        }
        flowerbed2.push_back(0);
        int count = 0;
        for(int i=1;i<flowerbed2.size()-1;i++)
        {
            if(flowerbed2[i-1] == 0 && flowerbed2[i] ==0 && flowerbed2[i+1] == 0)
            {
                flowerbed2[i] = 1;
                count++;
            }
        }
        if(count >= n)
        {
            return true;
        }
        return false;
        }
};