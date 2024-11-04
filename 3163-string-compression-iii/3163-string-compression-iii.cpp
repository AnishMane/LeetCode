class Solution {
public:
    string compressedString(string word) {
        string result = "";
        if(word.empty()) return result;
        int count = 1;
        char c = word[0];
        for(int i=1;i<word.size();i++){
            if(word[i] == c){
                if(count == 9){
                    result+= to_string(9) + c;
                    count = 1;
                    continue;
                }
                count++;
            }
            else{
                result+= to_string(count) + c;
                count = 1;
                c = word[i];
            }
        }
        result+=to_string(count)+c;
        return result;
    }
};