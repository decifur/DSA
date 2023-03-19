class Solution {

private: 
    void solveNQueensRecursive(vector<string> &board, int col, vector<vector<string>> &results) {
        
        int n = board.size();

            for(int row=0; row < n; row++){
                if(isEmpty(board, col, row)){
                    // empty 
                    board[row][col] = 'Q'; // use this position
                    if(col == (n - 1)){
                        // last column and result found
                        results.push_back(board);
                    }
                    solveNQueensRecursive(board, col + 1, results);   
                    board[row][col] = '.'; // reset position

                }
            }
        }

        bool isEmpty(vector<string> &board, int col, int row){
            int n = board.size();
                   
            for(int i=0; i<col; i++){
                // check on row
                  if(board[row][i] == 'Q'){
                        return false;
                }
            }

            for(int i= row - 1, j= col-1; i >= 0 && j >= 0; i--, j--){
                    // check upper left diagonal
                    if(board[i][j] == 'Q'){
                            return false;
                    }
            }

            for(int i=row + 1, j=col - 1; i < n && j >= 0; i++, j--){
                    // check lower left diagonal
                    if(board[i][j] == 'Q'){
                            return false;
                    }
            }

            return true;          
        }


public:
    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        vector<vector<string>> results;

        solveNQueensRecursive(board, 0, results);

        return results;
    }
};