// DESIGN TWITTER
#include<bits/stdc++.h>
using namespace std;
class Twitter {
public:
    int time;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    Twitter() {
        time =0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        vector<int> result;
        following[userId].insert(userId);
        for(int followee: following[userId]){
            auto &tw = tweets[followee];
            if(!tw.empty()){
                int idx = tw.size()-1;
                pq.push({tw[idx].first, tw[idx].second, followee, idx});
            }
        }
        while(!pq.empty() && result.size()<10){
            auto top =pq.top();
            pq.pop();
            int time = top[0];
            int tweetId = top[1];
            int user = top[2];
            int idx = top[3];
            result.push_back(tweetId);
            if(idx>0){
                auto &tw = tweets[user];
                pq.push({tw[idx-1].first, tw[idx-1].second, user, idx-1});
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId) following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if( following.count(followerId)) following[followerId].erase(followeeId);
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