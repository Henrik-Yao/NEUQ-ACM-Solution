#include<bits/stdc++.h>
using namespace std;
#define MOD 1000007

int main() {
	long long dp[51] = {0};
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i = 3; i <= 50; i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	int n;
	while(cin >> n) {
		cout << dp[n] << endl;
	}
} 

