#include <iostream>
#include <string>
using namespace std;
string rmv_Consecutive(string s);
int main()
{
    string s;
    cout<<"Enter a String : ";
    getline(cin,s);
    cout<<rmv_Consecutive(s);
    return 0;
}
string rmv_Consecutive(string s)
{
    string arr;
    int ptr=0;
    for(int i=0;i<s.length();i++)
    {
        if(i==0)
            arr+=s[i];
        else if(s[i]!=arr[ptr])
        {
            ptr++;
            arr+=s[i];
        }
    }
    return arr;
}