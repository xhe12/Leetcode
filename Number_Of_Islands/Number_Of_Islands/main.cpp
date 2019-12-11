//
//  main.cpp
//  Leetcode #200: Number_Of_Islands
//
//  Created by Sharon He on 12/11/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution{
private:
    vector<int>sz;
    vector<int>parentId;

    int root(int p)
    {
        while(parentId[p]!=p)
        {
            parentId[p] = parentId[parentId[p]];// path compression
            p = parentId[p];
        }
        return p;
    }
    
    bool find(int p,int q)
    {
        //check if p and q have the same root
        int r1 = root(p);
        int r2 = root(q);
        return (r1==r2);
    }
    
    void unite(int p, int q)
    {
        int r1 = root(p);
        int r2 = root(q);
        if(r1==r2)
        {
            return;
        }
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
public:
    int numIslands(vector<vector<char>>& grid){
        
        if(grid.size()==0)
        {
            return 0;
        }
        
        int n = grid[0].size();// total column;
        int N = grid.size()*grid[0].size();
        
        for(int i = 0; i<N; i++)
        {
            sz.push_back(1);
            parentId.push_back(i);// initialize the parentId to be each node itself
        }
        
        if(grid.size()>=2 && grid[0].size()>=2)
        {
            
            for(int i = 0; i<grid.size()-1; i++)
            {
                for(int j = 0; j<grid[1].size()-1;j++)
                {
                    if(grid[i][j]=='0')
                    {
                        parentId[i*n+j] = -1;
                    }
                    else
                    {
                        if(grid[i+1][j] == '1')
                        {
                            unite((i+1)*n+j, i*n+j);
                        }
                        if(grid[i][j+1] == '1')
                        {
                            unite(i*n+j+1, i*n+j);
                        }
                    }
                }
            }
        }
        int j = n-1;
        if(grid.size()>=2)
        {
            // Process the last column but the last element
            
            for(int i = 0; i<grid.size()-1;i++)
            {
                if(grid[i][j]=='0')
                {
                    parentId[i*n+j] = -1;
                }
                else if(grid[i+1][j] == '1')
                {
                    unite((i+1)*n+j, i*n+j);
                }
            }
        }
        int i = grid.size()-1;
        if(grid[0].size()>=2)
        {
            // Process the last row but the last element
            for(int j = 0; j<n-1;j++)
            {
                if(grid[i][j]=='0')
                {
                    parentId[i*n+j] = -1;
                }
                else if(grid[i][j+1] == '1')
                {
                    unite(i*n+j+1, i*n+j);
                }
                
            }
        }
        //Process the last element
        if(grid[i][j]=='0')
        {
            parentId[i*n+j] = -1;
        }
        
    
    // Calculate the total number of roots
    unordered_set<int> rootSet;
        int waterExists = 0;
    for(int i = 0; i<N; i++)
    {
        if(parentId[i]<0)
        {
            rootSet.insert(-1);
            waterExists = 1;
        }
        else
        {
            int r = root(i);
            if(rootSet.find(r)==rootSet.end())
            {
                rootSet.insert(r);
            }
        }
    }
    return rootSet.size()-waterExists;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> grid;

    Solution sol;
    int n = sol.numIslands(grid);
    cout <<n<<endl;
    return 0;
}
