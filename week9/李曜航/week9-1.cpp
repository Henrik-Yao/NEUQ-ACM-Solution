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

int main()
{
    // freopen("read.in","r",stdin);
    long long int dp[100];

    dp[1] = 1;
    dp[2] = 2;// 1 1 / 2
    dp[3] = 4;// 1 + 1 1 /1 + 2/ 2 + 1 / 3
    //1: dp[n-1]
    //2: dp[n-2]
    //3: dp[n-3]

    /*1111
    112
    121
    211
    22
    13
    31*/
    
    for(int i=4;i<=60;i++)
    {
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }

    int n = 0;
    while(cin>>n)
    {
        printf("%lld\n",dp[n]);
    }

}