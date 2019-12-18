//
//  main.cpp
//  Leetcode #198: House_Robber
//
//  Created by Xuan He on 12/14/19.
//  Copyright © 2019 Xuan He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        if(nums.size()==1)
        {
            return nums[0];
        }
        if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        if(nums.size()==3)
        {
            return max(nums[0]+nums[2],nums[1]);
        }
        int globalMax = max(nums[0]+nums[2],nums[1]);
        vector<int> curMax(nums.size(),0);
        curMax[0] = nums[0];
        curMax[1] = nums[1];
        curMax[2] = nums[0]+nums[2];
        for(int i=3;i<nums.size();i++)
        {
            curMax[i] = max(curMax[i-2]+nums[i],curMax[i-3]+nums[i]);
            globalMax = max(globalMax,curMax[i]);
        }
        return globalMax;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
