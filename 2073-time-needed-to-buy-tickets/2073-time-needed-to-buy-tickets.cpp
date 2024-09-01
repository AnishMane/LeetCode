class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        queue<int> tk;
        for(int i=0;i<tickets.size();++i){
            tk.push(i);
        }
        
        while(tickets[k] != 0){
            int current = tk.front();
            tk.pop();
            if(tickets[current] > 0){
                tickets[current]--;
                time++;
                
                if(tickets[current] > 0){
                    tk.push(current);
                }
            }          
        }
        return time;
    }
};