//
//  main.cpp
//  Leetcode #47: Permutation_II
//
//  Created by Xuan He on 12/1/19.
//  Copyright © 2019 Xuan He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permuteSet;
        vector<int> curSet;
        vector<bool> visited(nums.size(),false);
        
        if (nums.empty())
        {
            return {};
        }
        sort(nums.begin(),nums.end());
        findPermuteSet(nums,permuteSet,curSet,visited,0);
        return permuteSet;
    }
    
    void findPermuteSet(const vector<int>& nums,vector<vector<int>> &permuteSet,vector<int> &curSet,vector<bool> &visited,int levelIndx)
    {
        if(levelIndx == nums.size())
        {
            permuteSet.push_back(curSet);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                curSet.push_back(nums[i]);
                findPermuteSet(nums, permuteSet, curSet, visited, levelIndx+1);
                curSet.pop_back();
                visited[i] = false;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
