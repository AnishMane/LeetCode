class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int,char>> maxheap;
        if(a>0) maxheap.push({a,'a'});
        if(b>0) maxheap.push({b,'b'});
        if(c>0) maxheap.push({c,'c'});

        string res = "";
        while(!maxheap.empty()){
            pair<int,char> c1 = maxheap.top();
            maxheap.pop();

            int n = res.size();

            if(n>=2 && c1.second==res[n-1] && c1.second == res[n-2]){
                if(maxheap.empty()) break;
                pair<int,char>c2 = maxheap.top();
                maxheap.pop();

                res+=c2.second;
                if(c2.first-1>0)
                    maxheap.push({c2.first-1,c2.second});
                maxheap.push(c1);
            }
            else{
                res+=c1.second;
                if(c1.first-1>0)
                    maxheap.push({c1.first-1,c1.second});
            }
        }
        return res;
    }
};