#include <iostream>
using namespace std;
int search(int arr[],int n,int x,int k);
int main()
{
    int n,k,x;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Enter the value of K : ";
    cin>>k;
    cout<<"Enter the value of x : ";
    cin>>x;
    cout<<search(arr,n,x,k);
    return 0;
}
int search(int arr[],int n,int x,int k)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
            return i;
    }
    return -1;
}