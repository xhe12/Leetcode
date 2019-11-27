//
//  main.cpp
//  KConcatenationMaximumSum
//
//  Created by Sharon He on 11/21/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    long kConcatenationMaxSum(vector<int>& arr, int k) {
        int limit = 1e9 + 7;
        long maxSum = maxSubSum(arr,1);
        
        if (k==1)
        {
            return maxSum % limit;
        }
        
        long maxSum2 = maxSubSum(arr,2) % limit;
        long middleSum = accumulate(arr.begin(),arr.end(),0) % limit;
        if (middleSum >0)
        {
            maxSum2 = (maxSum2 + middleSum*(k-2)) % limit;
        }
        maxSum = max(maxSum,maxSum2) % limit;
        return maxSum;
    }
    
private:
    long maxSubSum(const vector<int>& arr, int k)
    {
        // Kane's algorithm
        int currentMax = 0;
        int globalMax = 0;
        
        maxSubSumWithoutRepo(arr, currentMax, globalMax);
        if (k==1)
        {
            return globalMax;
        }
        if (k==2)
        {
            maxSubSumWithoutRepo(arr, currentMax, globalMax);
        }
        return globalMax;
    }
    
    void maxSubSumWithoutRepo(const vector<int> &arr, int &currentMax, int &globalMax)
    {
        for (int i = 0; i<arr.size();++i)
        {
            currentMax = max(0,currentMax+arr[i]);
            globalMax = max(globalMax,currentMax);
            
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {-5,-2,0,0,3,9,-2,-5,4};
    int k = 5;
    Solution Sol;
    cout<< Sol.kConcatenationMaxSum(arr, k)<<endl;
    return 0;
}
