#include <bits/stdc++.h>
using namespace std;
void min_diff(int arr[], int num, int stud);
int main()
{
    int num,students;
    cout<<"Enter the size of array : ";
    cin>>num;
    int arr[num];
    cout<<"Enter the elements of the array : ";
    for(int i=0;i<num;i++)
        cin>>arr[i];
    cout<<"Enter the no. of students : ";
    cin>>students;
    sort(arr,arr + num);
    min_diff(arr,num,students);
    return 0;
}
void min_diff(int arr[], int num, int stud)
{
    int x = num - stud, y = num-1, diff = 99999, temp;
    while(x>=0)
    {
        temp = arr[y] - arr[x];
        if(temp<diff)
            diff = temp;
        x--;
        y--;
    }
    cout << "Minimum Difference is : " <<diff;
}