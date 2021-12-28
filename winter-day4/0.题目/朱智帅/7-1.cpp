#include<iostream>
using namespace std;
int main()
{
	int n, e, i, j, k, a, b, w;
	while (cin >> n >> e)
	{
		if (!n || !e) continue;
		int weight[101][101];
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				weight[i][j] = 200;
			}
		}
		for (i = 0; i < n; i++) weight[n][n] = 0;
		for (i = 0; i < e; i++)
		{
			cin >> a >> b >> w;
			weight[a][b] = w;
			weight[b][a] = w;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (k = 0; k < n; k++)
				{
					if (weight[j][k] > weight[j][i] + weight[i][k]) weight[j][k] = weight[j][i] + weight[i][k];
				}
			}
		}
		int sum;
		int min = INT16_MAX, mintag = -1;
		for (i = 0; i < n; i++)
		{
			sum = 0;
			for (j = 0; j < n; j++)
			{
				if (weight[i][j] != INT16_MAX) sum += weight[i][j];
			}
			if (sum < min)
			{
				min = sum;
				mintag = i;
			}
		}
		cout << mintag << endl;
	}
	return 0;
}