#include <stdio.h>
#include<iostream>
using namespace std;
int num[1000];
void quicksort(int left,int right);
int n;
int main()
{
    int i;
    cin>>n;
    for(i = 0;i < n;i++)
    {
        cin>>num[i];
    }
    quicksort(0,n - 1);
    for(i = 0;i < n;i++)
    {
        cout<<num[i]<<" ";
    }
    return 0;
}
void quicksort(int left,int right)
{
    int temp,t,i,j;
    if(left >= right)
    {
        return;
    }
    temp = num[left];
    i = left;
    j = right;
    while(i < j)
    {
        while(num[j] > temp&&i < j)
        {
            j--;
        }
        while(num[i] <= temp&&i < j)
        {
            i++;
        }
        if(i < j)
        {
            t = num[j];
            num[j] = num[i];
            num[i] = t;
        }
    }
    num[left] = num[i];
    num[i] = temp;
    int k;
    for(k=0;k<n;k++)
    {
        cout<<num[k]<<" ";
    }
    cout<<endl;
    quicksort(left,i - 1);
    quicksort(i + 1,right);
    return;
}