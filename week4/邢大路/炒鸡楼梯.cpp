#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int dp[100];
    dp[1]=0,dp[2]=1;
    dp[3]=2;
    for(int i=4;i<=70;i++){
        dp[i]=dp[i-2]+dp[i-1];
    }
    cin>>n;
    int m;
    while(n--){
        cin>>m;
        cout<<dp[m]<<endl;
    }
    return 0;
}
