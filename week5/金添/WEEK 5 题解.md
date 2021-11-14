# WEEK 5 题解

### 7-1**愿天下有情人都是失散多年的兄妹**

首先定义一个全局变量visit，可以标记该人是否被访问过。

对于每次输入，第num编号的元素输入一个二维数组，标记为自己的父母，并将父母性别进行标记

每次对每个对象单独访问，若有访问重叠，直接标记为NO

```C++
#include <bits/stdc++.h>
using namespace std;
int mark[200005][2];//[0]为父[1]为母 
bool visit[200005];
char sex[200005];
bool judge;//记录监视是否有相同祖先 
int num,k;
void search(int remp,int flag)//flag记录代数！！！ 
{
	if(flag>5)
	return;
	if(remp<=0)
	return;
	if(visit[remp])
	judge=1;//若先前标记过，即是骨科 
	visit[remp]=1;//此人已标记 
	search(mark[remp][0],flag+1);
	search(mark[remp][1],flag+1);
	
}

int main()
{
	cin>>num;
	for(int i=1;i<=num;i++)
	{
		int remp,remp1,remp2;
		char ch;
		cin>>remp>>ch>>remp1>>remp2;
		sex[remp]=ch,sex[remp1]='M',sex[remp2]='F';//将输入的本人和父母性别计入 
		mark[remp][0]=remp1;mark[remp][1]=remp2;//标记亲子关系 
	}	
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int remp1,remp2;
		cin>>remp1>>remp2;
		if(sex[remp1]==sex[remp2])
		{
			cout<<"Never Mind"<<endl;
			continue;
		}
		memset(visit,0,sizeof(visit));
		judge=0;
		search(remp1,1);
		search(remp2,1);
		if(judge)
		cout<<"No";
		else
		cout<<"Yes";
		if(i!=k)
		cout<<endl;
	}
}
```

### 7-2**哥德巴赫最新猜想**

一个小规律，注意这道题和欧拉筛和埃式筛没关系

对于一个n

n如果为偶数，n必为合数

n如果为奇数，如果n为质数，则每个质数等于两个质数之和

​						如果n为合数，减去2后，即为3个素数之和	

```C++
#include <bits/stdc++.h>
using namespace std;
bool judge(int a)
{
	bool flag=1;
	for(int j=2;j<=sqrt(a);j++)
	{
		if(a%j==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int main()
{
	int num,remp,ans;
	cin>>num;
	for(int i=1;i<=num;i++)
	{
		cin>>remp;
		if(remp%2==0)//每个不小于6的偶数都是两个素数之和
		{
			ans=2;
		}
		else
		{
			if(judge(remp))
			{
				ans=1;//加数即是它自己 
			}
			else
			{
				if(judge(remp-2))
				ans=2;
				else
				ans=3; 
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
```

### **7-3 图深度优先遍历**

首先定义一个数组graph二维

然后通过输入一个来进行单项图标记

然后定义一个循环进行对每一个点做一次深度遍历

即解

```C++
#include <bits/stdc++.h>
using namespace std;
int graph[51][2];
bool visit[200001];
int n,e;
void search(int remp)
{
	if(visit[remp])
	return;
	visit[remp]=1;
	cout<<remp<<" ";
	int mini=n; 
	for(int i=1;i<=e;i++)
	{
		if(graph[i][0]==remp&&visit[graph[i][1]]==0)//起点相同，终点没有访问过 
		mini=min(mini,graph[i][1]);
	}
	if(mini!=n)//防止一轮寻找下来轮空了，导致mini还是n默认值 
	search(mini);
}
int main()
{
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>graph[i][0];
		cin>>graph[i][1];
	}	
	for(int i=0;i<n;i++)
	search(i);
	
	return 0;
}
```

### **7-4 山**

相当一个迷宫问题变式，连通块原理可以轻易解决

将字号相同且相邻的元素进行标记计数，并将计数结果放入另外一个数组进行统计

最后统计数组个数即可

```C++
#include <bits/stdc++.h>
using namespace std;
int n,m;//行，列
bool shan[2010][2010];
bool visit[2010][2010]; 
int dirx[4]={0,0,-1,1};
int diry[4]={1,-1,0,0};
int num=0;//记录连通块 
int flag;//记录山的个数 
void search(int hang,int lie)
{
	if(!(hang<=n&&hang>0&&lie<=m&&lie>0))
	return;	
	visit[hang][lie]=1;
	for(int k=0;k<4;k++)
	{
		int rempx=dirx[k]+hang;
		int rempy=diry[k]+lie;
		if((visit[rempx][rempy]==0)&&shan[rempx][rempy]==1)
		search(rempx,rempy);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>shan[i][j];
		}
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(visit[i][j])
			continue;
			if(shan[i][j])
			{
				search(i,j);
				num++;
			}
		}
	}
	cout<<num;
	return 0;
 } 

```

### **7-5 跳跃**

经典的深度优先搜索，将每个格子数字放入数组中，对于访问每一个数组，都进行叠加即可

```C++
#include <bits/stdc++.h>
using namespace std;
int path[50010];
bool visit[50010];
bool flag;
int num;
void search(int start)
{
	if(flag)
		return;
	if (visit[start])
		return;
	if (start>=num||start<0)
		return;
	visit[start] = 1;
	if (!path[start])
	{
		flag = 1;
		return;
	}
	search(start + path[start]);
	search(start - path[start]);
}
int main()
{
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> path[i];
	}
	int start;
	cin >> start;
	search(start);
	if (flag)
		cout << "True";
	else
		cout << "False";
	return 0;
}
```





