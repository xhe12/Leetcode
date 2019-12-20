//
//  main.cpp
//  Find_The_Kth_Element
//
//  Created by Sharon He on 12/21/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findKthLargest(vector<int>& nums, int K)
    {
        int startIndx = 0;
        int endIndx = nums.size()-1;
        if(nums.size()==1)
        {
            return nums[0];
        }
        findKthLargestUtil(nums, K, startIndx, endIndx);
        return nums[nums.size()-K];
    }
private:
    void findKthLargestUtil(vector<int>& nums, int K, int startIndx, int endIndx)
    {
        int rank = partitioning(nums,startIndx,endIndx);
        if(rank==nums.size()-K)
        {
            return;
        }
        else if(rank<nums.size()-K)
            {
                findKthLargestUtil(nums,K,rank+1,endIndx);
            }
        else
            {
                findKthLargestUtil(nums,K,startIndx,rank-1);
            }
    
    }
    
    int partitioning(vector<int>& nums, int low, int high)
    {
        int i = low;
        int j = high;
        while (high!=low) {
            while(nums[i]<=nums[low])
            {
                i++;
                if(i>=high)
                {break;}
            }
            while(nums[j]>=nums[low])
            {
                j--;
                if(j<=low)
                {break;}
            }
            if(i>=j)
            {break;}
            swap(nums[i],nums[j]);
        }
        swap(nums[low],nums[j]);
        return j;
    }
    
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,1};
    int K = 2;
    Solution sol;
    sol.findKthLargest(nums, K);
    return 0;
}
