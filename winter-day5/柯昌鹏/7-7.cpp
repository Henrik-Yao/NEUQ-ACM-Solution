#include <bits/stdc++.h>
using namespace std;

int n,m,a[100100]={10000};

bool check(int k)
{
    // int i,cnt=1,last;
     //i的初值代表第一个牛舍的位置已经被占据，从第一个牛舍开始往后模拟放牛的过程
    // last=1;
    // while(last<=n)//这里还没有搞清楚开始的点以及结束条件
    // {
    //   i++;
    //   if(a[i]-a[last]>=k)
    //   {
    //     last=i;
    //     cnt++;  
    //   }
    // }
    int last=1,cnt=1;
    for(int i=2;i<=n;i++)
    {
      if(a[i]-a[last]>=k)
      {
        last=i;
        cnt++;
      }
    }
    if(cnt>=m) return true;
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int ans=-1;
    int l=1,r=a[n]-a[1],mid=0;
    while(l<=r)
    {
      mid=l+(r-l)/2;
      if(check(mid))
      {
        ans=mid;
        l=mid+1;
      }
      else r=mid-1;
    }
    cout<<ans;
    return 0;
}