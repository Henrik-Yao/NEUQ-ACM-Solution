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
