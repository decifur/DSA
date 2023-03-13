#include <iostream>
using namespace std;
int max_val(int arry[], int num);
int min_val(int arry[], int num);
int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    int arr[n];
    cout<<"Enter the elements of the array : \n";
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << "Minimum element is : " << min_val(arr,n) << endl;
    cout << "Maximum element is : " << max_val(arr,n) << endl;
    return 0;
}
int max_val(int arry[], int num)
{
    int max = arry[0];
    for(int i=1;i<num;i++)
    {
        if(max < arry[i])
            max = arry[i];
    }
    return max;
}
int min_val(int arry[], int num)
{
    int min = arry[0];
    for(int i=1;i<num;i++)
    {
        if(min > arry[i])
            min = arry[i];
    }
    return min;
}
