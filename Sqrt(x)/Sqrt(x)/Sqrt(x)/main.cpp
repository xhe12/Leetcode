//
//  main.cpp
//  Leetcode #69: Sqrt(x)
//
//  Created by Xuan He on 12/8/19.
//  Copyright © 2019 Xuan He. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        
        int root;
        split(x,left,right,root);
        return root;
    }
    
private:
    void split(const int &x,int left,int right, int &root)
    {
        int middle = (right-left)/2;
        if(pow(left,2)-x==0)
        {
            root = left;
            return;
        }
        else if(pow(right,2)-x==0)
        {
            root = right;
            return;
        }
        else if(middle<=0)
        {
            root = left;
            return;
        }
        
        if((pow(left,2)-x)*(pow(middle+left,2)-x)<=0)
        {
            split(x,left,middle+left,root);
        }
        else
        {
            split(x,middle+left,right,root);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
