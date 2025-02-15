class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> userTweet;
    unordered_map<int,unordered_set<int>> followList;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        time+=1;
        userTweet[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<userTweet[userId].size();i++){
            pq.push(userTweet[userId][i]);
        }

        for(auto it:followList[userId]){
            for(int i=0;i<userTweet[it].size();i++){
                pq.push(userTweet[it][i]);
            }
        }
        for(int i=1;i<=10;i++){
            if(pq.empty()) break;
            int temp = pq.top().second;
            result.push_back(temp);
            pq.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */