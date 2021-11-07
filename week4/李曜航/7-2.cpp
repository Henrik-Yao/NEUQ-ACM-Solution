#include <bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N = 50;
int dp[N];
signed main()
{
    int n = read();
    dp[1] = 1, dp[2] = 1;
    for(int i=3;i<=45;i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    dp[1] = 0;
    while(n--)
    {
        int m = read();
        printf("%lld\n",dp[m]);
    }
}