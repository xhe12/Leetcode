//
//  main.cpp
//  Leetcode #3: Longest_Substring_Without_Repeating_Characters
//
//  Created by Sharon He on 1/3/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int i = 0, j = 0;
        unordered_set<char> curSet;
        int minLength = 0;
        while(j<s.size()){
            if(curSet.find(s[j])==curSet.end()){
                curSet.insert(s[j]);
                minLength = (minLength>curSet.size())?minLength:(int)curSet.size();
                j++;
            }
            else{
                curSet.erase(s[i]);
                i++;
            }
        }
        return minLength;
    }
};
int main(int argc, const char * argv[]) {
    string s = "pwwkew";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s)<<endl;
    unordered_set<char> curSet = {'p','w'};
    
    return 0;
}
