//
//  main.cpp
//  Maximum_Subarray
//
//  Created by Xuan He on 12/14/19.
//  Copyright © 2019 Xuan He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0;
        int globalMax = nums[0];
        for(int i = 0; i<nums.size(); i++)
        {
            curMax += nums[i];
            globalMax = (globalMax>curMax)?globalMax:curMax;
            if(curMax<0)
            {
                curMax = 0;
            }
        }
        return globalMax;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
