# **寒假集训—day4（图）**

## **7-1**

用dijkstra求一下每个点的单源最短路

或者用floyd直接全部求出来

然后再比较即可

**AC代码**

~~~cpp
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int n,m;
struct node
{
	int pre,to,nex;
	int val;
}e[205];
int head[205];
int cnt;
void add(int a,int b,int c)
{
	e[++cnt].to=b;
	e[cnt].pre=a;
	e[cnt].val=c;
	e[cnt].nex=head[a];
	head[a]=cnt;
}
int dis[105];
int v[105];
int ans=inf;
int anss;
void dijkstra(int x)
{
	priority_queue<pair<int,int> >q;
	dis[x]=0;
	q.push({0,x});
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=e[i].nex)
		{
			int y=e[i].to;
			int val=e[i].val;
			if(dis[y]>dis[x]+val)
			{
				dis[y]=dis[x]+val;
				q.push({-dis[y],y});
			}
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		cnt=0;
		ans=inf;
		anss=0;
		memset(head,0,sizeof(head));
		for(int i=1;i<=m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			add(a,b,c);
			add(b,a,c);
		}
		for(int i=0;i<n;i++)
		{
			int sum=0;
			memset(dis,0x3f,sizeof(dis));
			memset(v,0,sizeof(v));
			dijkstra(i);
			for(int j=0;j<n;j++)
			{
				sum+=dis[j];
			}
			if(sum<ans)
			{
				ans=sum;
				anss=i;
			}
		}
		cout<<anss<<endl;
	}
	return 0;
}

~~~



## **7-2**

多次用dijkstra求单源最短路，或者用floyd

边的长度设为1即可

**AC代码**

~~~cpp
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;

int n,m;
struct node
{
	int pre,to,nex;
	int val;
}e[205];
int head[205];
int cnt;
void add(int a,int b)
{
	e[++cnt].to=b;
	e[cnt].pre=a;
	e[cnt].val=1;
	e[cnt].nex=head[a];
	head[a]=cnt;
}
int dis[205][205];//i到j
int v[205];
int opera[205];
void dijkstra(int a)
{
	priority_queue<pair<int,int> >q;
	memset(v,0,sizeof(v));
	memset(dis[a],0x3f,sizeof(dis[a]));
	dis[a][a]=0;
	q.push({0,a});
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=e[i].nex)
		{
			int y=e[i].to;
			int val=e[i].val;
			if(dis[a][y]>dis[a][x]+val)
			{
				dis[a][y]=dis[a][x]+val;
				q.push({-dis[a][y],y});
			}
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		memset(opera,0,sizeof(opera));
		memset(head,0,sizeof(head));
		for(int i=1;i<=n;i++)
		{
			int a,k;
			cin>>a>>k;
			for(int j=1;j<=k;j++)
			{
				int b;
				cin>>b;
				add(a,b);
			}
		}
		
		for(int i=1;i<=m;i++)
		{
			int a,b;
			cin>>a>>b;
			if(opera[a])
			{
				if(dis[a][b]!=inf)
				{
					cout<<dis[a][b]<<endl;
				}
				else cout<<"connection impossible"<<endl;
			}
			else
			{
				dijkstra(a);
				opera[a]=1;
				if(dis[a][b]!=inf)
				{
					cout<<dis[a][b]<<endl;
				}
				else cout<<"connection impossible"<<endl;
			}
		}
	}
	return 0;
}

~~~



## **7-3**

利用pre[i]数组记录最短路中i的前驱节点，然后dfs遍历输出即可

注意数据中含有起点和终点一样的数据，需要特判一下

**AC代码**

~~~cpp
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int n,m;
struct node
{
	int pre,to,nex;
	ll val;
}e[20005];
int head[20005];
int cnt;
void add(int a,int b,int c)
{
	e[++cnt].to=b;
	e[cnt].pre=a;
	e[cnt].val=c;
	e[cnt].nex=head[a];
	head[a]=cnt;
}
ll dis[20005];
int v[20005];
int be,en;
int pre[20005];
void dijkstra(int a)
{
	priority_queue<pair<ll,int> >q;
	memset(v,0,sizeof(v));
	memset(dis,0x3f,sizeof(dis));
	dis[a]=0;
	pre[a]=a;
	q.push({0,a});
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=e[i].nex)
		{
			int y=e[i].to;
			int val=e[i].val;
			if(dis[y]>dis[x]+val)
			{
				dis[y]=dis[x]+val;
				pre[y]=x;//记录前驱节点 
				q.push({-dis[y],y});
			}
		}
	}
}
void dfs(int x)
{
	if(x==be)
	{
		cout<<x<<"-->";
	}
	else
	{
		dfs(pre[x]);
		if(x!=en)cout<<x<<"-->";
		else cout<<x<<":";
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m/2;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	cin>>be>>en;
	dijkstra(be);
	if(be!=en)dfs(en);
	else cout<<be<<"-->"<<be<<":";
	cout<<dis[en];
	return 0;
}
~~~



## **7-4**

**整个可达距离中最大距离**的意思是**含节点数最多的最短路**(任意一条最短路，不限起点和终点)

注意是最短路，也就是说对于从0到5

​		0-->5和0-->2-->3-->5和0-->4-->3-->5都可以到达，但是只有0-->4-->3-->5算是最短路

![QQ图片20201121203429.png](https://images.ptausercontent.com/526008a3-d09c-4a2c-a1cc-08adc4e50165.png)

在样例中，最长的最短路长度为4，其中1-->2-->3-->5是最长的



同时，本题也含有起点和终点一样的数据，需要特判一下

**AC代码**

~~~cpp
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;

int n,m;
int be,en;
int d[105][105];
int path[105][105];//记录i到j的最短路径中j的前驱顶点。
int ans;
int anss;
void dfs(int b)
{
	if(be==b)
	{
		cout<<b<<"->";
		return;
	}
	else
	{
		dfs(path[be][b]);
		if(b!=en)cout<<b<<"->";
		else cout<<b<<":";
	}
}
int len(int a,int b,int step)
{
	if(b==a)
	{
		return step;
	}
	else
	{
		return len(a,path[a][b],step+1);
	}
}
int main()
{
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<n;i++)d[i][i]=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		d[a][b]=min(d[a][b],c);
		path[a][b]=a;
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(d[i][j]>=d[i][k]+d[k][j])
				{
					d[i][j]=d[i][k]+d[k][j];
					path[i][j]=path[k][j];
				}
			}
		}
	}
	
	cin>>be>>en;
	if(be==en)
	{
		cout<<be<<"->"<<en<<":0"<<endl;
	}
	else
	{
		if(d[be][en]!=inf)dfs(en);
		else cout<<be<<"->"<<en<<":";
		cout<<(d[be][en]==inf?-1:d[be][en])<<endl;
	}
	
	cin>>be>>en;
	if(be==en)
	{
		cout<<be<<"->"<<en<<":0"<<endl;
	}
	else
	{
		if(d[be][en]!=inf)dfs(en);
		else cout<<be<<"->"<<en<<":";
		cout<<(d[be][en]==inf?-1:d[be][en])<<endl;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d[i][j]!=inf)
			{
				int le=len(i,j,1);
				if(le>ans)ans=le;
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(d[i][j]!=inf)
			{
				if(len(i,j,1)==ans)
				{
					if(d[i][j]>anss)
					{
						anss=d[i][j];
						be=i;
						en=j;
					}
				}
			}
		}
	}
	if(d[be][en]!=inf)dfs(en);
	else cout<<be<<"->"<<en<<":";
	cout<<(d[be][en]==inf?-1:d[be][en])<<endl;
	return 0;
}
~~~



## **7-5**

dfs吧，累了，懒得用图了

**迷宫问题dfs记录最短路径的模板**

~~~cpp
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int n,m;
int ans=inf;
int ma[2005][2005];
int v[2005][2005];
int dx[5]={0,1,0,0,-1};
int dy[5]={0,0,1,-1,0};
int prex[2005],prey[2005];
int ansx[2005],ansy[2005];
int len;
int anslen;
void minn()
{
	anslen=len;
	for(int i=1;i<=len;i++)
	{
		ansx[i]=prex[i];
		ansy[i]=prey[i];
	}
}
void dfs(int a,int b,int c,int d,int step)
{
	if(step>ans)return;
	if(a==c&&b==d)
	{
		if(step<ans)
		{
			ans=step;
			minn();
		}
		return;
	}
	for(int i=1;i<=4;i++)
	{
		int x=a+dx[i];
		int y=b+dy[i];
		if(x>=0&&x<n&&y>=0&&y<n)
		{
			if(ma[x][y]!=-1&&!v[x][y])
			{
				prex[++len]=y;
				prey[len]=x;
				v[x][y]=1;
				dfs(x,y,c,d,step+ma[x][y]);
				v[x][y]=0;
				len--;
			}
		}
	}
}
int main()
{
	int a,b,c,d;
	cin>>m>>n;
	cin>>a>>b>>c>>d;
	prex[b]=b;
	prey[a]=a;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>ma[i][j];
		}
	}
	prex[++len]=b;
	prey[len]=a;
	dfs(a,b,c,d,ma[a][b]);
	for(int i=anslen;i>=1;i--)
	{
		cout<<"("<<ansy[i]<<" "<<ansx[i]<<")";
	}
	return 0;
}
~~~



## **7-6**

**利用两次dijkstra**

第一次用dis1记录从1到各个点的最小现金花费

第二次用dis2记录从n到各个点的最小旅游金花费

注意，第二次的dijkstra要用反向建的图（因为该题是单向图）

这样以后，只用枚举兑换的城市，若在i城市兑换，则需要现金dis1[i]+(dis2[i]+a[i]-1)/a[i]

**对于更换汇率**

tran[i]数组记录在i城市兑换时需要的总现金

只用改变一下在调整汇率后xi号城市兑换时需要的现金即可，其他的都不用变，对此，我们可以用一个set存储每个城市花的钱，需要修改时，删掉该城市之前的tran，再加入新的tran即可，每次询问的答案就是set的第一个元素

~~~cpp
minCost.erase(minCost.find(tran[xi]));//删除之前的tran
~~~

~~~cpp
a[xi]=y;//加入新的tran
minCost.insert(tran[xi]=dis1[xi]+(dis2[xi]+a[xi]-1)/a[xi]);
~~~

**AC代码**

~~~cpp
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
ll n,m,q;
ll a[100005];

struct node
{
	ll pre,to,nex;
	ll c,d;
}e1[200005],e2[200005];
ll head1[200005];
ll head2[200005];
ll cnt1,cnt2;
void add1(ll a,ll b,ll c,ll d)
{
	e1[++cnt1].to=b;
	e1[cnt1].pre=a;
	e1[cnt1].c=c;
	e1[cnt1].d=d;
	e1[cnt1].nex=head1[a];
	head1[a]=cnt1;
}
void add2(ll a,ll b,ll c,ll d)
{
	e2[++cnt2].to=b;
	e2[cnt2].pre=a;
	e2[cnt2].c=c;
	e2[cnt2].d=d;
	e2[cnt2].nex=head2[a];
	head2[a]=cnt2;
}

ll dis1[100005];
ll dis2[100005];
ll v1[100005];
ll v2[100005];
void dijkstra1()
{
	priority_queue<pair<ll,ll> >q;
	memset(v1,0,sizeof(v1));
	memset(dis1,0x3f,sizeof(dis1));
	dis1[1]=0;
	q.push({0,1});
	while(!q.empty())
	{
		ll x=q.top().second;
		q.pop();
		if(v1[x])continue;
		v1[x]=1;
		for(ll i=head1[x];i;i=e1[i].nex)
		{
			ll y=e1[i].to;
			ll c=e1[i].c;
			if(c+dis1[x]<dis1[y])
			{
				dis1[y]=c+dis1[x];
				q.push({-dis1[y],y});
			}
		}
	}
}
void dijkstra2()
{
	priority_queue<pair<ll,ll> >q;
	memset(v2,0,sizeof(v2));
	memset(dis2,0x3f,sizeof(dis2));
	dis2[n]=0;
	q.push({0,n});
	while(!q.empty())
	{
		ll x=q.top().second;
		q.pop();
		if(v2[x])continue;
		v2[x]=1;
		for(ll i=head2[x];i;i=e2[i].nex)
		{
			ll y=e2[i].to;
			ll d=e2[i].d;
			if(d+dis2[x]<dis2[y])
			{
				dis2[y]=d+dis2[x];
				q.push({-dis2[y],y});
			}
		}
	}
}
multiset<ll>minCost;//set 
ll tran[100005];
int main()
{
	cin>>n>>m>>q;
	for(ll i=1;i<=m;i++)
	{
		ll a,b;
		ll c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a==b)continue;
		add1(a,b,c,d);
		add2(b,a,c,d);//建一个反向的图 
	}
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	dijkstra1();
	dijkstra2();
	for(ll i=1;i<=n;i++)
	{
		if(dis1[i]==inf||dis2[i]==inf)continue;
		minCost.insert(tran[i]=dis1[i]+(dis2[i]+a[i]-1)/a[i]);
	}
	for(ll i=1;i<=q;i++)
	{
		ll x;
		ll y;
		scanf("%lld%lld",&x,&y);
		if(!a[x]||a[x]==y)
		{
			printf("%lld\n",*minCost.begin());
		}
		else
		{
			minCost.erase(minCost.find(tran[x]));
			a[x]=y;
			minCost.insert(tran[x]=dis1[x]+(dis2[x]+a[x]-1)/a[x]);
			printf("%lld\n",*minCost.begin());
		}
	}
	return 0;
}
~~~