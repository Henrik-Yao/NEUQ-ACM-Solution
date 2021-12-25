## week8 题解

#### 7-1最少失约

分析：想着想着动规，发现贪心更香。 如果把数组按照i排序，即后面的活动一定更晚发生（或同时），但结束时间不一定。

所以分两种情况

- 第i个活动在第i-1个活动结束后发生：res++
- 第i个活动在第i-1个活动结束前发生：若第i个活动结束的比第i-1个活动早，那就不选第i-1个活动了

```C++
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000007

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
	}
}
```



#### 7-2跳一跳

分析：如果定义dp[i]为跳到i最少的跳跃次数，会超时（注释代码中）

所以贪心，now为当前能跳到的最远距离，比如按照例子，maxindex = 2，遍历到1，记录now = 1+3=4，遍历到2，2+1<4, 然后res++，maxindex=now，继续遍历

```C++
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

```

