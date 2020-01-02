//
//  main.cpp
//  Generate_Parenthesis
//
//  Created by Xuan He on 12/23/19.
//  Copyright © 2019 Xuan He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string curString;
        vector<string> combination;
        
        generateParenthesisByDFS(n,curString,combination,0);
        return combination;
    }
    void generateParenthesisByDFS(int nLeft, string &curString, vector<string> &combination, int nRight)
    {
        if(nLeft==0 && nRight==0)
        {
            combination.push_back(curString);
            return;
        }
        if(nLeft>0)
        {
            curString.push_back('(');
            generateParenthesisByDFS(nLeft-1, curString, combination, nRight+1);
            curString.pop_back();
        }
        if(nRight>0)
        {
            curString.push_back(')');
            generateParenthesisByDFS(nLeft, curString, combination, nRight-1);
            curString.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
