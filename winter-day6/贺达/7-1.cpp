#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    int value;
    for (int i=1; i<n; i++)
    {
        value = arr[i];

        for(int j=0; j<i; j++)
        {
            if( value < arr[j])
            {
                for (int k=i; k>=j; k--)
                {
                    arr[k]=arr[k-1];
                }
                arr[j]=value;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
              cout<<arr[i];
              if(i!=n-1)
              {
                  cout<<" ";
              }
        }
          cout<<endl;
    }
    return;
}

int main()
{
    int n;
    while(cin>>n)
    {
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        insertionSort(a,n);

    }
}
