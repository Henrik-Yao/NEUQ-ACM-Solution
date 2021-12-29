#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
#include<map>
#include<string.h>
using namespace std;

bool vis[10001];
vector<int> nev[10001];
map<string, int>ma;
int dj[10001];//初始地去往某地的代价
int cs, en;
string path="";


string str(int n)
{
	return to_string(n);
}

void dfs(int now,string o,int xh)
{
	if (vis[now])return;
	if (dj[now] < xh)return;
	dj[now] = xh;
	if (now == en) { path = o; return; }
	vis[now] = 1;
	for (auto lsz : nev[now])
		dfs(lsz, o + "-->" + str(lsz), xh + ma[str(now) + "-" + str(lsz)]);
	vis[now] = 0;
}

int main()
{
	memset(dj, 999999, 10001);
	int v, e;//顶点数vN和边数eN
	cin >> v >> e;
	for (int i = 0; i < e / 2; i++)
	{
		int q, p, v;
		cin >> q >> p >> v;
		nev[q].push_back(p);
		nev[p].push_back(q);
		ma[str(q) + "-" + str(p)] = v;
		ma[str(p) + "-" + str(q)] = v;
	}
	
	cin >> cs >> en;
	if (cs == en) { cout << cs << "-->" << en << ":" << "0"; return 0; }
	dfs(cs,str(cs),0);
	cout << path;
	cout << ":" << dj[en];
	return 0;
}
