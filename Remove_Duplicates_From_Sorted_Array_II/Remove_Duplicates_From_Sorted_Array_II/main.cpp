//
//  main.cpp
//  Remove_Duplicates_From_Sorted_Array_II
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
        if(n<=2){return n;}
        int i = 2;
        int j = 2;
        while(j<n && i<n){
            if(nums[j-2]==nums[j-1]){
                while(nums[i]==nums[i-1]){
                    i++;
                    if(i>=n){return j;}
                }
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
