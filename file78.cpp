// SudoKu Solver
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(vector<vector<char>>& board, vector<vector<int>>& row, vector<vector<int>>& col, vector<vector<int>>& box){
        for( int i =0; i<9; i++){
            for( int j =0; j<9; j++){
                if(board[i][j] == '.'){
                   for( int num =1; num<=9; num++){
                    int b = (i/3)*3+(j/3);
                    if(!row[i][num] && !col[j][num] && !box[b][num]){
                        board[i][j] = num+'0';
                        row[i][num] = col[j][num]= box[b][num] =1;
                        if( solve(board, row, col, box)) return true;
                        board[i][j]='.';
                        row[i][num]= col[j][num]=box[b][num]=0;
                    }
                   } 
                   return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(10,0));
        vector<vector<int>> col(9, vector<int>(10,0));
        vector<vector<int>> box(9, vector<int>(10,0));
        for( int i =0; i<9; i++){
            for( int j =0; j<9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j]-'0';
                    int b = (i/3)*3 +(j/3);
                    row[i][num]=1;
                    col[j][num] =1;
                    box[b][num]=1;
                }
            }
        }
        solve( board, row, col, box);
    }
};