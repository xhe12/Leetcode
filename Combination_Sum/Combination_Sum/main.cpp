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
    vector<vector<int>> combinationSumII(vector<int>& candidates, int target)
    {
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        vector<vector<int>> combinations;
        dfsII(candidates,combinations,cur,target,0);
        return combinations;
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
    void iterative_dfs(const vector<int>& candidates, int target, vector<vector<int>> &combinations)
    {   // this doesn't work as of now
        vector<int> stack;
        stack.push_back(0);
        vector<int> cur;
        int sum = 0;
        int element;
        while(stack.size()>0)
        {
            element = stack.back();
            sum += element;
            stack.pop_back();
            cur.push_back(element);
            if (sum > target)
            {
                sum -= element;
                cur.pop_back();
                continue;
            }
            if (sum == target)
            {
                combinations.push_back(cur);
                cur.pop_back();
                sum -= element;
                continue;
            }
            for (int i:candidates)
            {
                if (i>=element)
                {
                    stack.push_back(i);
                }
            }
        }
        
    }
    void dfsII(const vector<int> &candidates, vector<vector<int>> &combinations, vector<int> &cur, int target, int startIndx)
    {
        if(target<0)
        {
            return;
        }
        if(target == 0)
        {
            combinations.push_back(cur);
            return;
        }
        for(int i = startIndx; i<candidates.size();++i)
        {
            if (i!= startIndx && candidates[i] == candidates[i-1])
            {
                continue;
            }
            cur.push_back(candidates[i]);
            dfsII(candidates,combinations,cur,target-candidates[i],i+1);
            cur.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
