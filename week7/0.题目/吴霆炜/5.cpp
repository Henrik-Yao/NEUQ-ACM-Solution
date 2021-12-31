#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[1505];
ll w[405],c[405];
int main(){
    int m,n;
    while(cin>>n>>m){
    memset(dp,0,sizeof(dp));
    memset(w,0,sizeof(w));
    memset(c,0,sizeof(c));
    for(int i = 1;i <= n;i++)cin>>w[i];
    for(int i = 1;i <= n;i++)cin>>c[i];
    for(int i = 1;i <= n;i++){
        for(int j = m;j >= 1;j--){
            if(j >= w[i])
            dp[j] = max(dp[j],dp[j - w[i]] + c[i]);
        }
    }
    cout<<dp[m]<<endl;
    }
    return 0;
}