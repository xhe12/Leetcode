//
//  main.cpp
//  Leetcode # 17: Letter_Comintations_of_a_Phone_Number
//  Use depth first search and breadth first search
//
//  Created by Sharon He on 11/26/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string &digits)
    {
        vector<vector<char>> map(8);
        map[0] = {'a','b','c'};
        map[1] = {'d','e','f'};
        map[2] = {'g','h','i'};
        map[3] = {'j','k','l'};
        map[4] = {'m','n','o'};
        map[5] = {'p','q','r','s'};
        map[6] = {'t','u','v'};
        map[7] = {'w','x','y','z'};
        
        vector<string> ans;
        string cur;
        int l = 0;
        dfs(digits, map, ans, cur, l);
        return ans;
     }
private:
    void dfs(const string &digits, const vector<vector<char>> &map, vector<string> &ans, string &cur, int &l)
    {
        if (l==digits.length())
        {
            ans.push_back(cur);
            return;
        }
        for(auto alphabet: map[(digits[l]-'0')-2])
        {
            cur.push_back(alphabet);
            l = l+1;
            dfs(digits, map, ans, cur, l);
            cur.pop_back();
            l -= 1;
        }
    }
};

int main(int argc, const char * argv[]) {
    /*
     vector<vector<char>> map(2);
    map[0] = {'a','b','c'};
    map[1] = {'d','e','f'};
     */
    string digits = "23";
    Solution sol;
    vector<string> combinations = sol.letterCombinations(digits);
    for (auto s:combinations)
    {
        cout<<s<<endl;
    }
    return 0;
}
