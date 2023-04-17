//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    // https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1

auto getEmptySlot(int grid[N][N]){
        
          struct result {
            int x;
            int y;
        };
        
         for(int row=0; row < N; row++){
            for(int col=0; col < N; col++){
                 if(grid[row][col] == 0){
                    return result {row, col};
                 }
            }
        }
        
        return result {-1 ,-1};
    }
    
    set<int> getPossibleValues(int grid[N][N], int x, int y){
        
        set<int> result = {1,2,3,4,5,6,7,8,9};
        
        for(int row=0; row < N; row++){
            if(grid[row][y] != 0){
                result.erase(grid[row][y]);
            }
        }
        
        for(int col=0; col < N; col++){
            if(grid[x][col] != 0){
                result.erase(grid[x][col]);
            }
        }
        
        int subRow = x - x % 3;
        int subCol = y - y % 3;
        
        for(int i = subRow; i < subRow + 3; i++){
            for(int j = subCol; j < subCol + 3; j++){
                 if(grid[i][j] != 0){
                    result.erase(grid[i][j]);
                }   
            }
        }
        
        return result;
    }
    
    
    bool solveSudokuBacktrackingAlgorithm(int grid[N][N]){
        auto pos = getEmptySlot(grid);
        
        int row = pos.x;
        int col = pos.y;
    
         
        if(row == -1 && col == -1){
            // no slots left
            return true;
        }
        
        set<int> values = getPossibleValues(grid, row, col);
        
                    
                    for(int value : values){
                    
                        grid[row][col] = value;
                        
                        if(solveSudokuBacktrackingAlgorithm(grid)){
                            return true;
                        }
                        
                        grid[row][col] = 0;
                    }
                    
        
        return false;
    }

    bool SolveSudoku(int grid[N][N]){
        
       if(solveSudokuBacktrackingAlgorithm(grid)){
                        return true;
                    }
                    else{
                        return false;
                    }
        
    }
    
    // Function to print grids of the Sudoku.
    
    void printGrid (int grid[N][N]) 
    {
        for(int i=0; i < N; i++){
            for(int j=0; j < N; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends
