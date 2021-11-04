#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

const int maxn = 10000005;
bool vis[maxn];

void primeget(int n) {
	int m = sqrt(n + 0.5);
	for (int i = 2; i <= m; i++)if (!vis[i])
		for (int j = i * i; j <= n; j += i) vis[j] = 1;
}

int main() {
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	int N;
	cin >> N;
	primeget(N);
	int sum = 0;
	for (int i = 1; i <= N ; i++)
	{
		if (!vis[i])++sum;
	}
	cout << sum;
}