class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>following;
    int timestamp;
    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        //timestamp,tweetid,userid,index in tweet
        priority_queue<tuple<int,int,int,int>>maxHeap;
        if(tweets.count(userId)&&!tweets[userId].empty())
        {
            int idx=tweets[userId].size()-1;
            maxHeap.push({
                tweets[userId][idx].first,
                tweets[userId][idx].second,
                userId,
                idx
            });
        }
        if(following.count(userId)){
            for(int followee:following[userId])
            {
                if(tweets.count(followee)&&!tweets[followee].empty())
                {
                    int idx=tweets[followee].size()-1;
                    maxHeap.push({tweets[followee][idx].first,
                    tweets[followee][idx].second,
                    followee,
                    idx});
                }
            }
        }

        vector<int>result;
        while(!maxHeap.empty()&&result.size()<10)
        {
            auto[time,tweetId,uid,idx]=maxHeap.top();
            maxHeap.pop();
            result.push_back(tweetId);

            if(idx>0)
            {
                maxHeap.push({
                    tweets[uid][idx-1].first,
                    tweets[uid][idx-1].second,
                    uid,
                    idx-1
                });
            }

        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
        {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following.count(followerId))
        {
            following[followerId].erase(followeeId);
        }
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