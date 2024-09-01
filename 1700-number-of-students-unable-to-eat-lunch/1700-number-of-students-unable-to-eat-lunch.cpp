class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        unordered_map<int,int> hashMap;
        for(int num:students){
            hashMap[num]++;
        }
        for(int i=0;i<sandwiches.size();++i){
            if(hashMap[sandwiches[i]] > 0){
                hashMap[sandwiches[i]]--;
            }
            else{
                return sandwiches.size()-i;
            }
        }
        return 0;
    }
};