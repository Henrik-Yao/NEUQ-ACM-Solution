#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a[1001],dp[1001];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=1000;k++)
            dp[k]=1;
        int mmax=-1;
        cin>>m;
        for(int j=1;j<=m;j++)
            cin>>a[j];
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<j;k++)
            {
                if(a[j]>a[k]) dp[j]=max(dp[j],dp[k]+1);
            }
            mmax=max(mmax,dp[j]);
        }
        cout<<mmax;
        if(i!=n) cout<<"\n\n";
        else cout<<"\n";
    }
    return 0;
}