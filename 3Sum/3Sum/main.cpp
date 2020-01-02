//
//  main.cpp
//  3Sum
//
//  Created by Sharon He on 1/2/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3){
            return {};
        }
        vector<vector<int>> solSet;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]){continue;}
            else{
                twoSum(nums,-nums[i],i+1,n-1,solSet);
            }
        }
        return solSet;
    }
    void twoSum(const vector<int>& nums, int target, int lp, int rp, vector<vector<int>>& solSet){
        if(lp >= nums.size()-1){
            return;
        }
        while(lp < rp){
            if(nums[lp]+nums[rp]==target){
                solSet.push_back({-target,nums[lp],nums[rp]});
                lp = moveLp(nums,lp);
                rp = moveRp(nums,rp);
            }
            else if(nums[lp]+nums[rp]>target){
                rp--;
            }
            else{
                lp++;
            }
        }
        return;
    }
    int moveLp(const vector<int>& nums, int lp){
        while(lp+1<nums.size() && nums[lp]==nums[lp+1]){
            lp++;
        }
        lp++;
        return lp;
    }
    int moveRp(const vector<int>& nums, int rp){
        while(rp-1>=0 && nums[rp]==nums[rp-1]){
            rp--;
        }
        rp--;
        return rp;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> nums = {-2,0,0,2,2};
    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);
}
