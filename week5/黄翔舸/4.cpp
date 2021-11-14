#include<iostream>

using namespace std;
int sum = 0;
int m, n;
bool shan[2001][2001];
void lian(int i, int j)
{
	int row[4] = { 0,1,0,-1 };
	int col[4] = { 1,0,-1,0 };
	for (int k = 0; k <= 3; k++)
	{
		if (row[k] + i >= 0 && col[k] + j >= 0 && row[k] + i < m && col[k] + j < n && shan[row[k] + i][col[k] + j])
		{
			shan[row[k] + i][col[k] + j] = 0;
			lian(row[k] + i, col[k] + j);
		}
	}
}
void xz(int i, int j)
{
	if (shan[i][j])
	{
		sum++;
		lian(i, j);
	}
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{


		for (int j = 0; j < n; j++)
		{
			cin >> shan[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			xz(i, j);



		}
	}
	cout << sum;

	return 0;
}