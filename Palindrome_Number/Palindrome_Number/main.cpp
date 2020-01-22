//
//  main.cpp
//  Palindrome_Number
//
//  Created by Sharon He on 1/22/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){return false;}
        int remainder = x;
        int mod;
        int converted = 0;
        while(remainder>0){
            if(converted>=INT_MAX/10){return false;}
            mod = remainder%10;
            remainder = (remainder-mod)/10;
            converted = converted*10+mod;
        }
        return x==converted;
    }
};
int main(int argc, const char * argv[]) {
    Solution sol;
    cout<<sol.isPalindrome(1000000001)<<endl;
    return 0;
}
