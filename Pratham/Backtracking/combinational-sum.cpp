//{ Driver Code Starts
//Initial template for C++

// https://practice.geeksforgeeks.org/problems/combination-sum-1587115620

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
    
  private:
  
    void solve(vector<int> &A, int sum, vector<vector<int>> &result, vector<int> comb, int start){
        
        if(sum == 0){
                // equal
                result.push_back(comb);
                return;
            }
            
        for(int i = start; i < A.size(); i++){
            if(i > 0 && A[i] == A[i-1]){
                // skip duplicate elements
                continue;
            }
            
            if(sum - A[i] < 0){
                break;
            }
            
             comb.push_back(A[i]);
                solve(A , sum - A[i] ,result , comb, i);
                comb.pop_back();
                
        }
    }
    
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<vector<int>> result;
      
      sort(A.begin(), A.end());
        solve(A, B, result, {}, 0);
        
        return result;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends