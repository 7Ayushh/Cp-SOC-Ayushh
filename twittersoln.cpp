#include<bits/stdc++.h>
using namespace std;

class Twitter {
private:
    int timestamp;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets;
    std::unordered_map<int, std::unordered_set<int>> followers;

public:
    Twitter() {
        timestamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId, timestamp);
        timestamp++;
    }

std::vector<int> getNewsFeed(int userId) {
    std::vector<int> newsFeed;
    auto compare = [](std::pair<int, int> a, std::pair<int, int> b) {
        return a.second > b.second;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> pq(compare);

    // Add user's tweets to the priority queue
    for (const auto& tweet : tweets[userId]) {
        pq.push(tweet);
        if (pq.size() > 10)
            pq.pop();
    }

    // Add followed users' tweets to the priority queue
    for (const auto& followerId : followers[userId]) {
        for (const auto& tweet : tweets[followerId]) {
            pq.push(tweet);
            if (pq.size() > 10)
                pq.pop();
        }
    }

    // Retrieve the tweet IDs from the priority queue in reverse order
    while (!pq.empty()) {
        newsFeed.push_back(pq.top().first);
        pq.pop();
    }
    
    // Reverse the newsFeed vector to have the most recent tweets at the front
    std::reverse(newsFeed.begin(), newsFeed.end());

    return newsFeed;
}

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    std::vector<int> feed1 = twitter.getNewsFeed(1);
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    std::vector<int> feed2 = twitter.getNewsFeed(1);
    twitter.unfollow(1, 2);
    std::vector<int> feed3 = twitter.getNewsFeed(1);

    // Printing the results
    std::cout << "Feed 1: ";
    for (int tweetId : feed1)
        std::cout << tweetId << " ";
    std::cout << std::endl;

    std::cout << "Feed 2: ";
    for (int tweetId : feed2)
        std::cout << tweetId << " ";
    std::cout << std::endl;

    std::cout << "Feed 3: ";
    for (int tweetId : feed3)
        std::cout << tweetId << " ";
    std::cout << std::endl;

    return 0;
}
