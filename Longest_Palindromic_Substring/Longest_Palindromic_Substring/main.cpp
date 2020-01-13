//
//  main.cpp
//  Longest_Palindromic_Substring
//
//  Created by Sharon He on 1/13/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0){return "";}
        if(s.size()==1){return s;}
        vector<vector<bool>> table(s.size(),vector<bool>(s.size()));
        table[0][0] = true;
        int startIndx = 0;
        int maxLen = 1;
        
        for(int i = 1; i<s.size();i++){
            table[i][i] = true;
            if(s[i]==s[i-1]){
                table[i][i-1] = true;
                startIndx = i-1;
                maxLen = 2;
            }
            else{
                table[i][i-1] = false;
            }
        }
        if(s.size()==2){return s.substr(startIndx,maxLen);}
        int diff;
        for(int j = 2; j<s.size(); j++){
            for(int i = 0; i<j-1; i++){
                if(table[j-1][i+1]&&s[j]==s[i]){
                    table[j][i] = true;
                    diff = j-i+1;
                    if(maxLen<diff){
                        maxLen=diff;
                        startIndx = i;
                    }
                }
                else{table[j][i] = false;}
            }
        }
        return s.substr(startIndx,maxLen);
    }
};
int main(int argc, const char * argv[]) {
    Solution sol;
    sol.longestPalindrome("babad");
    return 0;
}
