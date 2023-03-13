#include <iostream>
using namespace std;
bool duplicate_num(int arr[],int num);
int main()
{
    int num;
    cout<<"Enter the size of array : ";
    cin>>num;
    int arr[num];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<num;i++)
        cin>>arr[i];
    cout<<duplicate_num(arr,num);
    return 0;
}
bool duplicate_num(int arr[],int num)
{
    for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            if(arr[j]==arr[i])
                return true;
        }
    }
    return false;
}