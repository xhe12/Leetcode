//
//  main.cpp
//  Squres_of_a_Sorted_Array
//
//  Created by Sharon He on 1/2/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i;
        for(i=0; i<A.size(); i++){
            if(A[i]>=0){
                break;
            }
        }
        vector<int> sq;
        sortSquares(A,sq,i,i-1);
        
        return sq;
    }
    
    void sortSquares(const vector<int>& A, vector<int>& sq, int pr, int pl){
        while(true){
            if(pr>=A.size() && pl>=0){
                sq.push_back(pow(A[pl],2));
                pl--;
            }
            else if(pr<A.size() && pl<0){
                sq.push_back(pow(A[pr],2));
                pr++;
            }
            else if(pr<A.size() && pl>=0){
                if(pow(A[pr],2)>pow(A[pl],2)){
                    sq.push_back(pow(A[pl],2));
                    pl--;
                }
                else{
                    sq.push_back(pow(A[pr],2));
                    pr++;
                }
            }
            else{
                return;
            }
        }
        return;
    }
};
int main(int argc, const char * argv[]) {
    vector<int> A = {-1,0,3};
    Solution sol;
    vector<int> sorted = sol.sortedSquares(A);
    return 0;
}
