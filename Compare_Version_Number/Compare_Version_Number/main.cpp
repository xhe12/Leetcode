//
//  main.cpp
//  Compare_Version_Number
//
//  Created by Sharon He on 1/16/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1_number = parsing(version1);
        vector<int> v2_number = parsing(version2);
        
        int ptr = 0;
        while(ptr<v1_number.size() && ptr<v2_number.size()){
            if(v1_number[ptr]>v2_number[ptr]){return 1;}
            else if(v1_number[ptr]<v2_number[ptr]){return -1;}
            else{ptr++;}
        }
        if(v1_number.size()>ptr){
            for(int i = ptr; i<v1_number.size();i++){
                if(v1_number[i]>0){return 1;}
            }
        }
        else if(v2_number.size()>ptr){
            for(int i = ptr; i<v2_number.size();i++){
                if(v2_number[i]>0){return -1;}
            }
        }
        return 0;
    }
    
    vector<int> parsing(string &version){
        int temp;
        int i = 0;
        vector<int> result;
        while(i<version.size()){
            temp = 0;
            while(version[i]!='.'&&i<version.size()){
                temp = temp*10+(version[i]-'0');
                i++;
            }
            i++;
            result.push_back(temp);
            
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    string s1 = "1.0.001";
    string s2 = "1";
    Solution sol;
    cout<<sol.compareVersion(s1, s2)<<endl;
    return 0;
}
