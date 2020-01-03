//
//  main.cpp
//  Leetcode #28: Implement_strStr
//
//  Created by Sharon He on 1/3/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()<=0){
            return 0;
        }
        int i = 0, j = 0, k = 0;
        while(j<haystack.size() && k<needle.size()){
            while(haystack[j]==needle[k] && j<haystack.size() && k<needle.size()){
                j++;
                k++;
            }
            if(k>=needle.size()){
                return i;
            }
            else if(j>=haystack.size()){
                return -1;
            }
            else{
                i++;
                j = i;
                k = 0;
            }
        }
        return -1;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
