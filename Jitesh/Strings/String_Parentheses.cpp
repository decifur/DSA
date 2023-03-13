#include <iostream>
#include <string>
using namespace std;
bool isValid(string str);
int main()
{
    string str;
    cout<<"Enter the Parantheses : ";
    getline(cin,str);
    cout<<isValid(str);
    return 0;
}
bool isValid(string str)
{
    if(str.length()%2!=0)
        return false;
    if(str[0]==')' || str[0]==']' || str[0]=='}')
        return false;
    char arr[100000];
    arr[0] = 'A';
    arr[1] = str[0];
    int s_ptr = 1,a_ptr = 1;
    for(int i=0;str[i]!='\0';i++)
    {
        if((str[s_ptr]-arr[a_ptr]) > 0 && (str[s_ptr]-arr[a_ptr]) < 3)
        {
                a_ptr--;
        }
        else
        {
            arr[a_ptr+1] = str[s_ptr];
            a_ptr++;
        }
        s_ptr++;
    }
    if(a_ptr<=1)
        return true;
    return false;
}