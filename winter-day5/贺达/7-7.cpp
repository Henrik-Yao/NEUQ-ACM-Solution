#include<bits/stdc++.h>
using namespace std;

int a[100005];
int n,m;
//检查该距离是否可行
bool check(int x)
{
    int cnt=1;
    int last=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]-a[last]>=x)
        {
            cnt++;
            last=i;  //保存前一个
        }
    }
    if(cnt>=m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int mi=0x3f3f3f3f;
    for(int i=1;i<=n;i++) //找出最小间隔
    {
        mi=min(a[i]-a[i-1],mi);
    }
    int l=mi;
    int r=a[n]-a[1];   //最大间隔
    int ans=r;
    //二分查找
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;//符合条件就记录
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
