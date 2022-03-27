#include <bits/stdc++.h>
using namespace std;
int a[1001],dp[1001];
int main(){
    int n,t;
    cin>>t;
    int flag=1;
    while (t--){
        cin>>n;
        for (int i=1;i<=n;i++)
            cin>>a[i];
        for (int i=1;i<=n;i++)
            dp[i]=1;
        for (int i=1;i<=n;i++)
            for (int j=1;j<i;j++)
                if (a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);
        int ans=-1;
        for (int i=1;i<=n;i++)
            ans=max(ans,dp[i]);
        cout<<ans<<endl;
        if (t)cout<<endl;
    }
    return 0;
}