//
//  main.cpp
//  Leetcode #996: Number_Of_Squareful_Arrays
//
//  Created by Sharon He on 12/6/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        
        if(A.empty())
        {
            return 0;
        }
        
        if(A.size()==1)
        {
            return 1;
        }
        
        sort(A.begin(),A.end());
        vector<int> unique_A(A);
        auto itr = unique(unique_A.begin(),unique_A.end());
        unique_A.erase(itr,unique_A.end());
        
        unordered_map<int,int> digitCount;
        int n = A.size();
        for(int i = 0; i<n; i++)
        {
            if(i!=0 & A[i]==A[i-1])
            {
                digitCount[A[i]] += 1;
            }
            else
            {
                digitCount[A[i]] = 1;
            }
        }
        
        unordered_map<int,unordered_set<int>> match(unique_A.size());
        for(int i = 0; i<unique_A.size();i++)
        {
            for(int j = 0; j<unique_A.size();j++)
            {
                double sr = sqrt(unique_A[i]+unique_A[j]);
                if(ceil(sr)==floor(sr))
                {
                    match[unique_A[i]].insert(unique_A[j]);
                }
            }
        }
        
        vector<int> curSet;
        int ans = 0;
        
        for(int i=0; i<unique_A.size(); i++)
        {
            if(match.find(unique_A[i])!=match.end())
            {
                curSet.push_back(unique_A[i]);
                digitCount[unique_A[i]] -= 1;
                permuteDFS(unique_A,match,digitCount,curSet,ans,1,n);
                curSet.pop_back();
                digitCount[unique_A[i]] += 1;
            }
        }
        
        return ans;
    }
    
    void permuteDFS(const vector<int> &unique_A, const unordered_map<int,unordered_set<int>> &match, unordered_map<int,int> &digitCount,vector<int> &curSet,int &ans, int levelIndx, int n)
    {
        if(levelIndx>=n)
        {
            ans += 1;
            return;
        }
        for(auto itr = digitCount.begin(); itr!=digitCount.end(); ++itr)
        {
            unordered_set<int> bag = match.at(curSet.back());
            if((itr->second>0)&bag.find(itr->first)!=bag.end())
            {
                curSet.push_back(itr->first);
                itr->second -= 1;
                permuteDFS(unique_A,match,digitCount,curSet,ans,levelIndx+1,n);
                itr->second += 1;
                curSet.pop_back();
            }
        }
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    /*
     vector<int> A = {1,17,8};
    Solution sol;
    int num = sol.numSquarefulPerms(A);
    cout<<num<<endl;
     */
    unordered_map<int, unordered_set<int>> dict;
    unordered_set<int> bag = {1,2};
    dict[1] = bag;
    unordered_set<int> i = dict[1];
    
    return 0;
}
