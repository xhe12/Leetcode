//
//  main.cpp
//  Leetcode #77: Combinations
//
//  Created by Sharon He on 11/27/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        if(k>n)
        {
            return {{}};
        }
        vector<vector<int>> combinations;
        vector<int> cur;
        dfs_combinations(n,k,combinations,cur,1);
        return combinations;
    }
private:
    void dfs_combinations(const int n, int k, vector<vector<int>> &combinations, vector<int> &cur, int startIndx)
    {
        if (k <= 0)
        {
            combinations.push_back(cur);
            return;
        }
        for (int i = startIndx; i<=n; i++)
        {
            cur.push_back(i);
            dfs_combinations(n, k-1, combinations, cur,i+1);
            cur.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
