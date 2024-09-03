class Solution {
public:
    int getLucky(string s, int k) {
        string transformed = "";
        for(int i=0;i<s.size();++i){
            int value = s[i] - 'a' + 1;
            transformed += to_string(value);
        }
        
        while(k>0){
            int sum =0;
            for(int i=0;i<transformed.size();++i){
                sum += transformed[i] - '0';
            }
            transformed = to_string(sum);
            k--;
        }
        return stoi(transformed);
    }
};