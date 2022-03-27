#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int s,int e,int m)
{
    int zz[e-s+1];
    int i,j,k;
    for(k=s;k<=e;k++)zz[k-s]=a[k];

    i=s;j=m+1;
    for(k=s;k<=e;k++)
    {
        if(i>m)
        {
            a[k]=zz[j-s];
            j++;
        }
        else if(j>e)
        {
            a[k]=zz[i-s];
            i++;
        }
        else if(zz[i-s]>zz[j-s])
        {
            a[k]=zz[j-s];
            j++;
        }
        else 
        {
            a[k]=zz[i-s];
            i++;
        }
    }

}
void merge_sort(int a[],int s,int e)
{
    if(s>=e)return ;
    int z=(s+e)/2;
    merge_sort(a,s,z);
    merge_sort(a,z+1,e);
    merge(a,s,e,z);
}
void mergesort(int a[],int s,int e)
{
    merge_sort(a,s,e-1);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int i;
    for(i=0;i<n;i++)cin>>a[i];
    mergesort(a,0,n);
    for(i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}