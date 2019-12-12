//
//  main.cpp
//  Flood_Fill
//
//  Created by Sharon He on 12/12/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int oldColor = image[sr][sc];
        if(newColor == oldColor)
        {
            return image;
        }
        floodFillUtil(image,sr,sc,oldColor,newColor);
        return image;
    }
private:
    void floodFillUtil(vector<vector<int>>& image, int cr, int cc, int oldColor, int newColor)
    {
        
        if(image[cr][cc] != oldColor)
        {
            return;
        }
        
        image[cr][cc] = newColor;
        
        if(cr+1<image.size())
        {
            floodFillUtil(image,cr+1,cc,oldColor,newColor);
        }
        if(cr-1>=0)
        {
            floodFillUtil(image,cr-1,cc,oldColor,newColor);
        }
        if(cc+1<image[0].size())
        {
            floodFillUtil(image,cr,cc+1,oldColor,newColor);
        }
        if(cc-1>=0)
        {
            floodFillUtil(image,cr,cc-1,oldColor,newColor);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
