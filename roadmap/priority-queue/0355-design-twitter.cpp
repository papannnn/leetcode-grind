struct Tweet {
    int id;
    int time;
};

class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        postMap[userId].push_back({tweetId, time});
        if (postMap[userId].size() > 10) {
            postMap[userId].pop_front();
        }
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        auto comp = [] (const Tweet& a, const Tweet& b) {
            return a.time > b.time;
        };

        priority_queue<Tweet, vector<Tweet>, decltype(comp)> newsFeed;
        for (int i = 0 ; i < postMap[userId].size(); i++) {
            newsFeed.push(postMap[userId][i]);
            while (newsFeed.size() > 10) {
                newsFeed.pop();
            }
        }

        for (int acc : followMap[userId]) {
            for (int i = 0 ; i < postMap[acc].size(); i++) {
                newsFeed.push(postMap[acc][i]);
                while (newsFeed.size() > 10) {
                    newsFeed.pop();
                }
            }
        }

        vector<int> res;
        while (!newsFeed.empty()) {
            res.push_back(newsFeed.top().id);
            newsFeed.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }

private:
    int time{};
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, deque<Tweet>> postMap;
};
