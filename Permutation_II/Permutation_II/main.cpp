//
//  main.cpp
//  Leetcode #47: Permutation_II
//
//  Created by Sharon He on 12/2/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        if(nums.empty())
        {
            return {{}};
        }
        vector<vector<int>> permuteSet;
        vector<int> curSet;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> unique_nums;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
            {
                unique_nums[nums[i]] += 1;
            }
            else
            {
                unique_nums[nums[i]] = 1;
            }
        }
        int size = nums.size();
        findPermutationByDFS(size,unique_nums,permuteSet,curSet,0);
        return permuteSet;
    }
    void findPermutationByDFS(const int &size,unordered_map<int,int> &unique_nums,vector<vector<int>> &permuteSet,vector<int> &curSet,int levelIndx)
    {
        if(levelIndx==size)
        {
            permuteSet.push_back(curSet);
            return;
        }
        for(auto itr = unique_nums.begin();itr != unique_nums.end();++itr)
        {
            if(itr->second>0)
            {
                curSet.push_back(itr->first);
                itr->second -= 1;
                findPermutationByDFS(size, unique_nums, permuteSet, curSet, levelIndx+1);
                curSet.pop_back();
                itr->second += 1;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
