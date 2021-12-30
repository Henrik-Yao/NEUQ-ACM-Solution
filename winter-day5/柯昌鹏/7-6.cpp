#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    while(cin>>n)//多组数据
    {
    int a[n+1]={10000},l,r,k,mid,m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);//用sort之前还是初始化一下数组
    for(int i=1;i<=n;i++) 
    {
        cout<<a[i];
        if(i!=n) cout<<" "; 
    }
    cout<<endl;
    cin>>m;
    while(m--)
    {
        cin>>k;
        l=1,r=n;
    while(l<r)
    {
        mid=l+(r-l)/2;
        if(a[mid]>=k) r=mid;
        else l=mid+1;
    }
    if(a[l]==k)
    {
        cout<<l;
        if(m) cout<<" ";
    }
    else 
    {
        cout<<"0";
        if(m) cout<<" ";
    }
    }
    cout<<endl;
    }
    return 0;
}