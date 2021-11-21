#include<bits/stdc++.h>
using namespace std;
int n,dp[100],t;
int main()
{
    dp[1]=0,dp[2]=1,dp[3]=2;
    for(int i=4;i<=40;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}
