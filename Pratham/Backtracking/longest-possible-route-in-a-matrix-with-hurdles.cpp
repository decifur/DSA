//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
// https://practice.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1
class Solution {
private:

    int longestPathAlgorithm(vector<vector<int>> &matrix, int xs, int ys, int xd, int yd, int count)
        {
            // cout<< xs  << "," << ys << "=" << count << endl;
            
            if(xs == xd && ys == yd){
                // cout<< "WIN"<<endl;
                return count;
            }
            
            int result = -1;
            
            if(xs - 1 >= 0 && matrix[xs - 1][ys] > 0){
                // possible route top
                
                matrix[xs][ys]  = -1; // for Visited
                int t = longestPathAlgorithm(matrix, xs - 1, ys, xd, yd, count + 1);
                matrix[xs][ys]  = 1; // UnVisited
                
                if(t > result){
                    result = t;
                }
            }
            
            if(xs + 1 < matrix.size() && matrix[xs + 1][ys] > 0){
                // possible route bottom
                
                matrix[xs][ys]  = -1; // for Visited
                int t = longestPathAlgorithm(matrix, xs + 1, ys, xd, yd, count + 1);
                matrix[xs][ys]  = 1; // UnVisited
                
                if(t > result){
                    result = t;
                }
            }
            
            if(ys - 1 >= 0 && matrix[xs][ys - 1] > 0){
                // possible route left
                
                matrix[xs][ys]  = -1; // for Visited
              int t = longestPathAlgorithm(matrix, xs, ys - 1, xd, yd, count + 1);
              matrix[xs][ys]  = 1; // UnVisited
              
              if(t > result){
                    result = t;
                }
            }
            
            if(ys + 1 < matrix[xs].size() && matrix[xs][ys + 1] > 0){
                // possible route right
                matrix[xs][ys]  = -1; // for Visited
              int t = longestPathAlgorithm(matrix, xs, ys + 1, xd, yd, count + 1);
              matrix[xs][ys]  = 1; // UnVisited
              
              if(t > result){
                    result = t;
                }
            }
            
            return result;
        }
        
public:
    int longestPath(vector<vector<int>> &matrix, int xs, int ys, int xd, int yd)
    {
        
        if(matrix[xs][ys] == 0){
            return -1;
        }
        
        return longestPathAlgorithm(matrix, xs, ys, xd, yd, 0);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
