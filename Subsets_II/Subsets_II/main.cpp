//
//  main.cpp
//  Leetcode #90: Subsets_II
//
//  Created by Xuan He on 11/30/19.
//  Copyright © 2019 Xuan He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> subsets;
        sort(nums.begin(),nums.end());
        subsets = {{}};
        if (nums.empty())
        {
            return subsets;
        }
        vector<int> curset;
        EnumerateSubsetsWithDFS(nums,curset,subsets,0);
        return subsets;
    }
    
    void EnumerateSubsetsWithDFS(const vector<int>& nums, vector<int>& curset,vector<vector<int>> &subsets, int startIndx)
    {
        //termination condition;
        if(startIndx==nums.size())
        {
            return;
        }
        
        for(int i=startIndx;i<nums.size();i++)
        {
            if(i!=startIndx && nums[i] == nums[i-1])
            {
                continue;
            }
            curset.push_back(nums[i]);
            subsets.push_back(curset);
            EnumerateSubsetsWithDFS(nums, curset, subsets, i+1);
            curset.pop_back();
        }
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
