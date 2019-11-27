//
//  main.cpp
//  Longest_Subsequence_of_Given_Difference
//
//  Created by Sharon He on 11/18/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int sum = 1;
        int target;
        unordered_map<int, int> subSum;
        subSum[arr[0]] = 1;
        
        for (int i = 1; i < arr.size(); ++i)
        {
            target = arr[i] - difference;
            auto valItr = subSum.find(target);
            if ( valItr == subSum.end())
            {   // When target is not found
                subSum[arr[i]] = 1;
            }
            else
            {
                subSum[arr[i]] = valItr->second + 1;
            }
            
            if (sum < subSum[arr[i]])
            {
                sum = subSum[arr[i]];
            }
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    char town[] = "Beijing";
    cout << &town[0]<<"\n";
    
    vector<int> arr = {1,2,3,4};
    int d = 1;
    Solution sol;
    int sum = sol.longestSubsequence(arr,d);
    cout << sum << "\n";
    
    return 0;
}
