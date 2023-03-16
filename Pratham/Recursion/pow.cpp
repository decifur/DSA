class Solution {
public:
    double myPow(double x, int n) {

        if(n == INT_MAX) {
            return (x == 1) ? 1 : (x == -1) ? -1 : 0; // end of INT_MAX is odd num
        }

        if(n == INT_MIN) {
            return (x == 1) ? 1 : (x == -1) ? 1 : 0; // end of INT_MIN is even num
        }

        if(n < 0){
            n = n * -1; // positive
            x = 1/x; // reverse
        }

        if(n == 0){
            return 1;
        }
        
        if(n % 2 == 0){
            // even power
            return myPow(x * x, n/2);
        }else{
            return x * myPow(x, n-1);
        }
    }
};
