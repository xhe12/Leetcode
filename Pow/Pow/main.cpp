//
//  main.cpp
//  Pow
//
//  Created by Sharon He on 1/16/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
    double myPowUtil(double x, int n){
        if(n==0){return 1.0;}
        double halfPower = myPowUtil(x,n/2);
        if(n%2==0){return halfPower*halfPower;}
        else{return halfPower*halfPower*x;}
    }
public:
    double myPow(double x, int n) {
        if(n==-2147483648){
            return (1/myPowUtil(x,-(n+1)))*(1/x);
        }
        if(n<0){
            return 1/myPowUtil(x,-n);
        }
        else{
            return myPowUtil(x,n);
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    cout<<sol.myPow(1.0, -2147483648)<<endl;
    int x = 001;
    cout<<x<<endl;
    return 0;
}
