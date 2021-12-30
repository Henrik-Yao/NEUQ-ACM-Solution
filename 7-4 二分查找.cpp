#include<bits/stdc++.h>
using namespace std;
int a[1001],cnt=0,n;
int Binary(int a[],int x)
{
    int l=0,r=n-1,flag=0,mid;
    while(l<=r)
    {
        cnt++;
        int mid=(l+r)>>1;
        if(a[mid]<=x)
        {
            if(a[mid]==x) return mid;
            else l=mid+1;
        }
        else r=mid-1;
    }
    return -1;
}

int main()
{
    int x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>x;
    sort(a,a+n);
    cout<<Binary(a,x)<<endl;
    cout<<cnt;
    return 0;
}

