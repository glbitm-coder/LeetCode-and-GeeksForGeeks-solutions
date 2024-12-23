class Twitter {
public:
    unordered_map<int,unordered_set<int>> follows;
    unordered_map<int,vector<pair<int,int>>> myPosts;
    int time = 0, count = 10;
    Twitter() {
          

    }
    
    void postTweet(int userId, int tweetId) {
        myPosts[userId].push_back({time, tweetId});
        ++time;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto it:follows[userId]){
            for(auto i:myPosts[it]){
                pq.push(i);
            }
        }
        for(auto it:myPosts[userId]){
            pq.push(it);
        }
        vector<int> ans;
        int curr = 0;
        while(!pq.empty() && curr < count){
            ans.push_back(pq.top().second);
            pq.pop();
            ++curr;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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