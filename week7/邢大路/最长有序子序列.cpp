#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    int n;
    while(T--){
        cin>>n;
        int a[10005];
        int dp[10005];
        for(int i=1;i<=n;i++){
            cin>>a[i];
            dp[i]=1;
        }
        int ans=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(a[i]>a[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
        if(T)cout<<endl;
    }
    return 0;
}
