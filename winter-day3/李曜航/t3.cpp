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
int a[105];
int dp[105][105];
int main()
{
    // freopen("read.in","r",stdin);
    int n = read();
    for(int i=1;i<=n;i++)
        a[i] = read();
    sort(a+1,a+1+n);



    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                if()
            }
        }
    }

}