#include<bits/stdc++.h>
using namespace std;

#define INF 11111

struct Node{
	int v,l;//一条路的尾结点，该路的长度
};

int n,e,start,stop;
vector<Node> v[1001];
//使用二维动态数组
int dist[1001];//存最短路径
int path[1001];//存父节点
int visit[1001];//防止重复

void Dijkstra(int start)
{
	fill(dist,dist + 1001,INF);//全部初值为无穷大
	dist[start] = 0;
	for(int i = 0;i < n;i ++)
    {
		int u = -1,minx = INF;
		for(int j = 0;j < n;j ++)
		{
			if(visit[j] == 0 && dist[j] < minx)//选取可行的较小点，并记录起点
            {
				minx = dist[j];
				u = j;
			}
		}
		if(u == -1) break;
		visit[u] = 1;
		//我们需要看看新加入的顶点是否可以到达其他顶点并且看看通过该顶点到达其他点的路径长度是否比源点直接到达短，如果是，那么就替换这些顶点在dis中的值
		for (int j = 0; j < v[u].size(); j++)
		{
            int x = v[u][j].v;
            if (visit[x] == 0 && dist[u] + v[u][j].l < dist[x])
            {
                dist[x] = dist[u] + v[u][j].l;
                path[x] = u;
            }
        }
	}
}

int main(){
	cin >> n >> e;
    for (int i = 0; i < e / 2; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        //这两行就相当于用二维数组的edge[a][b] = edge[b][a] = c;
        //但是很多情况下用二维数组都会运行超时，要不然就内存超限
        v[a].push_back(Node{b, c});
        v[b].push_back(Node{a, c});
    }
    cin >> start >> stop;
    if (start == stop)
    {//如果起点和终点是同一个结点
        printf("%d-->%d:0",start,start);
        return 0;
    }
    Dijkstra(start);
    vector<int> ve;
    int x = stop;
    while (x != start)
    {
        ve.push_back(x);
        x = path[x];
    }
    cout << start;
    for (int i = ve.size() - 1; i >= 0; i--)
        cout << "-->" << ve[i];//动态数组的输出也不一定需要迭代器
    cout << ":" << dist[stop];
}


