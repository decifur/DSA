#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0) {
            n = abs(n);
            x = 1/x;
        }
        if(n%2==0){
            return myPow(x*x, n/2);
        }
        else{
            return x*myPow(x, n-1);
        }
    }
};

int main() {
    Solution s;
    double x;
    cin>>x;
    int n;
    cin>>n;
    double result = s.myPow(x, n);
    cout << x << " raised to the power of " << n << " is " << result <<endl;
    return 0;
}
