#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Twitter {
  private:
    // id -> set(id)
    unordered_map<int, unordered_set<int>> follow_map;
    // id -> (time, id)
    unordered_map<int, vector<pair<int, int>>> tweets;
    int timestamp = 0;

  public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // need to do k way merge
        // get a map of the following + user with indexes pointed to back
        // proceed to do a k way merge (max heap ver)
        // (timestamp, tweet_id, tweet_index, user_index)
        using T = tuple<int, int, int, int>;
        auto cmp = [](const T &a, const T &b) { return get<0>(a) < get<0>(b); };
        auto following =
            unordered_set(follow_map[userId].begin(), follow_map[userId].end());
        following.insert(userId);

        priority_queue<T, vector<T>, decltype(cmp)> pq;
        for (auto &id : following) {
            int size = tweets[id].size() - 1;
            if (size != -1) {
                pq.push({tweets[id][size].first, tweets[id][size].second, size,
                         id});
            }
        }

        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            auto [time, tweet, size, user] = pq.top();
            pq.pop();
            res.push_back(tweet);
            int new_size = size - 1;
            if (new_size != -1) {
                pq.push({tweets[user][new_size].first,
                         tweets[user][new_size].second, new_size, user});
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        follow_map[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (follow_map[followerId].contains(followeeId)) {
            follow_map[followerId].erase(followeeId);
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
