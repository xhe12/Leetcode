//
//  main.cpp
//  Remove_Duplicates_From_Sorted_Array
//
//  Created by Sharon He on 1/6/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0){return 0;}
        if(n==1){return 1;}
        int i = 1;
        int j = 1;
        while(i<n && j<n){
            while(nums[i]==nums[i-1]){
                i++;
                if(i>=n){return j;}
            }
            nums[j] = nums[i];
            i++;
            j++;
        }
        return j;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
