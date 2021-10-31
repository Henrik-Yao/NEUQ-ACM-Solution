#include<iostream>
using namespace std;

int arr[100000],temparr[100000];
void mergesort(int arr[],int left,int right)
{
    if (left >= right)
    {
        return;
    } 
    int mid = (left + right)/2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    int x = 0, i = left, j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j]) 
        {
            temparr[x] = arr[i];
            x++;
            i++;
        } 
        else 
        {
            temparr[x] = arr[j];
            x++;
            j++;
        }
    }
    while (i <= mid) 
    {
        temparr[x] = arr[i];
        x++;
        i++;
    }
    while (j <= right) 
    {
        temparr[x] = arr[j];
        x++;
        j++;
    }
    for (int k = left,l = 0; k <= right; k++,l++) {
        arr[k] = temparr[l];
    }
}

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    display(arr,n);
    return 0;
}