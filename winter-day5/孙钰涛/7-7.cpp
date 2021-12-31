#include<bits/stdc++.h>
using namespace std;
int a[100001],n,m;

bool find_ans(int x)
{
    int cnt=m,temp=a[1]+x;
    cnt--;
    for(int i=2;i<=n;i++)
    {
        if(temp<=a[i])
        {
            cnt--;
            temp=a[i]+x;
        }
    }
    if(cnt<=0) return 1;
    else return 0;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=0,r=a[n]-a[1];
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(find_ans(mid)==1) l=mid+1;
        else r=mid-1;
    }
    cout<<r;
    return 0;
}