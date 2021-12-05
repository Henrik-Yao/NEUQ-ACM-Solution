#include <bits/stdc++.h>
using namespace std;
int dp[405][1505]={0};
int v[405],w[405];
int n,c;
void getdp(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=c;j++)
            if(w[i]>j) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
}
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>c){
        for(int i=1;i<=n;i++) cin>>w[i];
        for(int i=1;i<=n;i++) cin>>v[i];
        getdp();
        cout<<dp[n][c]<<endl;
    }
}
