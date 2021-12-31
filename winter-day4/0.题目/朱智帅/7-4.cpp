#include<iostream>
#include<stack>
using namespace std;
double Dis[10001][10001] = { 0 };
int P[10001][10001];
stack<int>S;
int main()
{
	int n, e, i, j, k, a, b, w;
	cin >> n >> e;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			Dis[i][j] = INT16_MAX;
			P[i][j] = j;
		}
		Dis[i][i] = 0;
	}
	for (i = 0; i < e; i++)
	{
		cin >> a >> b >> w;
		Dis[a][b] = w;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (Dis[j][k] > Dis[j][i] + Dis[i][k])
				{
					Dis[j][k] = Dis[j][i] + Dis[i][k];
					P[j][k] = P[j][i];
				}
			}
		}
	}
	int u = 2;
	while (u--) {
		cin >> a >> b;
		int temp = P[a][b];
		cout << a << "->";
		while (P[temp][b] != temp) {
			cout << temp << "->";
			temp = P[temp][b];
		}
		if (Dis[a][b] < INT16_MAX) cout << b << ":" << Dis[a][b] << endl;
		else cout << b << ":" << -1 << endl;
	}
	int max = 0;
	for (i = 0; i < n; i++)
	{
		for(j=0;j<n;j++)
		{
			if (max < Dis[i][j] && Dis[i][j] < INT16_MAX) max = Dis[i][j], a = i, b = j;
		}
	}
	int temp = P[a][b];
	cout << a << "->";
	while (P[temp][b] != temp) {
		cout << temp << "->";
		temp = P[temp][b];
	}
	if (Dis[a][b] < INT16_MAX) cout << b << ":" << Dis[a][b] << endl;
	else cout << b << ":" << -1 << endl;
	return 0;
}