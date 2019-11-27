//
//  main.cpp
//  MakeArrayStrictlyIncreasing
//
//  Created by Sharon He on 11/22/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        int limit = 2000 + 1;
        vector<int> keep(arr1.size(),limit);
        // swap[j] = Swap[i][j], since there's no need to keep track of all rows of Swap
        vector<int> swap(arr2.size(),1);
        
        keep[0] = 0;
        int keep_temp;
        int swap_temp;
        
        // sort arr2;
        sort(arr2.begin(),arr2.end());
        
        // loop from the second element, since keep[0] = 0, Swap[0][*] = 1;
        for (int i = 1; i < arr1.size(); ++i)
        {
            keep_temp = (arr1[i]>arr1[i-1] ) ? keep[i-1]:limit;
            swap_temp = limit;
            for (int j = 0; j < arr2.size(); ++j)
            {
                if (arr2[j]<arr1[i])
                {
                    swap_temp = min(swap[j],swap_temp);
                }
                else
                {
                    break;
                }
            }
            keep[i] = min(keep_temp,swap_temp);
            
            // Update swap;
            for (int j = 0; j < arr2.size(); ++j)
            {
                keep_temp = (arr2[j]>arr1[i-1] ) ? keep[i-1]+1:limit;
                swap_temp = limit;
                for (int k = 0; k < j; ++k)
                {
                    swap_temp = min(swap[k]+1,swap_temp);
                }
                swap[j] = min(swap_temp,keep_temp);
            }
        }
        
        int globalmin = keep[arr1.size()-1];
        for (int j = 0; j<arr2.size(); ++j)
        {
            globalmin = min(globalmin,swap[j]);
        }
        if (globalmin >= limit)
        {
            return -1;
        }
        else
        {
            return globalmin;
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<int>v{1,2,3,1,2,3,3,4};
    sort(v.begin(),v.end());
    auto last = unique(v.begin(),v.end());
    for (int i:v)
    {
        cout<<i<<" ";
    }
    
    return 0;
}
