#include <iostream>
using namespace std;
void cmn_arr(int A[], int B[], int C[], int n1, int n2, int n3)
        {
            /*
                ****                 >>
                                        common from two - ***       >>
                ---*--**-------      >>                                common from 3 - ** (Ans)
                                                          !!*!!*!   >>
            */
            int arr[n1];
            int count=-1;
            //comparing smallest and largest
            for(int i=0;i<n1;i++)// 4 5 5
            {
                for(int j=0;j<n2 && i<n1;j++)// 3 4 5 5 10
                {
                    if(A[i]==B[j])
                    {
                        arr[++count]=A[i];
                        i++;
                    }
                }
            }// arr - 4 5 5 & count - 2
            int size_arr=count;
            int arr2[size_arr+1];
            int count2=-1;
            //comparing obtained common arr with given 3rd array 
            for(int i=0;i<=size_arr;i++)// 4 5 5
            {
                for(int j=0;j<n3 && i<=size_arr;j++)// 5 5 10 20
                {
                    if(arr[i]==C[j])
                    {
                        arr2[++count2]=arr[i];
                        i++;
                    }
                }
            }
            // arr2 - 5 5 & count2 - 1
            for(int i=0;i<=count2;i++)
                cout<<arr2[i]<<" ";
        }
void commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    if(n1<=n2 && n1<=n3)
            {
                if(n2>=n3)
                    cmn_arr(A,B,C,n1,n2,n3);
                else
                    cmn_arr(A,C,B,n1,n3,n2);
            }
            else if(n2<=n1 && n2<=n3)
            {
                if(n1>=n3)
                    cmn_arr(B,A,C,n2,n1,n3);
                else
                    cmn_arr(B,C,A,n2,n3,n1);
            }
            else
            {
                if(n1>=n2)
                    cmn_arr(C,A,B,n3,n1,n2);
                else
                    cmn_arr(C,B,A,n3,n2,n1);
            }
}
int main()
{
    int n1,n2,n3,i;
    cout<<"Enter the size of the three array seperated by space : ";
    cin>>n1>>n2>>n3;
    int A[n1],B[n2],C[n3];
    cout<<"Enter the elements of First array: ";
    for(i=0;i<n1;i++) cin>>A[i];
    cout<<"Enter the elements of Second array: ";
    for(i=0;i<n2;i++) cin>>B[i];
    cout<<"Enter the elements of Third array: ";
    for(i=0;i<n3;i++) cin>>C[i];
    commonElements(A,B,C,n1,n2,n3);
    return 0;
}