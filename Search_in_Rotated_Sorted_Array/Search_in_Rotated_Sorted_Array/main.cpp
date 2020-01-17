//
//  main.cpp
//  Search_in_Rotated_Sorted_Array
//
//  Created by Sharon He on 1/14/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0){return -1;}
        int pivot = findPivot(nums);
        //findPivotBacktracking(nums,0,nums.size()-1,pivot);
        int targetIndx;
        if(pivot == 0){
            targetIndx = binarySearch(nums,0,nums.size()-1,target);
        }
        else if(target>=nums[0]){
            targetIndx = binarySearch(nums,0,pivot,target);
        }
        else{
            targetIndx = binarySearch(nums,pivot+1,nums.size()-1,target);
        }
        return targetIndx;
    }
    void findPivotBacktracking(const vector<int>& nums, int startIndx, int endIndx,int& pivot){
        int midIndx = (startIndx+endIndx)/2;
        if(midIndx == startIndx){
            pivot = midIndx;
            return;
        }
        if(nums[midIndx]<nums[startIndx]){
            findPivotBacktracking(nums,startIndx,midIndx,pivot);
        }
        else if(nums[midIndx]>nums[endIndx]){
            findPivotBacktracking(nums,midIndx,endIndx,pivot);
        }
        else{
            pivot = 0;
            return;
        }
        return;
    }
    int binarySearch(const vector<int>& nums, int startIndx, int endIndx, int target){
        int lo = startIndx;
        int hi = endIndx;
        
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(nums[lo]==target){
                return lo;
            }
            else if(nums[hi]==target){
                return hi;
            }
            else if(mid==lo){break;}
            else if(nums[mid]>target){
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        if(nums[lo]==target){return lo;}
        else{return -1;}
        
    }
    int findPivot(const vector<int>& nums){
        int lo = 0;
        int hi = nums.size()-1;
        int mid;
        while(lo<hi){
            mid = (lo+hi)/2;
            if(mid==lo){break;}
            if(nums[mid]<nums[lo]){
                hi = mid;
            }
            else if(nums[mid]>nums[hi]){
                lo = mid;
            }
            else{break;}
        }
        return lo;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> nums = {1,3,5};
    Solution sol;
    sol.search(nums, 0);
    return 0;
}
