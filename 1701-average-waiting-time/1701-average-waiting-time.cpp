class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum = 0;
        int currTime =customers[0][0];
        for(int i=0;i<customers.size();i++){
            if(currTime < customers[i][0])
            {
                currTime = customers[i][0];
            }
            currTime += customers[i][1];
            sum = sum + currTime - customers[i][0];
        }
        return sum/customers.size();
    }
};