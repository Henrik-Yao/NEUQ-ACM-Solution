#include <bits/stdc++.h>
using namespace std;

void quicksort(int arr[],int begin,int end)
{
    if(begin >= end){return;}
    int i = begin;
    int j = end;
    int temp = arr[begin];
    while(i != j)
	{
        while(arr[j] > temp && i < j){j--;}
        while(arr[i] <= temp && i < j){i++;}
        if(j > i){swap(arr[j],arr[i]);}
    }
    arr[begin] = arr[i];
    arr[i] = temp;
    for(int i = 0;i < n;i++)
	{
        printf("%d ",arr[i]);
    }
    puts("");
    quicksort(arr,begin,i - 1);
    quicksort(arr,i + 1,end);
}
int main()
{
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0;i < n;i++){scanf("%d",&arr[i]);}
    quicksort(arr,0,n - 1);
    for(int i = 0;i < n;i++)
	{
        printf("%d ",arr[i]);
    }
    puts("");
    delete arr;
    return 0;
}
