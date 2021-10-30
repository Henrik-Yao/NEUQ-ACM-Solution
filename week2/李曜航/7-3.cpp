#include <bits/stdc++.h>
using namespace std;
int a[1000];
int ass[1000];

void merge(int l, int r, int mid)
{
    int i = l, j = mid+1, k = 0;
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j])
            ass[++k] = a[i++];
        else
            ass[++k] = a[j++];
    }
    while(i<=mid)
        ass[++k] = a[i++];
    
    while(j<=r)
        ass[++k] = a[j++];

    for(int i=0; i<r-l+1; i++)
        a[l+i] = ass[i+1];
}
void merge_sort(int l, int r)
{
    if(l>=r)
        return;
    int mid = (l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);

    merge(l,r,mid);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    merge_sort(1, n);

    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}