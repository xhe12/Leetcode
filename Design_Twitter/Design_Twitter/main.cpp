//
//  main.cpp
//  Leetcode #355: Design_Twitter
//
//  Created by Sharon He on 12/21/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Tweet{

public:
    static int Count;
    int tweetId;
    int timestamp;// time = 5, means the tweet is the fifth tweet being posted
    Tweet(int _tweetId)
    {
        tweetId = _tweetId;
        Count++;
        timestamp = Count;
    }
    int getTimestamp()
    {
        return timestamp;
    }
};

struct Comparator{
  bool operator()(Tweet* t1, Tweet* t2)
    {
        return t1->getTimestamp()>t2->getTimestamp();
    }
};

class User{
private:
    unordered_set<User*> followee;
    unordered_set<User*> follower;
    vector<Tweet*> ownTweet;
    int userId;
    
public:
    User(int _userId):userId(_userId){}
    void post(int tweetId)
    {
        //Create a new Tweet (meanwhile the total tweet amount is updated), add the newTweet to the vector ownTweet
        Tweet* newTweet = new Tweet(tweetId);
        ownTweet.push_back(newTweet);
    }
    vector<Tweet*> getNewsFeed()
    {
        priority_queue<Tweet*,vector<Tweet*>,Comparator> newsFeedQ;
        vector<Tweet*> newsFeed;
        for(Tweet* tweet:ownTweet)
        {
            newsFeedQ.push(tweet);
            if(newsFeedQ.size()>10)
            {
                newsFeedQ.pop();
            }
        }
        for(User* u: followee)
        {
            for(Tweet* t: u->ownTweet)
            {
                newsFeedQ.push(t);
                if(newsFeedQ.size()>10)
                {
                    newsFeedQ.pop();
                }
            }
        }
        while(!newsFeedQ.empty())
        {
            newsFeed.push_back(newsFeedQ.top());
            newsFeedQ.pop();
        }
        
        return newsFeed;
    }
        
    void follow(User* followee)
    {
        if(this->userId==followee->userId)
        {
            return;
        }
        followee->follower.insert(this);
        this->followee.insert(followee);
 
    }
    void unfollow(User* followee)
    {
        this->followee.erase(followee);
        followee->follower.erase(this);
    }
};

class Twitter {
    unordered_map<int,User*> userTracker;
public:
    // Initialize your data structure here.
    Twitter() {
    }
    
    // Compose a new tweet.
    void postTweet(int userId, int tweetId) {
        if(userTracker.find(userId)==userTracker.end())
        {
            User* newUser = new User(userId);
            userTracker[userId] = newUser;
        }
        userTracker[userId]->post(tweetId);
    }
    
    /* Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if(userTracker.find(userId)==userTracker.end())
        {
            return {};
        }
        vector<Tweet*> newsFeed = userTracker[userId]->getNewsFeed();
        vector<int> newsFeedId(newsFeed.size());
        for(int i = 0; i<newsFeed.size(); i++)
        {
            newsFeedId[newsFeed.size()-1-i] = newsFeed[i]->tweetId;
        }
        return newsFeedId;
    }
    
    // Follower follows a followee. If the operation is invalid, it should be a no-op.
    void follow(int followerId, int followeeId) {
        if(userTracker.find(followerId)==userTracker.end())
        {
            User* f = new User(followerId);
            userTracker[followerId] = f;
        }
        if(userTracker.find(followeeId)==userTracker.end())
        {
            User* f = new User(followeeId);
            userTracker[followeeId] = f;
        }
        userTracker[followerId]->follow(userTracker[followeeId]);
    }
    
    // Follower unfollows a followee. If the operation is invalid, it should be a no-op.
    void unfollow(int followerId, int followeeId) {
        if(userTracker.find(followerId)!=userTracker.end()&&userTracker.find(followeeId)!=userTracker.end())
        {
            userTracker[followerId]->unfollow(userTracker[followeeId]);
        }
    }
};
int Tweet::Count = 0;
/*
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
int main(){
    Twitter twitter;
    twitter.postTweet(1, 5);
    twitter.postTweet(1, 3);
    twitter.postTweet(1, 101);
    twitter.postTweet(1, 13);
    twitter.postTweet(1, 10);
    twitter.postTweet(1, 2);
    twitter.postTweet(1, 94);
    twitter.postTweet(1, 505);
    twitter.postTweet(1, 333);
    twitter.postTweet(1, 22);
    twitter.postTweet(1, 11);
    vector<int> newsFeed = twitter.getNewsFeed(1);
    
    return 0;
}
