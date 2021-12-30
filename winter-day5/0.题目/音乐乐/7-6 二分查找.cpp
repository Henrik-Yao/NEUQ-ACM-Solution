#include<bits/stdc++.h>
using namespace std;
int a[101],n,m;
int BinarySearch(int a[],int x)
{
    int l=1,r=n,mid;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(a[mid]<=x)
        {
            if(a[mid]==x) return mid;
            else l=mid+1;
        }
        else r=mid-1;
    }
    return 0;
}
int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            if(i==n)
                cout<<a[i]<<endl;
            else
                cout<<a[i]<<' ';
        }
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            int x;
            cin>>x;
            if(i==m)
                cout<<BinarySearch(a,x)<<endl;
            else
                cout<<BinarySearch(a,x)<<' ';
        }
    }
    return 0;
}
