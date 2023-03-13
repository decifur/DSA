#include <iostream>
#include <string>
#include <set>
using namespace std;
bool is_Anagram(string s, string t);
int main()
{
    string s,t;
    cout<<"Enter First String : ";
    getline(cin,s);
    cout<<"Enter Second String : ";
    getline(cin,t);
    cout<<is_Anagram(s,t);
    return 0;
}
bool is_Anagram(string s,string t)
{
    int l1 = s.length(), l2 = t.length(),sum1 = 0,sum2 = 0,i;
    set <char> s_set,t_set,s_rep,t_rep;
    for(i=0;i<l1;i++)
    {
        if(s_set.find(s[i])!=s_set.end())
            s_rep.insert(s[i]);
        s_set.insert(s[i]);
        sum1+=s[i];
    }
    for(i=0;i<l2;i++)
    {
        if(t_set.find(t[i])!=t_set.end())
            t_rep.insert(t[i]);
        t_set.insert(t[i]);
        sum2+=t[i];
    }
    if(s_set == t_set && sum1==sum2 && s_rep == t_rep)
    {
        return true;
    }
    return false;
}