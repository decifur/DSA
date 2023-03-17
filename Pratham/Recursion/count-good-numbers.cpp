#define MOD 1000000007

class Solution {
private: 

long long power(int x, long long n){
    if(n == 0){
            return 1;
        }
        long long ans = power(x, n/2);
        ans *= ans;
        ans %= MOD;
        if(n%2==1){
            ans *= x;
            ans %= MOD;
        }
        return ans;
}

public:

    int countGoodNumbers(long long n) {

        if(n % 2 == 0){
            return (power(5, n/2) * power(4, n/2)) % MOD;
        }
        else{
            return (power(5, ((n+1)/2)) * power(4, ((n-1)/2))) % MOD;
        }
    }
};


/*

n=1 : 5
0,2,4,6,8

n=2 : 20 : 5 * 4

02, 03, 05, 07,
22, 23, 25, 27,
42, 43, 45, 47,
62, 63, 65, 67,
82, 83, 85, 87,

n=3 : 5 * 4 * 5

n=4 : 400 : 5 * 4 * 5 * 4

5, 20, x, 400

TOTAL EVEN: 5
TOTAL PRIME: 4

n = 50 : 5^25 * 4^25


*/