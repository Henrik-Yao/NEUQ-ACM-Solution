#include<iostream>
#include<cstring>

int map[21][21];
int n, m, k, l;
using namespace std;

void open(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)return;
	map[x][y] = 0;
	for (int dr = -1; dr <= 1; dr++)
	{
		for (int dc = -1; dc <= 1; dc++)
		{
			if (map[x + dr][y + dc] == -2) {
				++map[x][y];
			}
		}
	}
	if (map[x][y] > 0)return;
	for (int dr = -1; dr <= 1; dr++)
	{
		for (int dc = -1; dc <= 1; dc++)
		{
			if (map[x + dr][y + dc] == -1)open(x + dr, y + dc);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> m >> k >> l;//k=mine l=click
	int x, y;
	memset(map, -1, sizeof(map));
	//input mine data
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		map[x][y] = -2;
	}
	//input mouse action
	for (int i = 0; i < l; i++)
	{
		cin >> x >> y;
		int count = 0;
		if (map[x][y] >= 0)continue;
		else if (map[x][y] == -2) {
			cout << "You lose" << endl;
			break;
		}
		else {
			open(x, y);
			for (int ii = 0; ii < n; ii++)
			{
				for (int jj = 0; jj < m; jj++)
				{
					if (map[ii][jj] >= 0)cout << map[ii][jj] << " ";//blocks already opened
					else {
						cout << -1 << " ";
						++count;
						//unopened block&mine block->pretend to be unopened
					}
				}
				cout << '\n';
			}
			if (count == k) {
				cout << "You win" << endl; break;
			}
		}
		cout << '\n';
	}
}