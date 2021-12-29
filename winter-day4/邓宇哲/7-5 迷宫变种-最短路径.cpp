#include <iostream>
#include <set>
using namespace std;
void dij(int x, int y);
class Node
{
public:
	pair<int, int> front;
	int length = 65535;
	int value;
};
void findpath(int sx, int sy, int ex, int ey);
Node matix[128][128];
bool sign[128][128] = {};
int m, n;
int dis = 0;
main()
{
	cin >> m >> n;
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	sx++;
	sy++;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> matix[i][j].value;
			if (matix[i][j].value == -1)
			{
				dis++;
			}
		}
	}
	set<pair<int, int>> sets; //记录已经被开发的区域
	pair<int, int> minn = {sx, sy};
	int min;
	matix[sx][sy].length = 0;
	sign[sx][sy] = 1;
	pair<int, int> now = {sx, sy}; //当前要进行操作的节点
	sets.insert(now);
	int ctrl[] = {1, 0, -1, 0, 1};
	while (sets.size() < m * n - dis)
	{
		min = 65535;
		for (int i = 0, j = 1; i < 4; j++, i++)
		{
			if (sign[now.first + ctrl[i]][now.second + ctrl[j]] || matix[now.first + ctrl[i]][now.second + ctrl[j]].value == -1)
			{
				continue;
			}
			if (matix[now.first + ctrl[i]][now.second + ctrl[j]].length > matix[now.first][now.second].length + matix[now.first + ctrl[i]][now.second + ctrl[j]].value)
			{
				sets.insert({now.first + ctrl[i], now.second + ctrl[j]});
				matix[now.first + ctrl[i]][now.second + ctrl[j]].front = {now.first, now.second};
				matix[now.first + ctrl[i]][now.second + ctrl[j]].length = matix[now.first][now.second].length + matix[now.first + ctrl[i]][now.second + ctrl[j]].value;
			}
		}
		for (auto i = sets.begin(); i != sets.end(); i++)
		{
			if (sign[i->first][i->second])
			{
				continue;
			}
			if (matix[i->first][i->second].length < min && sign[i->first][i->second] != 1)
			{
				min = matix[i->first][i->second].length;
				minn = {i->first, i->second};
			}
		}
		sign[minn.first][minn.second] = 1;
		now = minn;
	}
	cout << '(' << ex << ' ' << ey << ')';
	findpath(sx, sy, ex + 1, ey + 1);
}
void findpath(int sx, int sy, int ex, int ey)
{
	if (sx == ex && sy == ey)
	{
		return;
	}
	cout << '(' << matix[ex][ey].front.first - 1 << ' ' << matix[ex][ey].front.second - 1 << ')';
	findpath(sx, sy, matix[ex][ey].front.first, matix[ex][ey].front.second);
}