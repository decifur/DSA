//{ Driver Code Starts
// Initial template for C++
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    
    void findPathRecursive(vector<vector<int>> &matrix, int n, int x, int y, vector<string> &results, string positions) {
        
        if(x == n-1 && y == n-1){
            // break condition
            results.push_back(positions);
            positions = "";
            return;
        }
        
        if(x != 0 && matrix[x-1][y] == 1){
            // UP
            matrix[x-1][y] = 0;
            findPathRecursive(matrix, n, x-1, y, results, positions + "U");
            matrix[x-1][y] = 1;
        }
        
        if(x != n-1 && matrix[x+1][y] == 1){
            // DOWN
            matrix[x+1][y] = 0;
            findPathRecursive(matrix, n, x+1, y, results, positions + "D");
            matrix[x+1][y] = 1;
        }
        
        if(y != 0 && matrix[x][y-1] == 1){
            // LEFT
            matrix[x][y-1] = 0;
            findPathRecursive(matrix, n, x, y-1, results, positions + "L");
            matrix[x][y-1] = 1;
        }
        
        if(y != n-1 && matrix[x][y+1] == 1){
            // RIGHT
            matrix[x][y+1] = 0;
            findPathRecursive(matrix, n, x, y+1, results, positions + "R");
            matrix[x][y+1] = 1;
        }
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> results;
        
        if(m[0][0] == 1){
            m[0][0] = 0; // initial position
            findPathRecursive(m, n, 0, 0, results, "");
        }

        return results;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends