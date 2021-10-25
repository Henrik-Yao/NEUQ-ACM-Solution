#include<bits/stdc++.h>
using namespace std;

set<int> pre;
int cnt_pre[1000005];
set<int> sub;
int cnt_sub[1000005];
int a[1000005];
int main()
{
    int n;
    
    //memset(cnt_pre,0x3f3f3f3f,sizeof(cnt_pre));

    cin>>n;
    for(int i = 1; i <= n;i ++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <=n;i++)
    {
        pre.insert(a[i]);
        cnt_pre[i] = pre.size();
    }
    for(int i = n;i >=1;i--)
    {
        sub.insert(a[i]);
        cnt_sub[i] = sub.size();
    }
    int ans = 0;
    for(int i=0;i<=n;i++)
    {
        ans = max(ans,cnt_pre[i] + cnt_sub[i+1]);
    }
    cout<<ans<<endl;
}
