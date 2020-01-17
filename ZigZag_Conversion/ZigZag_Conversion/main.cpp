//
//  main.cpp
//  ZigZag_Conversion
//
//  Created by Sharon He on 1/17/20.
//  Copyright © 2020 Sharon He. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct ZigZagElement{
public:
    char alphabet;
    int row;
    int col;
    ZigZagElement(char e,int r, int c):alphabet(e),row(r),col(c){}
    
    bool operator <(const ZigZagElement& E) const{
        /*if(row < E.row){return true;}
        else if(row == E.row && col < E.col){return true;}
        else{return false;}*/
        return row<E.row;
    }
    bool operator >(const ZigZagElement& E) const{
        return row>E.row;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()==0){return "";}
        if(numRows<=1){return s;}
        vector<ZigZagElement*> ZigZag;
        
        ZigZagElement* E = new ZigZagElement(s[0],0,0);
        ZigZag.push_back(E);
        
        for(int i = 1; i<s.size(); i++){
            int withinGroup = i%(2*numRows-2);
            if(withinGroup!=0&&withinGroup<numRows){
                ZigZagElement* E = new ZigZagElement(s[i],ZigZag[i-1]->row+1,ZigZag[i-1]->col);
                ZigZag.push_back(E);
            }
            else{
                ZigZagElement* E = new ZigZagElement(s[i],ZigZag[i-1]->row-1,ZigZag[i-1]->col+1);
                ZigZag.push_back(E);
            }
        }
        sort(ZigZag.begin(),ZigZag.end());
        string convertedStr;
        for(int i=0; i<s.size(); i++){
            convertedStr.push_back(ZigZag[i]->alphabet);
        }
        return convertedStr;
    }
};
int main(int argc, const char * argv[]) {
    string s = "PAYPALISHIRING";
    Solution sol;
    cout<<sol.convert(s, 3)<<endl;
}
