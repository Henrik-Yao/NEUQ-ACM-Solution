#include<bits/stdc++.h>
using namespace std;
int w[500],v[500];

int main(){
    int n,m;
    while(cin >> n){
        cin >> m;
        for(int i=1; i<=n; i++){
            cin >> w[i];
        }
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        vector<int> dp(m+1,0);
        for(int i=1; i<=n; i++){
            for(int j=m; j>=w[i]; j--){
                dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
            }
        }
        cout << dp[m] << endl;
    }
}
