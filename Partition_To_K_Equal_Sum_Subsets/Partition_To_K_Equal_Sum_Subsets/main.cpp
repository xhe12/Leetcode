//
//  main.cpp
//  Leetcode #698: Partition_To_K_Equal_Sum_Subsets
//
//  Created by Sharon He on 12/13/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
private:
    vector<bool> visited;
    void partitionKSubsets(vector<int>& nums,int k,int curSum,int binSum,int binIndx, bool &ans, int startIndx)
    {
        if(binIndx>=k)
        {
            ans = true;
        }
        if(ans == true)
        {
            return;
        }
        if(curSum > binSum)
        {
            return;
        }
        for(int i = startIndx; i>=0; i--)
        {
            if(visited[i]==false)
            {
                visited[i] = true;
                int prevSum = curSum;
                curSum += nums[i];
                
                if(curSum == binSum)
                {
                    partitionKSubsets(nums,k,0,binSum,binIndx+1,ans, nums.size()-1);
                }
                else
                {
                    partitionKSubsets(nums,k,curSum,binSum,binIndx,ans, i-1);
                }
                visited[i] = false;
                curSum = prevSum;
            }
        }
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1)
        {
            return true;
        }
        sort(nums.begin(),nums.end());
        int sum = accumulate(nums.begin(),nums.end(),0);
        int binSum = sum/k;
        if(binSum*k < sum)
        {
            return false;
        }
        for(int i = 0; i<nums.size(); i++)
        {
            visited.push_back(false);
        }
        bool ans = false;
        int binIndx = 0;
        int curSum = 0;
        partitionKSubsets(nums,k,curSum,binSum,binIndx,ans,nums.size()-1);
        
        return ans;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,2,3,3,4,5};
    int k = 4;
    Solution sol;
    bool ans = sol.canPartitionKSubsets(nums, k);
    cout<<ans<<endl;
    return 0;
}
