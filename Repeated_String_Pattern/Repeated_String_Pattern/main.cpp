//
//  main.cpp
//  Repeated_String_Pattern
//
//  Created by Sharon He on 1/3/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = (int)s.size();
        if(n==1){
            return false;
        }
        bool global_pattern = false;
        bool cur_pattern = true;
        for(int pattern_length = 1; pattern_length<=n; pattern_length++){
            if(n % pattern_length == 0){
                for(int i = 1; i<(n/pattern_length); i++){
                    cur_pattern = true;
                    for(int j = 0; j<pattern_length; j++){
                        if(s[i*pattern_length+j]!=s[j]){
                            cur_pattern = false;
                            break;
                        }
                    }
                    if(cur_pattern==false){
                        break;
                    }
                }
            }
            global_pattern = (global_pattern || cur_pattern);
            if(global_pattern == true){
                break;
            }
        }
        return global_pattern;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
