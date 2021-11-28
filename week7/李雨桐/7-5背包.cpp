#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005]={0};
int vol[1005];
int val[1005];

int main()
{
    int n,v,ans=0;
    memset(dp,0,sizeof(dp));
    cin>>n>>v;
    for(int i=1;i<=n;i++)
        cin>>vol[i]>>val[i];

    for(int i=1;i<=n;i++)
        for(int j=0;j<=v;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j>=vol[i])
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-vol[i]]+val[i]);
                if(dp[i][j]>ans)
                    ans = dp[i][j];
            }

        }

    cout<<ans<<endl;
    return 0;
}

