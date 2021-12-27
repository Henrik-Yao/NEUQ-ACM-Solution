# **寒假集训—day1（线性表，栈，队列，字符串）**

## **7-1**

前缀和：

​        查询方便（ O(1) ），添加不方便（ O(n) ）,对于本题，添加会超时。

**树状数组：**

​        单次查询和添加都为O(logn),可以通过。

具体操作如下:

**lowbit(x)代表图中从最底层到达x的长度**

如lowbit(6)代表从101（十进制为5）到110（10进制为6）的长度，lowbit(6)=2.

~~~cpp
int lowbit(int x)
{
	return x&(-x);
}
~~~

![12.png](https://s2.loli.net/2021/12/25/JqjPyHrvfgG6xDS.png)

**c[y]代表所有子节点的和（包括自己）**

查询时，从当前位置向前遍历，把所有前边的区间都加上

如下图：求前6（二进制为110）项和，结果为①的区域加上②的区域，c[6]表示①区域的和（即a[5]+a[6]），c[4]表示②区域的和（即a[1]+a[2]+a[3]+a[4]）。

区间跳转：x-=x&-x即可从当前区间跳到上一个区间的根节点  6-lowbit(6)=6-2=4.

具体代码如下

~~~cpp
int ask(int x)//前x项和
{
	int ans=0;
	for(;x;x-=x&-x)ans+=c[x];
	return ans;
}
~~~

![img](https://s2.loli.net/2021/12/25/nvq3Q1SjmKprix9.jpg)

添加时，遍历父节点，父节点全部添加。

~~~cpp
void add(int x,int y)//x位置加y
{
	for(;x<=n;x+=x&-x)c[x]+=y;
}
~~~



##  **7-2**

可以用来练习链表，注意一些操作细节即可：

1.替换模式下，删除的是前边的一个字符，而非当前字符

2.替换模式下，替换完当前字符后，光标会自动后移一位

3.使用链表时要把头和尾单独独立出来，尽量不使用

~~~cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
string a;
struct node
{
	node *nex,*pre;
	char c;
};
node ans[50005];
node *head,*tail;
node *now;//now指每个字符的位置前边
int op=1;//当前是插入还是替换 
int len=0;//链表长度 
int main()
{
	head=ans;
	tail=(ans+50004);
	head->pre=NULL;
	head->nex=tail;
	tail->pre=head;
	tail->nex=NULL;
	getline(cin,a);
	
	int noww=0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]!='['&&a[i]!=']'&&a[i]!='{'&&a[i]!='}'&&a[i]!='-'&&a[i]!='=')
		{
			ans[++len].c=a[i];
			head->nex=(ans+len);
			tail->pre=(ans+len);
			(ans+len)->pre=head;
			(ans+len)->nex=tail;
			now=tail;
			noww=i;
			break;
		}
	}
	for(int i=noww+1;i<a.length();i++)
	{
		if(a[i]=='[')now=head->nex;
		else if(a[i]==']')now=tail;
		else if(a[i]=='{')
		{
			if(now!=head->nex)
			{
				now=now->pre;
			}
		}
		else if(a[i]=='}')
		{
			if(now!=tail)
			{
				now=now->nex;
			}
		}
		else if(a[i]=='-')
		{
			op=-op;
		}
		else if(a[i]=='=')
		{
			if(now->pre!=head->nex)
			{
				now->pre->pre->nex=now;
				now->pre=now->pre->pre; 
			}
			else if(now->pre==head->nex)
			{
				head->nex=now;
				now->pre=head;
			}
			else if(now==tail)
			{
				tail->pre=tail->pre->pre;
				tail->pre->pre->nex=tail;
			}
		}
		else
		{
			if(op==1)
			{
				if(now!=head->nex&&now!=tail)
				{
					ans[++len].c=a[i];
					(ans+len)->pre=now->pre;
					(ans+len)->nex=now;
					now->pre->nex=(ans+len);
					now->pre=(ans+len);
				}
				if(now==head->nex)
				{
					ans[++len].c=a[i];
					(ans+len)->nex=head->nex;
					head->nex->pre=(ans+len);
					head->nex=(ans+len);
					(ans+len)->pre=head;
				}
				else if(now==tail)
				{
					ans[++len].c=a[i];
					tail->pre->nex=(ans+len);
					(ans+len)->pre=tail->pre;
					(ans+len)->nex=tail;
					tail->pre=(ans+len);
				}
			}
			else if(op==-1)
			{
				if(now!=tail)
				{
					now->c=a[i];
					now=now->nex;
				}
				else
				{
					ans[++len].c=a[i];
					tail->pre->nex=(ans+len);
					(ans+len)->pre=tail->pre;
					(ans+len)->nex=tail;
					tail->pre=(ans+len);
				}
			}
		}
	}
	for(node *i=head->nex;i!=tail;i=i->nex)
	{
		if(i==tail)break;
		cout<<i->c;
	}
	return 0;
}
~~~



## **7-3**

简单的模拟，标记该人是否已经出列即可。

或者使用双向循环链表及时删除出列的人。



## **7-4**

链表模板题，有必要多做几次

### **链表主要操作如下：**

**链表定义：**

~~~ cpp
struct node
{
	node *nex,*pre;//指向下一个元素和前一个元素
	int num;//记录该元素数据
};
~~~

**建立一个新链表：**

~~~cpp
node *heads,*tails;//头尾指针
void setnode()
{
	heads=new node();//初始化表头
	tails=new node();//初始化表尾
	heads->nex=tails;
	tails->pre=heads;
}
~~~

**插入数据：**

~~~cpp
void insert(node *p,int val)//在p这个元素的后边加上一个新元素，其值为val
    ，新表数值为val
{
	node *q=new node();
	q->num=val;
	p->nex->pre=q;
	q->nex=p->nex;
	p->nex=q;
	q->pre=p;
}
~~~

**删除数据：**

~~~cpp
void remove(node *p)//删除p这个元素
{
	p->pre->nex=p->nex;
	p->nex->pre=p->pre;
	delete p;
}
~~~

**删除链表：**

~~~cpp
void recycle()
{
	while(heads!=tails)
	{
		heads=heads->nex;
		delete heads->pre;
	}
	delete tails;
}
~~~

**循环输出链表：**

~~~cpp
for(node *i=heads->nex;i!=tails;i=i->nex)
	{
		if(i!=tails->pre)cout<<i->num<<"->";
		else cout<<i->num<<endl;
	}
~~~





完整代码：

~~~cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;

int len=0;
int a[100005];


struct node
{
	node *nex,*pre;
	int num;
};
node *heads,*tails;
node *heads1,*tails1;
void setnode()
{
	heads=new node();
	tails=new node();
	heads->nex=tails;
	tails->pre=heads;
}
void setnode1()
{
	heads1=new node();
	tails1=new node();
	heads1->nex=tails1;
	tails1->pre=heads1;
}
void insert(node *p,int val)
{
	node *q=new node();
	q->num=val;
	p->nex->pre=q;
	q->nex=p->nex;
	p->nex=q;
	q->pre=p;
}
void remove(node *p)
{
	p->pre->nex=p->nex;
	p->nex->pre=p->pre;
	delete p;
}
void re()
{
	while(heads!=tails)
	{
		heads=heads->nex;
		delete heads->pre;
	}
	delete tails;
}
void re1()
{
	while(heads1!=tails1)
	{
		heads1=heads1->nex;
		delete heads1->pre;
	}
	delete tails1;
}
int main()
{
	while(scanf("%d",&a[++len])!=EOF);
	sort(a+1,a+len);
	setnode();
	setnode1();
	node *nows=heads;
	node *nows1=heads1;
	for(int i=1;i<len;i++)
	{
		insert(nows,a[i]);
		nows=nows->nex;
	}
	for(node *i=heads->nex;i!=tails;i=i->nex)
	{
		if(i!=tails->pre)cout<<i->num<<"->";
		else cout<<i->num<<endl;
	}
	for(node *i=heads->nex;i!=tails;i=i->nex)
	{
		node *j=i->pre;
		if(i->num%2==0)
		{
			insert(nows1,i->num);
			nows1=nows1->nex;
			remove(i);
			i=j;
		}
	}
	for(node *i=heads->nex;i!=tails;i=i->nex)
	{
		if(i!=tails->pre)cout<<i->num<<"->";
		else cout<<i->num<<endl;
	}
	if(heads->nex==tails)cout<<endl;
	for(node *i=heads1->nex;i!=tails1;i=i->nex)
	{
		if(i!=tails1->pre)cout<<i->num<<"->";
		else cout<<i->num;
	}
	re();
	re1();
	return 0;
}
~~~



## **7-5**

1.压栈匹配即可

2.顺便记录下未匹配的括号数



## **7-6**

同上1.



## **7-7**

题目有些花里胡哨，理解了就很简单

简单的模拟



## **7-8**

同7-6



## **7-9**

模拟，加队列

基本思路：按顺序每次队列加入一个人，并向后在有效时间内寻找有无他的朋友，若有则朋友入队，若无，则下一个人入队。

代码中有解释：

~~~cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
map<string,int>mmp;//属于那个圈子
struct node
{
	string name;
	int t,p;
}nodes[100005];
bool vis[100005];
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int l;
		cin>>l;
		for(int j=0;j<l;j++)
		{
			string name;
			cin>>name;
			mmp[name]=i+1;
		}
	}
	int tot=m+1;
	for(int i=0;i<n;i++)
	{
		cin>>nodes[i].name>>nodes[i].t>>nodes[i].p;
		if(!mmp[nodes[i].name])mmp[nodes[i].name]=tot++;
		if(nodes[i].p>60)nodes[i].p=60;
	}
	int ans=0;//等待时间 
	int time=nodes[0].t+nodes[0].p;//总用时 
	queue<node>q;
	q.push(nodes[0]);
	vis[0]=true;
	while(!q.empty())
	{
		node now=q.front();
		cout<<now.name<<endl;
		q.pop();
		bool flag=false;
		for(int i=1;i<n;i++)//寻找有无朋友 
		{
			if(vis[i])continue;
			if(nodes[i].t>time)break;
			if(mmp[nodes[i].name]==mmp[now.name])//有 
			{
				q.push(nodes[i]);
				vis[i]=true;
				flag=true;
				ans+=time-nodes[i].t;//加上该朋友等待的时间 
				time+=nodes[i].p;//结束时间加上朋友用的时间 
				break;
			}
		}
		if(!flag)//无朋友
		{
			for(int i=1;i<n;i++)//寻找下一个人 
			{
				if(vis[i])continue;
				q.push(nodes[i]);
				vis[i]=true;
				ans+=max(0,time-nodes[i].t);//加上该人的等待时间 
				if(nodes[i].t>time)time=nodes[i].t;//用该人所用的时间更新总用时 
				time+=nodes[i].p;
				break;
			}
		}
	}
	printf("%0.1lf",1.0*ans/n);
	return 0;
}
~~~



## **7-10**

其实是求下降子序列的个数。