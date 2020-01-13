//
//  main.cpp
//  Divide_Two_Integers
//
//  Created by Sharon He on 1/13/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if(divisor== INT_MIN){
            return 0;
        }
        int i;
        int temp;
        int ans = 0;
        int abs_divisor = divisor;
        if(abs_divisor<0){abs_divisor = -abs_divisor;}
        int abs_dividend = dividend;
        if(abs_dividend<0){abs_dividend = -abs_dividend;}
        while(abs_divisor <= abs_dividend){
            temp = abs_divisor;
            i = 1;
            while((temp<<1) <= abs_dividend){
                temp = temp<<1;
                i = i<<1;
                if(temp>=(INT_MAX>>1)){break;}
            }
            abs_dividend-=temp;
            ans += i;
        }
        int sign = -1;
        if(dividend>=0 && divisor>=0){
            sign = 1;
        }
        else if(dividend<0 && divisor<0){
            sign = 1;
        }
        return sign*ans;
    }
};
int main(int argc, const char * argv[]) {
    int dvd = -2147483648;
    int dvs = 1;
    Solution sol;
    cout<<sol.divide(dvd,dvs)<<endl;
    
    return 0;
}
