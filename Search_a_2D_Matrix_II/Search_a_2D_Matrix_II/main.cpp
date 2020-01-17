//
//  main.cpp
//  Search_a_2D_Matrix_II
//
//  Created by Sharon He on 1/15/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int totalRow = matrix.size();
        if(totalRow==0){return false;}
        int totalCol = matrix[0].size();
        
        pair<int,int> pivot(totalRow-1,0);
        
        while(pivot.first>=0 && pivot.second>=0){
            if(matrix[pivot.first][pivot.second]>target){
                pivot.first -= 1;
            }
            else if(matrix[pivot.first][pivot.second]<target){
                pivot.second += 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
