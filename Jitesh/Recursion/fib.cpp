#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n<=2)
            return 1;
        else
            return fib(n-1)+fib(n-2);
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    Solution obj;
    cout << "Fibonacci series up to " << n << ":\n";
    cout << obj.fib(n);
    return 0;
}
