//
//  main.cpp
//  Leetcode #39: Combination Sum.
//
//  Created by Sharon He on 11/26/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        int remains = target;
        vector<int> cur;
        vector<vector<int>> combination;
        dfs(candidates,remains,cur,combination);
        return combination;
        
    }
private:
    void dfs(const vector<int>& candidates, int &remains, vector<int> &cur, vector<vector<int>> &combination)
    {
        if (remains == 0)
        {
            combination.push_back(cur);
            return;
        }
        if (remains < 0)
        {
            return;
        }
        
        for (auto x: candidates)
        {
            if(cur.size()==0 || x >= cur.back())
            {
                cur.push_back(x);
                remains -= x;
                dfs(candidates,remains,cur,combination);
                cur.pop_back();
                remains += x;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
