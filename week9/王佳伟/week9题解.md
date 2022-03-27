# week9题解



## 7-1铺满方格

分析：定义dp[i]为铺满1*i的方案总数，**可推出动态转移方程：dp[i] = dp[i-1] + dp[i-2] + dp[i-3]**

因为dp[i]状态只可能从从这三种状态**直接**转移而来

```C++
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

```



## 7-2求解区间覆盖问题

自己的思路：先想的二分答案，发现题目条件每条线段可以任意长，无法求解。又想动态规划发现算法复杂度达到了On3，百度了一下发现暴力最好

**具体做法：计算没有覆盖的空隙，从大到小排序，当m=1，整个区间len长度，减去最大的m个空隙即可得到。（每减一个空隙，相当于原来的最长len线段被分成两个，知道被分成m个，每次分割都保证减去的值最大）**

```C++
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000007

//二分答案 想了半天感觉不行
//还是用动态规划 ，复杂度太高了 
// 最后发现暴力复杂度最小，哭笑 
int main() {
	int maxm = INT_MAX;
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> d(n-1);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 1; i < n; i++){
		d[i-1] = a[i]-a[i-1]-1;
	}
	sort(d.begin(), d.end(), greater<int>());
	int len = a[n-1] - a[0] + 1;
	for(int i = 0; i < n-1; i++){
		if(i >= m-1) break;
		len -= d[i];
	}
	cout << len;
//	for(int i = 0; i < n-1; i++) cout << d[i] << " ";
}
/*
5 10
1 3 8 5 11
*/
```



### 