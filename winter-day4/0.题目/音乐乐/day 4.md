# day 3

---

## 7-1 双十一

```
#include<bits/stdc++.h> 
#define Inf 0x3f3f3f3f
using namespace std;
int m[105][105];
int vis[105],dis[105],total[105];
int n,e,i;
void Dijkstra(int u)
{
	memset(vis,0,sizeof(vis));
	for(int t=0;t<n;t++)
		dis[t]=m[u][t];//先将出发点到其他点各点的直接距离存储，方便与后面的间接距离相比较
	vis[u]=1;//出发点不可访问
	for(int t=0;t<n;t++)//遍历找到出发点到其他点之间的最短距离
	{
		int minn=Inf,temp;
		for(int i=0;i<n;i++)
		{
			if(!vis[i]&&dis[i]<minn&&t!=i)//该点是目前检索到的距离最短的，且未被访问过，且不是自身
			{
				minn=dis[i];
				temp=i;
			}
		}
		vis[temp]=1;//temp为找到的距离目前所在位置最短的点，标记已经被访问过
		for(int i=0;i<n;i++)
		{
			if(m[temp][i]+dis[temp]<dis[i])//如果从出发点到temp所在位置加上temp到遍历的i点所在位置比出发点到i的距离短，就更新出发点到i点的最短距离
			{
				dis[i]=m[temp][i]+dis[temp];
			}
		}
	}
	
}
int main()
{
	while(~scanf("%d%d",&n,&e))
	{
        memset(total,0,sizeof(total));
		for(i=0;i<105;i++) 
			for(int j=0;j<105;j++)
		m[i][j]=Inf;//初始化，将整个图上的点之间的距离先标记为无穷大
		for(i=0;i<n;i++)
			m[i][i]=0;//一个点到自身的距离为0
		for(i=0;i<e;i++)
		{
			int city1,city2;
			cin>>city1>>city2>>m[city1][city2];
            m[city2][city1]=m[city1][city2];//无向图，在邻接矩阵上需要标记两次
		}
		for(i=0;i<n;i++)
		{
			Dijkstra(i);
            for(int j=0;j<n;j++)
                total[i]+=dis[j];//total求出发点到其他各点的距离之和
		}
		int minn=total[0],index=0;
		for(i=1;i<n;i++)
		{
			//cout<<i<<':'<<total[i]<<endl;
			if(total[i]<minn)
            {
                minn=total[i];
			    index=i;
            }
		}//找出到其他点距离之和最短的出发点的下标
		cout<<index<<endl;
	}
	return 0;
}
```



## 7-3 最短路径之Dijkstra

```
#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

struct Node{
	int v,l;
};

int n,e,start,stop;
vector<Node> v[1001];
int dist[1001];
int path[1001];
int visit[1001];

void Dijkstra(int start)
{
	fill(dist,dist + 1001,INF);
	dist[start] = 0;
	for(int i = 0;i < n;i ++)
	{
		int u = -1,minx = INF;
		for(int j = 0;j < n;j ++)
		{
			if(visit[j] == 0 && dist[j] < minx)
			{
				minx = dist[j];
				u = j;
			}
		}
		if(u == -1) break;	
		visit[u] = 1;
		for (int j = 0; j < v[u].size(); j++) {
            int x = v[u][j].v;
            if (visit[x] == 0 && dist[u] + v[u][j].l < dist[x]) {
                dist[x] = dist[u] + v[u][j].l;
                path[x] = u;
            }
        }
	}
}

int main(){
	cin >> n >> e;
    for (int i = 0; i < e / 2; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        //这两行就相当于用二维数组的edge[a][b] = edge[b][a] = c;但是很多情况下用二维数组都会运行超时，要不然就内存超限 
        v[a].push_back(Node{b, c});
        v[b].push_back(Node{a, c});
    }
    cin >> start >> stop;
    if (start == stop) {//如果起点和终点是同一个结点 
        printf("%d-->%d:0",start,start);
        return 0;
    }
    Dijkstra(start);
    vector<int> ve;
    int x = stop;
    while (x != start) {
        ve.push_back(x);
        x = path[x];
    }
    cout << start;
    for (int i = ve.size() - 1; i >= 0; i--)
        cout << "-->" << ve[i];//动态数组的输出也不一定需要迭代器 
    cout << ":" << dist[stop];
}
```

