//
//  main.cpp
//  Leetcode #140: Word_Break_II
//
//  Created by Sharon He on 12/18/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
    vector<string> wordBreakII(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        int flag;
        vector<string> allCombinations;
        string curCombination;
        for(int i=0; i<wordDict.size(); i++)
        {
            dict.insert(wordDict[i]);
        }
        vector<vector<int>> separatingIndx(s.length());
        
        for(int i=s.length()-1; i>=0; i--)
        {
            flag = 0;
            if(dict.find(s.substr(i,s.length()-i))!=dict.end())
            {
                separatingIndx[i].push_back(s.length());
                flag = 1;
            }
            for(int j=s.length()-1; j>i; j--)
            {
                if(separatingIndx[i][0]<=s.length() && dict.find(s.substr(i,j-i))!=dict.end())
                {
                    separatingIndx[i].push_back(j);
                    flag = 1;
                }
            }
            if(flag==0)
            {
                separatingIndx[i].push_back(s.length()+1);
            }
        }
        if(separatingIndx[0][0]>=s.length())
        {
            return {};
        }
        else
        {
            findAllValidCombinations(separatingIndx,0,curCombination,allCombinations,s.length(),s);
        }
        return allCombinations;
    }
    
    void findAllValidCombinations(const vector<vector<int>> &separatingIndx, int startIndx, string &curCombination, vector<string> &allCombinations, int n,const string &s)
    {
        if(startIndx>=n)
        {
            allCombinations.push_back(curCombination);
            return;
        }
        for(int k:separatingIndx[startIndx])
        {
            string temp = curCombination;
            curCombination.append(s.substr(startIndx,k-startIndx));
            findAllValidCombinations(separatingIndx, k, curCombination, allCombinations, n, s);
            curCombination = temp;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
