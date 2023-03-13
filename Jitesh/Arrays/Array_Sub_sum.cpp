#include <iostream>
using namespace std;
void sub_array(int arry[], int num);
int main()
{
    int n;
    cout << "Enter the Size of array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : ";
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sub_array(arr,n);
    return 0;
}
void sub_array(int arry[], int num)
{
    int n = num;
    int sum=0,temp = 0,a,b;
/*
    1 2 3 4 5 6 7 8             1 2 3 4 5 6 7 8(2-8)     1 2 3 4 5 6 7 8(3-8)   ...
    -------------->(1-8)          ------------>              ---------->            ...
    ------------>(1-7)            ---------->                -------->              ...
    ---------->(1-6)              -------->                  ------>                ...
    -------->(1-5)                ------>                    ---->                  ...
    ------>(1-4)                  ---->                      -->                    ...
    ---->(1-3)                    -->                        >                      ...
    -->(1-2)                      >
    >(1)
*/
    for(int i=0;i<num;i++) // Loop for incrementing i in Arr(i,j) -->> (1-8),(2-8),(3,8)....(8,8)
    {
        while(n!=0)// loop for handling j in Arr(i,j) -->> (1-8),(1-7),(1-6).....(1-1)
        {
            for(int j=i;j<n;j++) // loop for including subsets without first and last elements -->> (2-7),(3-5),(2-4),etc
            {
                temp += arry[j];
                if(temp>sum)
                {
                    sum = temp;
                    a = i; // for storing the index of subset with largest sum
                    b = j; // ,,
                }
            }
            temp = 0;
            n--;
        }
        n=num;
    }
    cout << "Sum = " <<sum <<endl<<"Subaray : ";
    for(int i=a;i<=b;i++)
        cout << arry[i] << " ";
}