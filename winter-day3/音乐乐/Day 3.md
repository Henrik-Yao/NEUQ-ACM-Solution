# DAY 3

---

## 7-1 图的创建

邻接表+vector

```c++
#include<bits/stdc++.h> 
using namespace std;
vector<int>v[20010];
int m,adj[20010],temp[20010],mem[20010];
struct edge
{
	int to;
	int next;
	int w;
}e[20010];
void add(int x,int y,int z)
{
	++m;
	v[x].push_back(m);
	e[m].to=y;
	e[m].next=x;
	e[m].w=z;
}

int main()
{
	int n,ed,i;
	cin>>n>>ed;
	for(i=1;i<=ed;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	//for(i=0;i<n;i++)
		//cout<<i<<' '<<v[i].size()<<endl;
	for(i=0;i<n;i++)
	{
		memset(temp,0,sizeof(temp));
		memset(mem,0,sizeof(mem));
		if(v[i].size())
		{
			int cap=v[i].size();
			for(int j=0;j<cap;j++)
			{
				temp[j]=e[v[i][j]].to;
				mem[temp[j]]=e[v[i][j]].w;
			}
			sort(temp,temp+cap);
			cout<<i<<':';
			for(int j=0;j<cap;j++)
			{
				cout<<"("<<i<<","<<temp[j]<<","<<mem[temp[j]]<<")";
			} 
			cout<<endl;
		}
	}
	return 0;
}
```



## 7-2 图的删边操作

将目的地对应的出发点全部放入set，直接排序好了，对应元素也可以直接删除，无需遍历。二维数组储存边权，想找时直接取出。

```c++
#include<bits/stdc++.h> 
using namespace std;
set<int>setting[20001];
set<int>::iterator j;
int arr[20001][20001];
int m;
struct edge
{
	int to;
	int next;
	int w;
}e[1001];
void add(int x,int y,int z)
{
	++m;
	setting[x].insert(y);
	arr[x][y]=z;
}
void erase(int x,int y)
{
	setting[x].erase(y);
}

int main()
{
	int n,ed,i;
	cin>>n>>ed;
	for(i=1;i<=ed;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	int k;
	cin>>k;
	while(k--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		erase(a,b);
	}
	//for(i=0;i<n;i++)
		//cout<<i<<' '<<v[i].size()<<endl;
	for(i=0;i<n;i++)
	{
		if(setting[i].size())
		{
			int cap=setting[i].size();
			cout<<i<<':';
			for(j=setting[i].begin();j!=setting[i].end();j++)
			{
				cout<<"("<<i<<","<<*j<<","<<arr[i][*j]<<")";
			} 
			cout<<endl;
		}
	}
	return 0;
}
```



## 7-4 岛屿数量

连通块问题，写过好多遍了。。。



## 7-6 最小支撑树

```c++
#include<bits/stdc++.h>
using namespace std;
int F[1501];
struct Edge
{
	int from;
	int to;
	int w;
}edge[1501];//生成边
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}//按照边权从小到大将边排序
int find(int x)
{
	if(F[x]==x)
	return F[x];
	else
	return F[x]=find(F[x]);
}//并查集模板，递归到代表元
bool fun(int a,int b)
{
	int x=find(a);
	int y=find(b);
	//cout<<"x"<<x<<' '<<"y"<<y<<' '<<endl;
	if(x!=y)
	{
		F[y]=x;
		return true;
	}
	return false;
}//比较a,b的find()值判断它们是否在一个集内，如果不在，就将b加入a的集

int main()
{
	int n,e,i;
	while(~scanf("%d%d",&n,&e))
	{
		int total=0,cnt=0;
		for(i=0;i<e;i++)
		{
			scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].w);
		}
		for(i=0;i<n;i++)
			F[i]=i;//初始化
		sort(edge,edge+e,cmp);
		for(i=0;i<e;i++)
		{
			if(fun(edge[i].from,edge[i].to))
			{
				total+=edge[i].w;
				cnt++;
			}//如果输入的两个端点不在一个集内，为其连上线后将边权加入total，连线数加一
			if(cnt==n-1)//已经构成最小生成树
			break;
		}
		//cout<<cnt<<' ';
		if(cnt==n-1) printf("%d\n",total);//树的特点：结点数-1==边数
        else cout<<"There is no minimum spanning tree."<<endl;
	}
	return 0;
}
```



## 7-5 繁忙的都市

跟7-6差不多，只是要输出边数和跳出循环时对应的最大边权。



## 7-7 特殊最小成本修路

在7-6基础上增加了一个特殊点，循环时要特判：

```C++
if((edge[i].from==v||edge[i].to==v)&&cnt<2)
{
	if(fun(edge[i].from,edge[i].to))
	{
		total+=edge[i].w;
		cnt++;
		num++;
	}
}
```

