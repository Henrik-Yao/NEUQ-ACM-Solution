#include <bits/stdc++.h>

using namespace std;
void max_heapify(int arr[], int start, int end) 
{
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)
     { 
        if (son + 1 <= end && arr[son] < arr[son + 1]) 
            son++;
        if (arr[dad] > arr[son]) 
            return;
        else { 
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heap_sort(int arr[], int len) 
{
    
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    
    for(int i=0;i<len;i++) cout<<arr[i]<<" ";
    cout<<endl;
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);        
        for(int i=0;i<len;i++) cout<<arr[i]<<" ";
        cout<<endl;
    }
}
int main() 
{
    int len;
    cin>>len;
    int arr[len];
    for(int i=0;i<len;i++) cin>>arr[i];
    heap_sort(arr, len);
    return 0;
}
