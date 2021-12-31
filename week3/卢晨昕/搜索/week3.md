# **week3-搜索，回溯 题解**

### **7-1**

数据范围比较小，可用二维数组存图，若两个城市 **i，j** 间有路，则**ma i,j**=**ma j,i**=**1**

若终点感染，直接输出

若终点没有感染，则运用dfs进行图的遍历：

​        1.dfs（now）表示当前走到now城市，枚举所有其他城市i（1<=i<=m&&i!=now）.

​        2.若**now与i之间有路**且**该i没有感染**，则dfs（i），同时记录i走过，guo i=1.

​        3.若当前的dfs的now==en（终点），则结束即可，并且记录可以到达城市en.

​        4.之后dfs时，若已经得到可以到达的记录，则可直接return.

​        5.输出结果时若没有记录到达过终点，则说明无法达到

AC代码：

```cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int m,n,k;
int s[105];//记录未感染城市
int guo[105];//记录城市是否走过
int ma[105][105];//记录道路是否通畅
int be,en;
int ans=0;//记录是否到达过终点
void dfs(int now)
{
	if(ans==1)return;
	if(now==en)//到地方了
	{
		ans=1;
		return;
	}
	for(int i=1;i<=m;i++)
	{
		if(i!=now&&s[i]==1&&ma[now][i]==1&&guo[i]==0)
		{
			guo[i]=1;
			dfs(i);
			guo[i]=0;//回溯
		}
	}
}
int main()
{
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int ss;
		cin>>ss;
		s[ss]=1;
	}
	for(int i=1;i<=k;i++)
	{
		int a,b;
		cin>>a>>b;
		ma[a][b]=1;
		ma[b][a]=1;
	}
	cin>>be>>en;
	if(s[en]==0)
	{
		cout<<"The city "<<en<<" is not safe!";
		return 0;
	}
	guo[be]=1;
	dfs(be);
	if(ans==1)
	{
		cout<<"The city "<<en<<" can arrive safely!";
		return 0;
	}
	else
	{
		cout<<"The city "<<en<<" can not arrive safely!";
		return 0;
	}
	return 0;
}
```



### **7-2**

蒟蒻只会用链式前向星存图了。。。

当我开开心心的打了一个普通dfs并提交后，~~果不其然~~**运行超时**

所以考虑**剪枝**和**记忆化搜索**：

​        剪枝：

​                ~~咋剪，我不会~~

​        记忆化搜索：

​                一个点的路径数=它的每个子节点的路径数之和

​                由于dfs是一直遍历到终点，所以一个节点的子节点的路径数可以优先计算出来，所以我们只用在每个点进行遍历时，直接用它的**所有子节点路径数相加**即可得到它的路径数

​                对于直接可以到终点的节点，路径数为1

AC代码：

```cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int n,m;
int be,en;
int flag;//记录是否有其他的终点
int ma[505];//记录该点是否去过

//链式前向星存图
struct node
{
	int to,nex;
}e[200005];
int head[200005],cnt=0;
void add(int a,int b)
{
	e[++cnt].to=b;
	e[cnt].nex=head[a];
	head[a]=cnt;
}
//链式前向星存图

int num[505];
int dfs(int now)
{
	if(num[now]!=0)//之前算过now了
	{
		return num[now];
	}
	for(int i=head[now];i;i=e[i].nex)
	{
		int y=e[i].to;
		if(ma[y]==0)
		{
			ma[y]=1;
			dfs(y);
			ma[y]=0;
		}
		num[now]+=num[y];//每个子节点的和
	}
	if(num[now]==0)//判断出en以外的终点
	{
		flag=1;
	}
	return num[now];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
	}
	cin>>be>>en;
	ma[be]=1;
	num[en]=1;
	cout<<dfs(be);
	if(flag==1)cout<<" No";
	else cout<<" Yes";
	return 0;
}
```



### **7-3**

宽搜板子了算是，多判断一下每个点周围雷的个数

AC代码：

```cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int dx[10]={0,1,1,1,0,0,-1,-1,-1};
int dy[10]={0,-1,0,1,-1,1,-1,0,1};
int n,m,k,l;
int ma[25][25];//图 
int mapp[25][25];//雷 
bool check()//win否
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(ma[i][j]==-1)sum++;
		}
	}
	if(sum==k)return true;
	return false;
}
int v[25][25];//记录是否走过 
void bfs(int a,int b)
{
	queue<pair<int,int> >q;
	q.push({a,b});
	v[a][b]=1;
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		int num=0;
		for(int i=1;i<=8;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx>=0&&yy>=0&&xx<n&&yy<m)
			{
				if(mapp[xx][yy]==1)num++;
			}
		}
		if(num!=0)ma[x][y]=num;
		else
		{
			ma[x][y]=0;
			for(int i=1;i<=8;i++)
			{
				int xx=x+dx[i];
			    int yy=y+dy[i];
			    if(xx>=0&&yy>=0&&xx<n&&yy<m&&v[xx][yy]==0)
			    {
			    	v[xx][yy]=1;
			    	ma[xx][yy]=0;
			        q.push({xx,yy});
				}
			}
		}
	}
}
int main()
{
	cin>>n>>m>>k>>l;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ma[i][j]=-1;
		}
	}
	for(int i=1;i<=k;i++)
	{
		int a,b;
		cin>>a>>b;
		mapp[a][b]=1;
	}
	while(l--)
	{
		int a,b;
		cin>>a>>b;
		if(mapp[a][b]==1)
		{
			cout<<"You lose";
			return 0;
		}
		else if(v[a][b]==1)continue;
		else
		{
			bfs(a,b);
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					cout<<ma[i][j]<<" ";
				}
				cout<<endl;
			}
			if(check())
			{
				cout<<"You win";
				return 0;
			}
			else cout<<endl;
		}
	}
	return 0;
}
```



### **7-4**

~~自信宽搜，果断超时~~

改进：

​        进行块处理，连通的一系列格子都可以直接等于连通格子的个数

AC代码：

```cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int dx[5]={0,1,0,0,-1};//移动 
int dy[5]={0,0,1,-1,0};//移动 
int n,m;
int ma[1005][1005];//存图 
int mapp[1005][1005];//记录是否走过 
int dis[1005][1005];//记录可以到达的格子数 
int k[1000005][3];//记录连通块的每个点的坐标 
string s;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int j=0;j<=n-1;j++)
		{
			if(s[j]=='0')
			{
				ma[i][j+1]=0;
			}
			else if(s[j]=='1')
			{
				ma[i][j+1]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=inf;
		}
	}
	while(m--)
	{
		int ans=1;
		int a,b;
		scanf("%d%d",&a,&b);
		if(mapp[a][b]!=0)//该块已经处理过了 
		{
			if(m)printf("%d\n",dis[a][b]);
			else printf("%d",dis[a][b]);
			continue;
		}
		queue<pair<int,int> >q;
		k[ans][1]=a;
		k[ans][2]=b;
		mapp[a][b]=1;
		q.push({a,b});
		while(!q.empty())
		{
			int x=q.front().first;
			int y=q.front().second;
			q.pop();
			for(int i=1;i<=4;i++)
			{
				int xx=x+dx[i];
				int yy=y+dy[i];
				if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&mapp[xx][yy]==0)
				{
					if(ma[xx][yy]!=ma[x][y])
					{
						mapp[xx][yy]=1;
						ans++;
						q.push({xx,yy});
						k[ans][1]=xx;//（xx，yy）加入这一区块 
						k[ans][2]=yy;//（xx，yy）加入这一区块
					}
				}
			}
		}
		for(int i=1;i<=ans;i++)
		{
			dis[k[i][1]][k[i][2]]=ans;//每个格子都附成区块的格子数 
		}
		if(m)printf("%d\n",dis[a][b]);
		else printf("%d",dis[a][b]);
	}
	return 0;
}
```

