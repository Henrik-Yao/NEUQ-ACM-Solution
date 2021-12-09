#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int a[1000010];
int dp[1000010];
int main()
{
    // freopen("read2.in","r",stdin);

    int n = read();
    memset(dp,0x7f,sizeof(dp));
    for(int i=1;i<=n;i++)
        a[i] = read();
    dp[1] = 0;
    
    int maxnext = 0;
    for(int i=1;i<=n;i++)
    {
        if(i+a[i]>=n){cout<<dp[i]+1<<endl;return 0;}
        
        if(a[i]>0 && i+a[i]>maxnext)
        for(int j=i+1;j<=i+a[i]&&j<n;j++)
 			dp[j] = min(dp[j],dp[i]+1);
        
        maxnext = max(maxnext, i + a[i]);
    }
}