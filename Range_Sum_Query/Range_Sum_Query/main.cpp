//
//  main.cpp
//  Range_Sum_Query
//
//  Created by Xuan He on 12/14/19.
//  Copyright © 2019 Xuan He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
    vector<int> nums;
    vector<int> subSum;
    
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        
        if(nums.size()>0)
        {
            
            subSum.push_back(nums[0]);
            if(nums.size()>1)
            {
                for(int i = 1; i<nums.size(); i++)
                {
                    subSum.push_back(subSum.back()+nums[i]);
                }
            }
        }
    }
    
    int sumRange(int i, int j) {
        if(nums.size()>max(i,j))
        {
            return subSum[max(i,j)]-subSum[min(i,j)]+nums[min(i,j)];
        }
        else
        {
            return 0;
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-2,0,3,-5,2,-1};
    NumArray narray(nums);
    narray.sumRange(0, 1);
    return 0;
}
