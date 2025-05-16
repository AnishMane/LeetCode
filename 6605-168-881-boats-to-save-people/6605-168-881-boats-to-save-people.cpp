class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int res = 0;
        sort(people.begin(),people.end());
        int i = 0, j=n-1;

        while(i<=j){
            if(people[j] + people[i] > limit){
                j--;
                res++;
            }
            else{
                j--;
                i++;
                res++;
            }
        }
        return res;
    }
};