#include <iostream>
#include <string>
using namespace std;
string str_lower(string str);
string is_ab12(string str);
bool is_Palindrome(string str);
int main()
{
    string str;
    cout << "Enter the String : ";
    getline(cin,str);
    cout << is_Palindrome(is_ab12(str_lower(str)));
    return 0;
}
string str_lower(string str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>=65 && str[i]<=90)
            str[i] += 32;
    }
    return str;
}
string is_ab12(string str)
{
    string str1;
    for(int i=0;str[i]!='\0';i++)
    {
        if((str[i]>=97 && str[i]<=122) || (str[i]>=48 && str[i]<=57))
            str1+= str[i];
    }
    return str1;
}
bool is_Palindrome(string str)
{
    for(int i=0;i<str.length();i++)
        cout<<"str = "<<i<<" "<<str[i]<<endl;
    int token = str.length()-1;
    for(int i=0; i<str.length();i++)
    {
        if(str[token] != str[i])
            return false;
        token--;
    }
    return true;
}