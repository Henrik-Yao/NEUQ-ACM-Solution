#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int INF = 1e6;
int n,m;
struct edge
{
	int from,to,w;
	edge(int a,int b,int c)
	{
		from=a;to=b;w=c;		
	}
};
vector<edge>e[maxn];
struct node
{
	int id,n_dis;//id为结点 dis为到起点的距离
	node(int b,int c)
	{
		id=b;n_dis=c;
	}
	bool operator < (const node&a) const//?
	{
		return n_dis>a.n_dis;
	}
};
int pre[maxn];//记录前驱结点
void putpath(int s,int t)//打印s到t的最短路径
{
	if(s==t)
	{
		printf("%d",s);return;//打印起点
	}
	putpath(s,pre[t]);//先打印前一个点
	printf("-->%d",t);//后打印当前点
}
void dij()//dijkstra
{
	int s,t;//起点 终点
	cin>>s>>t;
	int dis[maxn];//记录所有结点到起点的距离
	bool done[maxn];
	for(int i=0;i<n;i++)
	{
		dis[i]=INF;done[i]=false;//初始化
	}
	dis[s]=0;//起点到本身的距离为0
	priority_queue<node>Q;//优先序列
	Q.push(node(s,dis[s]));//起点进序列
	while(!Q.empty())
	{
		node u=Q.top();//pop出距离最小的结点u
		Q.pop();
		if(done[u.id]) continue;//丢弃已经找到的结点
		done[u.id]=true;
		for(int i=0;i<e[u.id].size();i++)//访问u的所有邻居
		{
			edge y=e[u.id][i];//u.id的第i个邻居为y.to
			if(done[y.to]) continue;//丢弃已经找到最短路径的邻居结点
			if(dis[y.to]>y.w+u.n_dis)
			{
				dis[y.to]=y.w+u.n_dis;
				Q.push(node(y.to,dis[y.to]));
				
				pre[y.to]=u.id;//记录路径
			}
		}
	}
	putpath(s,t);
	if(s==t)cout<<"-->"<<t;
	cout<<":"<<dis[t];
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) e[i].clear();
	int a,b,c;
	for(int i=0;i<m/2;i++)//输入
	{
		scanf("%d%d%d",&a,&b,&c);
		e[a].push_back(edge(a,b,c));//结点a的邻居
		e[b].push_back(edge(b,a,c));
	}
	dij();//dijkstra
	return 0;
}