class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumG = 0;
        int sumC = 0;
        for(int i=0;i<gas.size();i++){
            sumG+=gas[i];
            sumC+=cost[i];
        }
        if(sumG<sumC) return -1;
        
        int total = 0;
        int start = 0;
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];
            if(total<0){
                total = 0;
                start = i+1;
            }
        }
        return start;
        
    }
};