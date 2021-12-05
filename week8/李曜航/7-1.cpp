//0 2 5
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
/*
void print(int a)
{
    printf("\n%d:\n",a);
    for(int i=1;i<=24;i++)
    {
        for(int j=i;j<=24;j++)
        {
            if(dp[i][j])
                printf("dp[%d][%d]:%d  ",i,j,dp[i][j]);
        }
        // printf("\n");
    }
}
*/

int main()
{
    // freopen("read.in","r",stdin);
    // freopen("out","w",stdout);
    int t = read();
    while(t--)
    {
        int dp[99][99] = {0};
        int mx = 0;
        int n = read();
        for(int i=1;i<=n;i++)
        {
            int a = read(), b = read();
            dp[a][b] = 1;
        }
        // print(0);
        for(int i=1;i<=24;i++)
        {
            for(int k=1;k<=i;k++)
            {
                dp[0][i] = max( dp[0][i], dp[0][k]+dp[k][i] );
            }
            // print(i);
        }
        cout<<n-dp[0][24]<<endl;
    }
}