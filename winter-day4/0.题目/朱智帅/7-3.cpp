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
	e = e / 2;
	for (i = 0; i < e; i++)
	{
		cin >> a >> b >> w;
		Dis[a][b] = w;
		Dis[b][a] = w;
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
	cin >> a >> b;
	int temp = P[a][b];
	cout << a << "-->";
	while (P[temp][b]!=temp) {
		cout << temp << "-->";
		temp = P[temp][b];
	}
	cout << b << ":";
	printf("%.0f", Dis[a][b]);
	return 0;
}