#include <bits/stdc++.h>
using namespace std;
int p[1009];
struct Edge{
	int u, v, val;
};
int find(int x)
{
	return x == p[x] ? x : p[x] = find(p[x]);
}
bool cmp(Edge e1, Edge e2)
{
	return e1.val < e2.val;
}
	int n, v, m; Edge edge[1009];
	int fans = -1;
void kr(Edge e1,Edge e2){
	
		for (int i = 0; i < 60; i++) p[i] = i;
//		printf("强制选择\n");
		int sum = 0, cnt = 0, num = 0;	
		int x = find(e1.u), y = find(e1.v);
		if(x != y)
			{
//				printf("x = %d, y = %d\n", x, y);
				if((e1.u == v || e1.v == v) && cnt < 2)
				{
//					printf("优先：有节点1,u = %d, v = %d\n", e1.u, e1.v);
					sum += e1.val;
					p[x] = y;
					cnt++;num++;
//					printf("num = %d\n", num);
				}
				else if(e1.u != v && e1.v != v)
				{
//					printf("优先：无节点1,u = %d, v = %d\n", e1.u, e1.v);
					sum += e1.val;
					p[x] = y;
					num++;
//					printf("num = %d\n", num);
				}
			}
			x = find(e2.u), y = find(e2.v);
		if(x != y)
			{
//				printf("x = %d, y = %d\n", x, y);
				if((e2.u == v || e2.v == v) && cnt < 2)
				{
//					printf("优先：有节点2,u = %d, v = %d\n", e2.u, e2.v);
					sum += e2.val;
					p[x] = y;
					cnt++;num++;
//					printf("num = %d\n", num);
				}
				else if(e2.u != v && e2.v != v)
				{
//					printf("优先：无节点2,u = %d, v = %d\n", e2.u, e2.v);
					sum += e2.val;
					p[x] = y;
					num++;
//					printf("num = %d\n", num);
				}
			}
		
		
		for (int i = 1; i <= m; i++)
		{
			x = find(edge[i].u), y = find(edge[i].v);
			if(x != y)
			{
//				printf("x = %d, y = %d\n", x, y);
				if((edge[i].u == v || edge[i].v) && cnt < 2)
				{
//					printf("有节点,u = %d, v = %d\n", edge[i].u, edge[i].v);
					sum += edge[i].val;
					p[x] = y;
					cnt++;num++;
//					printf("num = %d\n", num);
				}
				else if(edge[i].u != v && edge[i].v != v)
				{
//					printf("无节点,u = %d, v = %d\n", edge[i].u, edge[i].v);
					sum += edge[i].val;
					p[x] = y;
					num++;
//					printf("num = %d\n", num);
				}
			}
		}
		if(num == n-1 && cnt <= 2)
			if(fans == -1) fans = sum;
				else fans = min(sum, fans);
		
	}
int main(){

	while(cin >> n >> v >> m)
	{
		fans = -1;
		for (int i = 1; i <= m; i++)
		{
			cin >> edge[i].u >> edge[i].v >> edge[i].val;
//			fans += edge[i].val;
		}
		
		sort(edge+1,edge+m+1,cmp);
		for (int i = 1; i <= m; i++)
		{
			for (int j = i+1; j <= m; j++)
			{
				if(i != j)
				{
//						printf("优先选择 %d,%d\n", i, j);
						kr(edge[i],edge[j]);
				 } 
			}
		}
		cout << fans << endl;
	}
	
	
	return 0;
}
