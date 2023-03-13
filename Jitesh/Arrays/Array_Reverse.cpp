#include <iostream>
using namespace std;
void reverse(int arry[],int num);
int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i=0;i<n;i++)
        cin >> arr[i];
    reverse(arr,n);
    return 0;
}
void reverse(int arry[], int num)
{
    int temp,n = num/2,token = num-1;
    for(int i=0;i<n;i++)
    {
        temp = arry[i];
        arry[i] = arry[token];
        arry[token] = temp;
        token--;
    }
    cout << "Reversed Array : ";
    for(int j=0;j<num;j++)
        cout << arry[j] <<" ";
}