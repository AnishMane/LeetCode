class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        if(skill.size()%2 != 0){
            return -1;
        }
        bool temp = true;
        int i = 0;
        int j = skill.size()-1;
        int sum = skill[i] + skill[j];
        long long result = 0;
        while(i<j){
            if(skill[i]+skill[j] != sum){
                return -1;
            }
            result += skill[i]*skill[j];
            i++;
            j--;
        }
        return result;
    }
};