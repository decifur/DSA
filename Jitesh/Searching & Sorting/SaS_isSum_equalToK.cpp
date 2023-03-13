#include <bits/stdc++.h>
using namespace std;
string Sum_check(int a[],int b[],int n,int k);
int main()
{
    int n,i,k;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int a[n],b[n];
    cout<<"Enter the elements of First Array :";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter the elements of Second Array :";
    for(i=0;i<n;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    cout<<"Enter the value of K : ";
    cin>>k;
    cout<<Sum_check(a,b,n,k);

}
string Sum_check(int a[],int b[],int n,int k)
{
    int i,flag=1;
    for(i=0;i<n;i++)
    {
        if(a[i]+b[n-i]<k)
            flag = 0;
    }
    if(flag == 1)
        return "Yes";
    return "No";
}