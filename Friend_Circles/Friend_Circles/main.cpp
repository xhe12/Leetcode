//
//  main.cpp
//  Leetcode #547: Friend_Circles
//
//  Created by Sharon He on 12/11/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    vector<int> sz;
    vector<int> parentId;
    
    int root(int p)
    {
        while(p!=parentId[p])
        {
            parentId[p] = parentId[parentId[p]];
            p = parentId[p];
        }
        return p;
    }
    
    void unite(int p, int q)
    {
        int r1 = root(p);
        int r2 = root(q);
        if(r1!=r2)
        {
            if(sz[r1]>=sz[r2])
            {
                parentId[r2] = r1;
                sz[r1] += sz[r2];
            }
            else
            {
                parentId[r1] = r2;
                sz[r2] += sz[r1];
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& M) {
        
        if(M.size() == 1)
        {
            return 0;
        }
        
        for(int i = 0; i<M.size(); i++)
        {
            sz.push_back(1);
            parentId.push_back(i);
        }
        
        for(int i = 0; i<M.size(); i++)
        {
            for(int j = i+1; j<M.size();j++)
            {
                if(M[i][j]==1)
                {
                    unite(i,j);
                }
            }
        }
        unordered_set<int> circleSet;
        for(int i = 0; i<M.size(); i++)
        {
            circleSet.insert(root(i));
        }
        return circleSet.size();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
