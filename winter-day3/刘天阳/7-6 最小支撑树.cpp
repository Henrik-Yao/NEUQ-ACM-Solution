#include <bits/stdc++.h>
using namespace std;
struct Edge{
	int u, v, val;
};
int p[20009];
int find(int x){
	return p[x] == x ? x : p[x] = find(p[x]);
}
bool cmp(Edge e1, Edge e2)
{
	return e1.val < e2.val;
}
Edge edge[20009];
int main(){
	int n, m;
	while(cin >> n >> m)
	{
		
		for (int i = 1; i <= m; i++)
		{
			cin >> edge[i].u >> edge[i].v >> edge[i].val;
			edge[i*2].u = edge[i].v; 
			edge[i*2].v = edge[i].u;
			edge[i*2].val = edge[i].val; 
		}
		for (int i = 1; i <= n; i++) p[i] = i;
		sort(edge+1, edge+m*2+1, cmp);
		int ans = 0;
		for (int i = 1; i <= m*2; i++)
		{
			int x = find(edge[i].u), y = find(edge[i].v);
			if(x != y)
			{
//				printf("u = %d,v = %d\n",edge[i].u,edge[i].v);
				ans += edge[i].val;
				p[x] = y;
			}
		}
		int ju = 1;
//		printf("find(2) = %d, find(3) = %d\n",find(2), find(3));
		for (int i = 1; i < n; i++)
		{
			int x = find(i), y = find(i+1);
			if(x != y) {
				ju = 0;
				break;
			}
		}
		if(ju) 	cout << ans << endl;
		else cout << "There is no minimum spanning tree." << endl;
	}
	
	return 0;
}
