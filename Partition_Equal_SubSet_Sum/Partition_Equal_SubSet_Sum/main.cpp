//
//  main.cpp
//  Partition_Equal_SubSet_Sum
//
//  Created by Sharon He on 1/17/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1){return false;}
        
        int halfSum = sum/2;
        vector<bool> prevPartition(halfSum+1);
        vector<bool> curPartition(halfSum+1);
        
        prevPartition[0] = true;
        curPartition[0] = true;
        for(int v = 1; v<=halfSum; v++){
            prevPartition[v] = false;
        }
        
        for(int i = 0; i<nums.size(); i++){
            for(int v=halfSum; v>=1;v--){
                if(v>=nums[i]){
                    curPartition[v] = (prevPartition[v-nums[i]]||prevPartition[v]);
                }
                else{
                    curPartition[v] = prevPartition[v];
                }
                prevPartition[v] = curPartition[v];
            }
            
        }
        return curPartition[halfSum];
    }
    
    bool canPartitionII(vector<int>& nums) {
            const int MAX_NUM = 100;
            const int MAX_ARRAY_SIZE = 200;
            bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
            int sum = 0;
            for (auto n : nums) {
                sum += n;
                bits |= bits << n;
            }
            return !(sum % 2) && bits[sum / 2];
        }
};
int main(int argc, const char * argv[]) {
    //vector<int> nums = {5,2,4};
    //Solution sol;
    //cout<<sol.canPartitionII(nums)<<endl;
    int x = 5;
    int* ptr = &x;
    if(ptr==nullptr){cout<<"OK"<<endl;}
    else{cout<<"it points to something"<<endl;}
    return 0;
}
