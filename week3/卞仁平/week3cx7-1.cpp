#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int mm(int l,int r)
{
    if(l==r)return a[l];
    int mid=(l+r)/2;
    int L=mm(l,mid);
    int R=mm(mid+1,r);
    int s1=0;
    int s2=0;
    int ll=-1e9,rr=-1e9;
    int i;
    for(i=mid;i>=l;i--)
    {
        s1+=a[i];
        ll=max(ll,s1);
    }
    for(i=mid+1;i<=r;i++)
    {
        s2+=a[i];
        rr=max(rr,s2);
    }
    return max(max(L,R),max(ll+max(0,rr),max(0,ll)+rr));


}
int main()
{
    cin>>n;
    int i;
    int f=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>=1)f=1;
    }
    if(f==0)cout<<0;
    else 
     cout<<mm(1,n);
}