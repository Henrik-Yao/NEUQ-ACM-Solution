#include <bits/stdc++.h>
using namespace std;
struct Node{
	int f,t,q;
};
Node node[20009];
int vis[20009];
bool cmp(Node node1,Node node2)
{
	if(node1.f != node2.f) return node1.f < node2.f;
	return node1.t < node2.t;
}
int main()
{
	int n, e; cin >> n >> e;
	for (int i = 1;  i <= e; i++)
	{
		cin >> node[i].f >> node[i].t >> node[i].q;
		vis[node[i].f]++;
	}
//	for (int i = 0; i < n; i ++) cout << vis[i] << " ";
//	cout << endl;
	sort(node+1,node+e+1,cmp);
	int t = 1;
	for (int i = 0; i < n; i++)
	{
		int k = t;
		if(!vis[i]) continue;
		cout << node[t].f << ":";
		for (;t < k+vis[i]; t++)
		{
			printf("(%d,%d,%d)",node[t].f,node[t].t,node[t].q);
		}
		cout << endl;
	}
	return 0;
}
