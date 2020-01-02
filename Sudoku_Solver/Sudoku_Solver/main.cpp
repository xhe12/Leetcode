//
//  main.cpp
//  Sudoku_Solver
//
//  Created by Sharon He on 12/31/19.
//  Copyright © 2019 Sharon He. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    bool isNRowValid(const vector<vector<char>>& board, int n, int i){
        // n is the nth row
        for(int j = 0; j<9; j++)
        {
            if(board[n][j]== i+'0'){
                return false;
            }
        }
        return true;
    }
    bool isNColValid(const vector<vector<char>>& board, int n, int i){
        // n is the nth column
        for(int j = 0; j<9; j++)
        {
            if(board[j][n]== i+'0'){
                return false;
            }
        }
        return true;
    }
    bool isNBoxValid(const vector<vector<char>>& board, int n, int value){
        // n is the position, the nth element;
        int row = (n-n%9)/9;
        int col = n%9;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                if(board[row-row%3+i][col-col%3+j]== value+'0'){
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudokuUtil(vector<vector<char>>& solution,vector<vector<char>>& board, int position,int i){
        int unfilled = findUnfilled(board,position);
        if(unfilled == -1)
        {
            solution = board;
            return;
        }
        if(isNRowValid(board, (unfilled-unfilled%9)/9,i) &&
           isNColValid(board, unfilled%9,i) &&
           isNBoxValid(board, unfilled,i)){
            
            board[(unfilled-unfilled%9)/9][unfilled%9] = i+'0';
            for(int j=1; j<10; j++){
                solveSudokuUtil(solution,board, unfilled, j);
            }
        }
        board[(unfilled-unfilled%9)/9][unfilled%9] = '.';
    }
    
    int findUnfilled(const vector<vector<char>>& board, int position){
        while(position<81){
            if(board[(position-position%9)/9][position%9]=='.'){
                return position;
            }
            else{
                position += 1;
            }
        }
        return -1;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int position = 0; //initialize the position
        vector<vector<char>> solution;
        for(int i=1; i<10; i++){
            solveSudokuUtil(solution,board,position,i);//Fill the current unfilledPosition to be i
        }
        board = solution;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution sol;
    sol.solveSudoku(board);
    return 0;
}
