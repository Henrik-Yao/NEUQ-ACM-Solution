#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int room;
    while(cin>>n>>room){
    int w[500],v[1600];
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    int dp[500][1600];
    memset(dp,0,sizeof(dp));
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=room;j++){
         if(w[i]>j)dp[i][j]=dp[i-1][j];
        else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            if(dp[i][j]>ans)ans=dp[i][j];
    }
    }
    cout<<ans<<endl;
    }
    return 0;
}
