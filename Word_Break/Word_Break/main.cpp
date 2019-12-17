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
    bool wordBreak_Improve(string s, vector<string> &wordDict){
        unordered_set<string> dict;
        unordered_map<int,int> validString;
        
        for(int i = 0; i<wordDict.size(); i++)
        {
            dict.insert(wordDict[i]);
        }
        for(int i = 0; i<s.size(); i++)
        {
            for(int j = i; j<s.size(); j++)
            {
                string str = s.substr(i,j-i+1);
                auto itr = dict.find(str);
                if(itr!=dict.end())
                {
                    validString[i] = j; // string s[i:j] is a valid string
                }
            }
        }
        return breakableWithMap(validString,0,s.length());
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
    bool breakableWithMap(const unordered_map<int, int> &validString, int j, int n)
    {
        if(j>=n)
        {
            return true;
        }
        
    }
};

int main(int argc, const char * argv[]) {
    string s = "aaaaaaa";
    vector<string> wordDict = {"aaaa","aaa"};
    Solution sol;
    sol.wordBreak(s, wordDict);
    return 0;
}
