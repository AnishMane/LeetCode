class Solution {
public:
    
    void backtracking(string digits, unordered_map<char,string> hashMap, vector<string>&result, int index, string res){
        if(index == digits.size()){
            result.push_back(res);
            return;
        }
        
        for(int i=0;i<hashMap[digits[index]].size();++i){
            
            backtracking(digits,hashMap,result,index+1,res+hashMap[digits[index]][i]);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};
        vector<string> result;
        unordered_map<char,string> hashMap;
        
        hashMap['2'] = "abc";
        hashMap['3'] = "def";
        hashMap['4'] = "ghi";
        hashMap['5'] = "jkl";
        hashMap['6'] = "mno";
        hashMap['7'] = "pqrs";        
        hashMap['8'] = "tuv";
        hashMap['9'] = "wxyz";

        backtracking(digits,hashMap,result,0, "");
        
        return result;
    }
};