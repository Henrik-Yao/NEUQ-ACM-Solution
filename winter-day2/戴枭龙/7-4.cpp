#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int f[1000], n, m, q, cnt;

void Init() {//f数组存储的是每个罪犯的父亲即老大、cnt用来记录犯罪团伙的数量
	for (int i = 1; i <= n; i++)
		f[i] = i;
	return;
}

int findf(int v) {
	if (f[v] == v)
		return v;
	else {//路径压缩使搜索祖宗的过程中，路径中搜索的结点的父亲的变为祖宗)
		f[v] = findf(f[v]);
		return f[v];
	}
}

void Merge(int v, int u) {
	int t1 = findf(v);
	int t2 = findf(u);
	f[t2] = t1;
	return;
}

int main() {
	int i, a, b;
	cin >> n >> m >> q;
	Init();//初始化，让每个罪犯的父亲都是自己
	for (i = 0; i < m; i++) {
		cin >> a >> b;
		Merge(a, b);
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		if (f[a] == f[b])
			cout << "In the same gang." << endl;
		else
			cout << "In different gangs." << endl;
	}
	for (i = 1; i <= n; i++) {	//遍历f数组，如果罪犯的父亲还是自己，那么就是一个犯罪团伙
		if (f[i] == i)
			cnt++;
	}
	cout << cnt;
	return 0;
}
