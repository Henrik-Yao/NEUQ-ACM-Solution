#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
bool vis[100001];
vector<int> mapp[100001];
char xb[100001];//性别
int pd;//默认可以
void dfs1(int q1, int ds)//如何判断代数？？？？
{
	if (ds > 4) return;
	if (q1 == -1) { return; }
	vis[q1] = 1;
	for (auto lsz : mapp[q1])
	{
		dfs1(lsz, ds + 1);
	}
}
void dfs2(int q2, int ds)
{
	if (ds > 4) return;
	if (q2 == -1) { return; }
	if (pd)return;
	if (vis[q2]) { pd = 1; return; }
	for (auto lsz : mapp[q2])
	{
		dfs2(lsz, ds + 1);
	}
}
int main()
{
	int n;
	cin >> n;
	int zj, fq, mq;
	for (int i = 0; i < n; i++)
	{
		cin >> zj; cin >> xb[zj] >> fq >> mq;
		mapp[zj].push_back(fq);
		mapp[zj].push_back(mq);
		xb[fq] = 'M';
		xb[mq] = 'F';
	}
	int k;
	cin >> k;
	int q1, q2;
	for (int i = 0; i < k; i++)
	{
		cin >> q1 >> q2;
		if (xb[q1] == xb[q2])cout << "Never Mind" << endl;
		else
		{
			pd = 0;
			memset(vis, 0, 100001);
			dfs1(q1, 0);
			dfs2(q2, 0);
			if (!pd)cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}