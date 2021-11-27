#include<bits/stdc++.h>
using namespace std;

int weight[405];
int val[405];
int dp[405][1501] = {{0}};//dp[i][j]前i个物品，在j容量中最大价值 
int main() {
	int n, c;
	while(scanf("%d%d", &n,&c) != EOF) {
		for(int i = 1; i <= n; i++){
			cin >> weight[i];
		}
		for(int i = 1; i <= n; i++){
			cin >> val[i];
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= c; j++){
				dp[i][j] = dp[i-1][j];
				if(j >= weight[i])
				dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i]] + val[i]);
			}
		}
//		for(int i = 1; i <= n; i++){
//			for(int j = 1; j <= c; j++){
//				cout << dp[i][j] << " ";
//			}
//			cout << endl;
//		}
		cout << dp[n][c] << endl;
		memset(dp, 0, sizeof(dp));
	}
}
/*
4 9
2 3 4 5
3 4 5 7
//3 8
//2 3 4 
//1 2 3 
//5 10
//5 1 7 2 4
//3 5 7 2 3
*/



