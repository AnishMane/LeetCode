class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        set<pair<int,int>> sObs;
        for(int i=0;i<obstacles.size();++i){
            sObs.insert({obstacles[i][0], obstacles[i][1]});
        }
        pair<int,int> position = {0,0};
        int direction = 0;
        int maxDist = 0;
        
        for(int i=0;i<commands.size();++i){
            if(commands[i] == -2){
                direction = (direction + 3)%4;
            }
            else if(commands[i] == -1){
                direction = (direction+1)%4;
            }
            else{
                for(int j=0;j<commands[i];++j){
                    int nX = position.first + directions[direction].first;
                    int nY = position.second + directions[direction].second;
                    if(sObs.count({nX,nY})){
                        break;
                    }
                    position.first = nX;
                    position.second = nY;

                    maxDist = max(maxDist, (position.first*position.first + position.second*position.second));
                    }    
            }
        }
        return maxDist;
    }
};