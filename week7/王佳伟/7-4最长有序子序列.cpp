#include<bits/stdc++.h>
using namespace std;

int a[1005];
int dp[1005];//dp[i][0/1]前i个数字中选i和前面某个j合并
int main() {
	int res = 0;
	int T, n;
	cin >> T; 
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for(int i = 1; i <= n; i++){
			dp[i] = 1;
			for(int j = 1; j < i; j++){
				if(a[i] > a[j]) {
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
			res = max(res, dp[i]);
		} 
		cout << res << endl;
		res = 0;
		if(T >= 1) cout << endl;
	}
//	for(int i = 1; i <= n; i++)cout << dp[i] << " ";
	
}


