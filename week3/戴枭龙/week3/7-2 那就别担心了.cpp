#include <bits/stdc++.h>
using namespace std;
#define N 1000
int head[N], sj[N * N], zz[N * N], idx;
int num[N];
int n, m, s1, s2, flag;

void add(int a, int b) {
	sj[idx] = b, zz[idx] = head[a], head[a] = idx++;
}

int dfs(int t) {
	int sum = 0;
	if (num[t] != -1)
		return num[t];
	if (t == s2)
		return num[t] = 1;
	if (head[t] == -1) {
		flag = 1;
		return num[t] = 0;
	}
	for (int i = head[t]; i != -1; i = zz[i]) {
		int j = sj[i];
		sum += dfs(j);
	}
	return num[t] = sum;
}

int main() {
	memset(head, -1, sizeof head);
	memset(num, -1, sizeof num);
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		int p, q;
		cin >> p >> q;
		add(p, q);
	}
	cin >> s1 >> s2;
	int sum = dfs(s1);
	cout << sum << " ";
	if (flag || !sum)
		cout << "No";
	else
		cout << "Yes";
	return 0;
}
