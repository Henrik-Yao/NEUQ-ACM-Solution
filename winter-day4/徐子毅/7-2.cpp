#include <iostream>
#include <cstring>
using namespace std;
#define inf 999999
int main(){
	int n,m;
	while(cin>>n>>m){
		int dp[n][n];
		memset(dp,inf,sizeof dp);
		for(int T=0;T<n;T++){
			int i,cn;
			cin >> i >> cn;
			for(int TT=0;TT<cn;TT++){
				int num;
				cin >> num;
				dp[i][num]=1;
			}
		}
		int inter,router1,router2;
		for(inter=0;inter<n;inter++){
			for(router1=0;router1<n;router1++){
				for(router2=0;router2<n;router2++){
					if(dp[router1][router2]>dp[router1][inter]+dp[inter][router2])  dp[router1][router2]=dp[router1][inter]+dp[inter][router2];
				}
			}
		}
		for(int TTT=0;TTT<m;TTT++){
			int r1,r2;
			cin >> r1 >> r2;
			if(dp[r1][r2] >=inf/2) cout << "connection impossible" << endl;
			else cout << dp[r1][r2] << endl;
		}
	}
	return 0;
}