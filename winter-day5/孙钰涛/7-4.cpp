#include<bits/stdc++.h>
using namespace std;
int cnt=0,n,a[1001],x;
int l,r;

int find()
{
    while (l<=r)
    {
        cnt++;
        int mid=(l+r)/2;
        if(x==a[mid]) return mid;
        if(x>a[mid]) l=mid+1;
        else r=mid-1;
    }
    return -1;
}

int main()
{
    
    cin>>n;
    l=0;
    r=n-1;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>x;
    cout<<find()<<"\n"<<cnt;
    return 0;
}