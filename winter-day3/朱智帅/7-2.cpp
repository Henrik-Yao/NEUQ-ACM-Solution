#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct G
{
	int E, W;
};
bool cmp(G G1, G G2)
{
	return G1.E < G2.E;
}
queue<G>Q[20000];
int main()
{
	int n, e, i, d;
	cin >> n >> e;
	for(i = 0; i < e; i++)
	{
		int a, b, weight;
		cin >> a >> b >> weight;
		Q[a].push({ b,weight });
	}
	cin >> d;
	for (i = 0; i<d; i++)
	{
		int a, b;
		cin >> a >> b;
		while (!Q[a].empty())
		{
			int e = Q[a].front().E, w = Q[a].front().W;
			Q[a].pop();
			if (e == b) break;
			Q[a].push({ e,w });
		}
	}
	for (i = 0; i < n; i++)
	{
		if (!Q[i].empty())
		{
			int k = 0, j;
			G g[20000];
			cout << i << ":";
			while (!Q[i].empty())
			{
				g[k] = Q[i].front();
				k++;
				Q[i].pop();
			}
			sort(g, g + k, cmp);
			for (j = 0; j < k; j++)
				cout << "(" << i << "," << g[j].E << "," << g[j].W << ")";
			cout << endl;
		}
	}
	return 0;
}