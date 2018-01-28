class Twitter {
private:
	map<int, map<int, int>> friend_list;
	stack<pair<int, int>> tweet;

public:
	/** Initialize your data structure here. */
	Twitter() {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		tweet.push({ userId, tweetId });
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		stack<pair<int, int>> copy = tweet;
		vector<int> res;
		while (!copy.empty() && res.size() < 10) {
			pair<int, int> new_tweet = copy.top();
			copy.pop();
			if (friend_list[userId].count(new_tweet.first) > 0 || userId == new_tweet.first) res.push_back(new_tweet.second);
		}
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		friend_list[followerId][followeeId]++;
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (friend_list[followerId].count(followeeId) > 0) {
			friend_list[followerId].erase(followeeId);
		}
	}
};