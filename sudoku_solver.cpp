// not complete
#include<bits/stdc++.h>
using namespace std;

#define UNDEFINED 0
int N = 9;
int grid[9][9] = {{ 3, 1, 6, 5, 7, 8, 4, 9, 2 }, 
                        { 5, 2, 9, 1, 3, 4, 7, 6, 8 }, 
                        { 4, 8, 7, 6, 2, 9, 5, 3, 1 }, 
                        { 2, 6, 3, 0, 1, 5, 9, 8, 7 }, 
                        { 9, 7, 4, 8, 6, 0, 1, 2, 5 }, 
                        { 8, 5, 1, 7, 9, 2, 6, 4, 3 }, 
                        { 1, 3, 8, 0, 4, 7, 2, 0, 6 }, 
                        { 6, 9, 2, 3, 5, 1, 8, 7, 4 }, 
                        { 7, 4, 5, 0, 8, 6, 3, 1, 0 }}; 
bool isSafe(){
    unordered_map<int, int> row[9], col[9], box[3][3];
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            row[r][grid[r][c]] += 1;
            col[c][grid[r][c]] += 1;
            box[r / 3][c / 3][grid[r][c]] += 1;
            if(row[r][grid[r][c]] > 1 || col[c][grid[r][c]] > 1 || box[r / 3][c / 3][grid[r][c]] > 1)
                return false;
        }
    }
    return true;
}
void print(){
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
}
bool solveSudoku(int i, int j){
    if(i == N - 1 && j == N){
        if(isSafe()){
            print();
            return true;
        }
        return false;
    }
    if(j == N){
        j = 0;
        i++;
    }
    if(grid[i][j] != UNDEFINED){
        return solveSudoku(i, j + 1);
    }
    for(int numbers = 1; numbers <= N; numbers++){
        grid[i][j] = numbers;
        if(solveSudoku(i, j + 1)){
            return true;
        }
        grid[i][j] = UNDEFINED;
    }
    return false;
}
int main()  
{  
    // 0 means unassigned cells  
    
     
    if (solveSudoku(0,0) != true)  
        cout << "No solution exists";  
   
    return 0;  
} 