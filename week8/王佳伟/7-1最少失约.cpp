#include<bits/stdc++.h>
using namespace std;
#define MOD 1000007

//dp[i][k]前i个活动，j点为止最大的活动参加数 
//dp[i][j] = dp

int main() {
	int T, n;
	cin >> T;
	while(T--){
		cin >> n;
		vector<int> dp(n+1, 0);
		vector<vector<int>> a(n+1, vector<int>(2));
		for(int i = 1; i <= n; i++){
			cin >> a[i][0] >> a[i][1];
		}
		sort(a.begin()+1, a.end());
		
		int now = a[1][1];
		int res = 1;
		for(int i = 1; i <= n; i++){
			if(a[i][1] < now){
				now = a[i][1];
				continue;
			}
			if(a[i][0] >= now){
				now = a[i][1];
				res++;
			}
		} 
		cout << n-res << endl;
//		for(int i = 1; i <= n; i++){
//			if(a[i][1] < a[i][0]){
//				
//			}
//			if(a[i][0] >= dp[i-1]){
//				if(a[i][0] > a[i][1] && a[i][1] > dp[1]){
//					cout << "kkk";
//					continue;
//				}
//				res++;
//				dp[i] = a[i][1];
//			}
//			else{
//				if(dp[i-1] > a[i][1])
//				dp[i-1] = min();
//			}
//		}
//		cout << n-res << endl;
	}
}

/*
3 5 
4 6
7 10
23 4后面的状态与前面的状态有关，3 5，还是4 6. 本来是选3 5更好，因为5更小，但是这道题的特殊性4比3好，不好定义：因此dp为必须选第i个

dp[i][j]定义前i个活动截至时间为j,这个样子也是不行的,当a[i][0],a[i][1]为一个比较小的数，会影响到较大的。可以选择把a[i][0]从小到大排序 

dp[i][j]活动截至为i，在前j个活动中选择。 


*/


/*
2
5
1 4
3 5
3 8
5 9
12 14
5
2 3
3 10
8 9
9 15
4 10
*/
