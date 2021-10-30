#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n, m, a, b;
int u = 1;
struct ll { int u; char p[101]; }
d[100001];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> d[i].u >> d[i].p;
	}
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (a == d[u].u)
		{
			u = (u - b + n - 1) % n + 1;
			continue;
		}
		else if (a != d[u].u)
		{
			u = (u + b - 1) % n + 1;
			continue;
		}
	}
	cout << d[u].p;
	return 0;
}