#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int f[1000], n, m, q, cnt;

void Init() {//f����洢����ÿ���ﷸ�ĸ��׼��ϴ�cnt������¼�����Ż������
	for (int i = 1; i <= n; i++)
		f[i] = i;
	return;
}

int findf(int v) {
	if (f[v] == v)
		return v;
	else {//·��ѹ��ʹ�������ڵĹ����У�·���������Ľ��ĸ��׵ı�Ϊ����)
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
	Init();//��ʼ������ÿ���ﷸ�ĸ��׶����Լ�
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
	for (i = 1; i <= n; i++) {	//����f���飬����ﷸ�ĸ��׻����Լ�����ô����һ�������Ż�
		if (f[i] == i)
			cnt++;
	}
	cout << cnt;
	return 0;
}
