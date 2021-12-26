# **寒假集训—day2（树）**

# **7-1**

带空指针信息的二叉树先根序列（先序序列），模板题

**用先根序列建二叉树**

每个0都代表上一个数的没有一个儿子

**对带空指针信息的二叉树先根序列的理解：**

例：1 -2 0 0 3 -1 0 0 -1 0 0 代表的二叉树如下图（0不代表真正的节点）

-2后边的第一个0代表-2没左孩子，第二个0代表没右孩子，所以-2为叶节点，然后返回-2的父亲1，3为1的右孩子......一次类推

![img](https://s2.loli.net/2021/12/26/W8hmLMcKG7yopF2.jpg)

**代码：**

~~~cpp
//带空指针信息的二叉树先根序列
#include<bits/stdc++.h>

using namespace std;
int ans[105];
int maxn;
int maxans=-100000;
int anss;
struct node
{
	int val;
	int step;//记录深度
	node *l,*r;//指向左孩子和右孩子
};
node *creat(int s)//建立二叉树
{
	node *bt;
	int x;
	cin>>x;
	if(x==0)bt=NULL;
	else
	{
		bt=new node();
		bt->val=x;
		bt->step=s+1;
		if(bt->step>maxn)maxn=bt->step;
		bt->l=creat(bt->step);
		bt->r=creat(bt->step);
	}
	return bt;
}
void vis(node *bt)//对二叉树进行遍历，计算每层的叶节点值（无空指针）
{
	if(bt==NULL)return;
	else
	{
		if(bt->l==NULL&&bt->r==NULL)ans[bt->step]+=bt->val;//叶节点 
		vis(bt->l);
		vis(bt->r);
	}
}
int main()
{
	node *bt=creat(-1);
	vis(bt);
	for(int i=maxn;i>=0;i--)
	{
		if(ans[i]>maxans&&ans[i]!=0)//无叶节点的层不算 
		{
			maxans=ans[i];
			anss=i;
		}
	}
	cout<<anss;
	return 0;
}
~~~



## **7-2**

建树模板题，可根据**先序序列和中序序列**，或者**后序序列和中序序列**建立一个二叉树

**中序序列的性质：**

取x节点左边的某一点，若该点是x的后代节点，则该节点一定位于x的左子树上

取x节点右边的某一点，若该点是x的后代节点，则该节点一定位于x的右子树上

如下图：

中根序列：[6,3,4,1,5,8,2,7]

3，6都为4的左边的后代节点，所以一定都在4的左子树上

![img](https://s2.loli.net/2021/12/26/qwnD73YTvahKz6o.png)

前根序列：[4,6,3,2,5,1,8,7]

后根序列：[3,6,1,8,5,7,2,4]

中根序列：[6,3,4,1,5,8,2,7]



**前根序列从左边开始算根**

**后根序列从右边开始算根**



AC代码：

~~~cpp
//根据后根序列和中根序列 得到前根序列 
#include<bits/stdc++.h>

using namespace std;
int maxn=0;
bool ans;
string in,post;
struct node
{
	char val;
	int step;
	node *l,*r;
};
node *creat(int poststart,int postend,int instart,int inend)
{
	node *root=new node();//root代表当前子树
	root->val=post[postend];//当前子树的根节点
	root->l=NULL;
	root->r=NULL;
	int n=0;
	bool flag=0;//判断两个序列能否对应上
	for(n;n<=inend;n++)//root的左子树长度为n-1,n为根节点，n右边为右子树 
	{
		if(in[instart+n]==root->val)
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		if(n>=1)
			root->l=creat(poststart,poststart+n-1,instart,instart+n-1);
	//post中从poststart到poststart+n-1都是左子树的节点，in中从instart到instart+n-1都是左子树的节点，instart+n为root的根节点
		if(instart+n<inend)
			root->r=creat(poststart+n,postend-1,instart+n+1,inend);
        //同上，都是右子树的节点
	}
	
		
	if(!flag)ans=false;
	
	return root;
}
void high(node *x,int s)
{
	if(x==NULL)return;
	x->step=s;
	if(s>maxn)maxn=s;
	high(x->l,s+1);
	high(x->r,s+1);
}
void visit(node *x,int s)//前序遍历输出
{
	if(x==NULL)return;
	if(s!=-1)cout<<x->val;//
	visit(x->l,s+1);      //该三行的顺序代表前序，中序还是后序
	visit(x->r,s+1);      //
}
int main()
{
	while(cin>>post)
	{
		cin>>in;
		
		maxn=0;ans=true;
		
		node *x=creat(0,post.length(),0,in.length());
		if(ans)
		{
			high(x,-1);//-1层为初始的空节点 
			cout<<maxn<<endl;
			visit(x,-1);
			cout<<endl;
		}
		else
		{
			cout<<"INVALID"<<endl;
		}
	}
	return 0;
}
~~~



## **7-3**

利用先根序列建立森林，并求解最近公共祖先

采用左儿子又右兄弟的记录方法，达成用二叉树记录普通树的效果

下图一目了然

![img](https://s2.loli.net/2021/12/26/QiVvBq3ZOGrWwt2.png)

AC代码：

~~~cpp
//左儿子右兄弟的存树方式
#include<bits/stdc++.h>

using namespace std;
int t;
int ans;
map<int,int>v;
struct node
{
	node *child=NULL;//记录该点的第一个儿子，其他的儿子记成该儿子的兄弟 
	node *brother=NULL;//记录该点的第一个兄弟，第二个个兄弟由第一个兄弟记录 
	node *fa=NULL;
	int len=0;
	int val=0;
};
node *creat()
{
	node *root=new node();
	root->child=NULL;
	root->brother=NULL;
	int a;
	cin>>a;
	if(a==0)root=NULL;
	else
	{
		root->val=a;
		root->child=creat();//child是root的大孩子 
		root->brother=creat();//brother是next的兄弟 
	}
	return root;
}
void findfa(node *x,node *fa)
{
	if(x==NULL)return;
	x->fa=fa;
	findfa(x->child,x);//自己儿子的父亲就是自己 
	findfa(x->brother,fa);//自己兄弟和自己父亲相同 
}
void find(node *z,int a,int b,node *&x,node *&y)
{
	if(z==NULL)return;
	if(z->val==a)x=z;
	if(z->val==b)y=z;
	find(z->child,a,b,x,y);
	find(z->brother,a,b,x,y);
}
void dfs1(node *x)
{
	if(x==NULL)return;
	v[x->val]=1;
	dfs1(x->fa);
}
void dfs2(node *y)
{
	if(y==NULL)return;
	if(v[y->val]!=0)
	{
		ans=y->val;
		return;
	}
	dfs2(y->fa);
}
int main()
{
	cin>>t;
	while(t--)
	{
		v.clear();
		
		int a,b;
		node *bt=creat();
		ans=bt->val;
		findfa(bt,NULL);
		cin>>a>>b;
		node *x,*y;
		find(bt,a,b,x,y);
		dfs1(x);
		dfs2(y);
		cout<<ans<<endl;
		delete bt; 
	}
	return 0;
}
~~~





##  **7-4**

连通块，不说了，在主函数中多次遍历dfs即可

代码如下：

~~~cpp
//连通块 
#include<bits/stdc++.h>

using namespace std;
int n,m,q;
struct node
{
	int nex,fro,to;
}e[2005];
int head[2005];
int cnt;
void add(int a,int b)
{
	e[++cnt].fro=a;
	e[cnt].to=b;
	e[cnt].nex=head[a];
	head[a]=cnt;
}


int ans;
int v[1005];
void dfs(int x)
{
	v[x]=ans;
	for(int i=head[x];i;i=e[i].nex)
	{
		int y=e[i].to;
		if(!v[y])dfs(y);
	}
}
int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			ans++;
			dfs(i);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int a,b;
		cin>>a>>b;
		if(v[a]==v[b])cout<<"In the same gang."<<endl;
		else cout<<"In different gangs."<<endl;
	}
	cout<<ans;
	return 0;
}
~~~



## **7-5**

写此题要了解哈夫曼树

[该博客讲的灰常好](https://blog.csdn.net/bjweimengshu/article/details/105383513)

无论是什么方法，最简洁的压缩长度就是哈夫曼压缩方式的长度

代码：

~~~cpp
//7-7 哈夫曼编码
#include<bits/stdc++.h>

using namespace std;
int n,m;
char c[100];
int f[1000];
int ans=0;//哈夫曼长度
int sum=0;//题设方式的长度
int flag=0;
priority_queue<int,vector<int>,greater<int> >q;//固定写法，实现小根堆 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		getchar();
		cin>>c[i]>>f[i];
		q.push(f[i]);
	}
	while(q.size()>1)
	{
		int x=q.top();
		q.pop();
		int y=q.top();
		q.pop();
        //每次取最小的两个数相加构成新节点
		q.push(x+y);
		ans+=x+y;
	}
	
	cin>>m;
	while(m--)
	{
		char s[75][75];
		sum=0;
		for(int i=1;i<=n;i++)
		{
			getchar();
			char x;
			cin>>x>>s[i];
			sum+=(int)strlen(s[i])*f[i];
		}
		if(sum!=ans)
		{
			cout<<"No"<<endl;
		}
		else
		{
			flag=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j)
					{
						if(strstr(s[i],s[j])==&s[i][0])//判断某个序列是否是另一个序列的前缀，strstr返回子串在源字符串的起始位置的指针
						{
							flag=1;
							break;
						}
					}
				}
				if(flag==1)break;
			}
			if(flag==1)cout<<"No"<<endl;
			else cout<<"Yes"<<endl;
		}
	}
	
	return 0;
}
~~~



## **7-6**

类同7-2

代码：

~~~cpp
//7-5 二叉树路径和
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n;
int pre[25],mid[25];
struct node
{
	int val;
	node *l,*r;
};
node *build(int prestart,int preend,int midstart,int midend)
{
	node *root=new node();
	root->val=pre[prestart]; 
	root->l=NULL;
	root->r=NULL;
	int n=0;
	while(root->val!=mid[midstart+n])n++;//n-1为 左子树长度 
	if(n>=1)root->l=build(prestart+1,prestart+n,midstart,midstart+n-1);
	if(midstart+n<midend)root->r=build(prestart+n+1,preend,midstart+n+1,midend);
	return root;
}
void vis(node *a)
{
	if(a==NULL)return;
	vis(a->l);
	vis(a->r);
	cout<<a->val<<" ";
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>pre[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>mid[i];
	}
	node *bt=build(1,n,1,n);
	vis(bt);
	return 0;
}
~~~



## **7-7**

类同7-2

代码：

~~~cpp
//7-7 按层遍历二叉树
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n;
int pre[25];
int mid[25];
struct node
{
	node *l,*r;
	int val;
};
node *build(int prestart,int preend,int midstart,int midend)
{
	node *root=new node();
	root->l=NULL;
	root->r=NULL;
	root->val=pre[prestart];
	int len=0;
	while(mid[midstart+len]!=root->val)len++;
	if(len>=1)
		root->l=build(prestart+1,prestart+len,midstart,midstart+len-1);
	if(midstart+len<midend)
		root->r=build(prestart+len+1,preend,midstart+len+1,midend);
	return root;
}
void vis(node *a)
{
	queue<node*>q;
	q.push(a);
	while(!q.empty())
	{
		node *a=q.front();
		q.pop();
		cout<<a->val<<" ";
		node *x=a->l;
		node *y=a->r;
		if(x!=NULL)q.push(x);
		if(y!=NULL)q.push(y);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>pre[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>mid[i];
	}
	node *bt=build(1,n,1,n);
	vis(bt);
	return 0;
}
~~~



## **7-8**

层序，从0开始编号，则now * 2+1为now的左儿子编号，now * 2+2为now的右儿子编号

~~~cpp
//7-8 中序遍历二叉树
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int t;
int n;
int maxn=0;
int num[1005];
struct node
{
	node *l,*r;
	int val;
	int step;
};
void build(node *root,int now,int step)
{
	if(now<n)
	{
		root->val=num[now];
		root->step=step;
		if(step>maxn)maxn=step;
		if(2*now+1<n&&num[now*2+1]!=0)
		{
			root->l=new node();
			build(root->l,now*2+1,step+1);
		}
		if(2*now+2<n&&num[now*2+2]!=0)
		{
			root->r=new node();
			build(root->r,now*2+2,step+1);
		}
	}
}
int hi=0;
void vis(node *a)
{
	if(a==NULL)return;
	vis(a->l);
	if(hi==0)//垃圾pta，牛马输出格式，毁我青春
	{
		cout<<a->val;
		hi=1;
	}
	else if(hi==1)cout<<" "<<a->val;
	vis(a->r);
}
int main()
{
	cin>>t;
	while(t--)
	{
		memset(num,0,sizeof(num));
		maxn=0;
		hi=0;
		cin>>n;
		for(int i=0;i<n;i++)cin>>num[i];
		node *bt=new node();
		build(bt,0,1);
		vis(bt);
		cout<<endl;
		if(t)cout<<maxn<<endl;
		else cout<<maxn;
	}
	return 0;
}
~~~



## **7-9**

类同7-2