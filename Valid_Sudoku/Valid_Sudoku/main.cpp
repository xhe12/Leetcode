//
//  main.cpp
//  Valid_Sudoku
//
//  Created by Sharon He on 12/31/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int n = 0; n<9; n++){
            if(!isNRowValid(board,n)){
                return false;
            }
            if(!isNColValid(board, n)){
                return false;
            }
            if(!isNBoxValid(board, n)){
                return false;
            }
        }
        return true;
    }
    bool isNRowValid(const vector<vector<char>>& board, int n){
        unordered_set<int> filled;
        int size = 0;
        for(int i = 0; i<9; i++)
        {
            if(board[n][i]!='.'){
                size += 1;
                filled.insert(board[n][i]-'0');
            }
        }
        return filled.size()==size;
    }
    bool isNColValid(const vector<vector<char>>& board, int n){
        unordered_set<int> filled;
        int size = 0;
        for(int i = 0; i<9; i++)
        {
            if(board[i][n]!='.'){
                size += 1;
                filled.insert(board[i][n]-'0');
            }
        }
        return filled.size()==size;
    }
    bool isNBoxValid(const vector<vector<char>>& board, int n){
        unordered_set<int> filled;
        int size = 0;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(board[n-n%3+j][(n%3)*3+i]!='.'){
                    size += 1;
                    filled.insert(board[n-n%3+j][(n%3)*3+i]-'0');
                }
            }
        }
        return filled.size()==size;
    }
};
int main(int argc, const char * argv[]) {
    char c = 0x01;
    vector<int> v = {1,2};
    cout<<v[c]<<endl;
    return 0;
}
