#include<bits/stdc++.h>
using namespace std;

class Twitter {
public:

    // unordered sets and maps have const time complexity and  implemented using hash tables (keys ke according)

// The tweets data structure in the Twitter class uses the userID as the key in the unordered map to access the vector of tweets associated with that user. Each tweet in the vector is represented by a pair consisting of the tweetID and its corresponding timestamp.

    // recently part ko answer
    int timestamp=0;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int,int>>> tweets;
    
    Twitter() {
        timestamp=0; // start
    }
    
    void postTweet(int userId, int tweetId) {  
        // userID - user only , tweetID - like tweet is an img to uska bhi to label hoga koi
        tweets[userId].push_back({tweetId, timestamp});
        timestamp++;
    }
    
    // vector<int> getNewsFeed(int userId) {
    //     // tweets[userID] is a vector
    //     // combining both and then checking timestamp was the main problem
    //     vector<int> newsfeed;
    //     vector<pair<int,int>> combined_feed;

    //     // add own tweets
    //     // insert method -- posi of insert and then the range
    //     combined_feed.insert(combined_feed.end(), tweets[userId].begin(),tweets[userId].end());
    //     // add follower tweets
    //     for(const int& followerId : followers[userId]){
    //         combined_feed.insert(combined_feed.end(), tweets[followerId].begin(), tweets[userId].end());
    //     }
    //     // The lambda function [](const auto& a, const auto& b) { return a.second > b.second;}
    //     //ompares two elements a and b of the combinedTweets vector based on their second values.
    //     // The a and b represent pairs of tweet IDs and timestamps in the combinedTweets vector.
    //     sort(combined_feed.begin(),combined_feed.end(), [](const auto& a, const auto& b){
    //         return a.second > b.second;
    //     });   //weird lambda function

    //     int count=1;
    //     for(const auto& tweets : combined_feed){
    //         newsfeed.push_back(tweets.first);
    //         count++;
    //         if(count==10) break;
    //     }
    //     // now retrieve
    //     return newsfeed;
  //  }
//     std::vector<int> vec = {1, 2, 3, 4, 5};
//     auto it = vec.begin();
//     while (it != vec.end()) {
//         int element = *it;
//         // Perform operations with element
//         ++it;} // Move to the next element


    vector<int> getNewsFeed(int userId) {
        std::vector<int> newsFeed;
        std::priority_queue<std::pair<int, int>> pq;

        // Add user's own tweets
        for (const auto& tweet : tweets[userId]) {
            pq.push(tweet);
            if (pq.size() > 10)
                pq.pop();
        }

        // Add followed users' tweets
        for (const int& followerId : followers[userId]) {
            for (const auto& tweet : tweets[followerId]) {
                pq.push(tweet);
                if (pq.size() > 10)
                    pq.pop();
            }
        }

        while (!pq.empty()) {
            newsFeed.insert(newsFeed.begin(), pq.top().first);
            pq.pop();
        }

        return newsFeed;
    }

    
    void follow(int followerId, int followeeId) {
        if(followerId =! followeeId) followers[followeeId].erase(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // phle you've to follow , so condition checked above
        followers[followeeId].erase(followerId);
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