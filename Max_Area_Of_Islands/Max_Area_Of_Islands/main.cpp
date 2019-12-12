//
//  main.cpp
//  Leetcode #695: Max_Area_Of_Islands
//
//  Created by Sharon He on 12/12/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> parentId;
    vector<int> area;
    int root(int p)
    {
        while(parentId[p]!=p)
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
            if(area[r1]>=area[r2])
            {
                parentId[r2] = r1;
                area[r1] += area[r2];
            }
            else
            {
                parentId[r1] = r2;
                area[r2] += area[r1];
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea = 0;
        
        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j<grid[0].size(); j++)
            {
                parentId.push_back(i*grid[0].size()+j);
                area.push_back(1);
            }
        }
        
        if(grid.size()>=2 && grid[0].size()>=2)
        {
            for(int i = 0; i<grid.size()-1; i++)
            {
                for(int j = 0; j<grid[0].size()-1; j++)
                {
                    if(grid[i][j]==0)
                    {
                        parentId[i*grid[0].size()+j] = -1;
                    }
                    else
                    {
                        if(grid[i][j+1]==1)
                        {
                            unite(i*grid[0].size()+j,i*grid[0].size()+j+1);
                        }
                        if(grid[i+1][j]==1)
                        {
                            unite(i*grid[0].size()+j,(i+1)*grid[0].size()+j);
                        }
                    }
                }
            }
        }
        if(grid[0].size()>=2)
        {
            int i = grid.size()-1;
            for(int j = 0; j<grid[0].size()-1; j++)
            {
                if(grid[i][j]==0)
                {
                    parentId[i*grid[0].size()+j] = -1;
                }
                else
                {
                    if(grid[i][j+1]==1)
                    {
                        unite(i*grid[0].size()+j,i*grid[0].size()+j+1);
                    }
                }
            }
        }
        if(grid.size()>=2)
        {
            int j = grid[0].size()-1;
            for(int i = 0; i<grid.size()-1; i++)
            {
                if(grid[i][j]==0)
                {
                    parentId[i*grid[0].size()+j] = -1;
                }
                else
                {
                    if(grid[i+1][j]==1)
                    {
                        unite(i*grid[0].size()+j,(i+1)*grid[0].size()+j);
                    }
                }
            }
        }
        if(grid[grid.size()-1][grid[0].size()-1]==0)
        {
            parentId.back() = -1;
        }
        
        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j<grid[0].size(); j++)
            {
                if(parentId[i*grid[0].size()+j] != -1)
                {
                    maxArea = (maxArea<area[i*grid[0].size()+j])?area[i*grid[0].size()+j]:maxArea;
                }
            }
        }
        return maxArea;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
