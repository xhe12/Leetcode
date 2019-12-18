//
//  main.cpp
//  Leetcode #139: Word_Break
//
//  Created by Sharon He on 12/17/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;

class Solution{
public:
    bool wordBreak(string s, vector<string> &wordDict){
        unordered_set<string> dict;
        vector<vector<bool>> validationChart(s.length(),vector<bool>(s.length(),false));
        for(int i = 0; i<wordDict.size(); i++)
        {
            dict.insert(wordDict[i]);
        }
        for(int i=0; i<s.length(); i++)
        {
            for(int j=i; j<s.length();j++)
            {
                string str = s.substr(i,j-i+1);
                auto itr = dict.find(str);
                validationChart[j][i] = (itr!=dict.end());
            }
        }
        bool ans = false;
        return breakable(validationChart, 0);

    }
    
    bool wordBreak_DP(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        for(int i = 0; i<wordDict.size(); i++)
        {
            dict.insert(wordDict[i]);
        }
        vector<bool> isBreakable(s.length(),false);
        
        for(int i = 0; i<s.length(); i++)
        {
            if(dict.find(s.substr(0,i+1))!=dict.end())
            {
                isBreakable[i] = true;
                continue;
            }
            for(int j = 0; j<i; j++)
            {
                if(isBreakable[j] && dict.find(s.substr(j+1,i-j))!=dict.end())
                {
                    isBreakable[i] = true;
                    break;
                }
            }
        }
        return isBreakable[s.length()-1];
    }
private:
    bool breakable(const vector<vector<bool>> &validationChart, int j)
    {
        if(j>=validationChart.size())
        {
            return true;
        }
        for(int i = j; i<validationChart.size(); i++)
        {
            if(validationChart[i][j] && breakable(validationChart, i+1))
            {
                return true;
            }
            
        }
        return false;
    }

};

int main(int argc, const char * argv[]) {
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    Solution sol;
    sol.wordBreak_DP(s, wordDict);
    return 0;
}
