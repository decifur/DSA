class Solution {
public:

    int myAtoi_recursion(string s, int sign, int num,int i) {
        int digit = s[i] - '0';
            if(!s[i] || digit < 0 || digit > 9){
                return num * sign; // end
            }

        if ((num > INT_MAX / 10 || (num == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10))) {
            return sign == 1 ? INT_MAX : INT_MIN; // end
        }

        num = num * 10 + digit;

        return myAtoi_recursion(s, sign, num, ++i);
    }

    int myAtoi(string s) {
        int sign = 1, num = 0, i = 0;

        while(s[i] == ' '){
            i++;
        } 

        if(s[i] == '-' || s[i] == '+'){
            if(s[i] == '-'){
                 sign = -1;
                     }
            i++;
        }

        return myAtoi_recursion(s, sign, num, i);
    }
};