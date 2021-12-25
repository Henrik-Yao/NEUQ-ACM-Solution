#include<bits/stdc++.h>
using namespace std;
#define MOD 1000007

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	if(n <= 1){
		cout << 0;
		return 0;
	}
	int res = 0;
	int maxindex = a[0];
	int r = 1;
	while(r < n){
		int now = maxindex;
		while(r <= maxindex && r < n){
			now = max(now, r+a[r]);
			r++;
		}
		maxindex = now;
		res++;
	}
	cout << res;
	
//	for(int i = 1; i < n; i++){
//		for(int j = 0; j < i; j++){
//			if(dp[j] >= dp[i]-1) continue;
//			if(j+a[j] >= i) dp[i] = dp[j]+1;
//		}
//	}
//	cout << dp[n-1];
//	for(int i = 0; i < n; i++) cout << dp[i] << " ";
}

