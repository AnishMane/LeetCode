class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s.begin(),s.end());
        string s2 = s;
        vector<int> prev(n+1,0), cur(n+1,0);
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) cur[j] = 1 + prev[j-1];
                else{
                    int first = prev[j];
                    int second = cur[j-1];

                    cur[j] = max(first,second);
                }
            }
            prev = cur;
        }

        int lps = prev[n];

        return n-lps;
    }
};