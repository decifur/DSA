#include <iostream>
using namespace std;
int num_ceiling(int arr[],int n,int x);
int num_floor(int arr[],int n,int x);
int main()
{
    int n,x;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the value of x : ";
    cin>>x;
    cout<<"Ceiling is = "<<num_ceiling(arr,n,x)<<endl<<"Floor is = "<<num_floor(arr,n,x);
    return 0;
}
int num_ceiling(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
            return arr[i];
        if(arr[i]<x && arr[i+1]>x)
            return arr[i+1];
        if(arr[n-1]<x)
            return -1;
        if(arr[0]>x)
            return arr[0];
    }
    return 0;
}
int num_floor(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
            return arr[i];
        if(arr[i]>x && arr[i-1]<x)
            return arr[i-1];
        if(arr[0]>x)
            return -1;
        if(arr[n-1]<x)
            return arr[n-1];
    }
    return 0;
}