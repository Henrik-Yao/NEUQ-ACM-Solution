# DAY 1

---

## 7-1 动态区间求和

这道题让我接触到了一个新的知识点：树状数组，形状上是二叉树的变形，利用二进制中一些01的巧妙变换使得如单点查找、单点修改、数列前缀和等执行效率大大提升。

![img](https://img-blog.csdnimg.cn/20200717113256650.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2Jlc3Rzb3J0,size_16,color_FFFFFF,t_70)

```c++
int lowbit(int x)//找到一个二进制数最低位的1所在的位置
{
	return x&(-x);
}
void update(int j,int n,int x)//单点更新
{
	for(int i=j;i<=n;i+=lowbit(i))
	{
		c[i]+=x;
	}
}
long long getsum(int add)//前缀查询
{
	long long ans=0;
	for(int i=add;i;i-=lowbit(i))
	{
		ans+=c[i];
	}
	return ans;
}
int main()
{
	int n,q,i;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		update(i,n,a);
	}//输入a[i]数列时直接用update函数完成树状数组c[]的构建
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int j,x;
			cin>>j>>x;
			update(j,n,x);
		}
		if(op==2)//前缀和相减->区间查询
		{
			int l,r;
			cin>>l>>r;
			long long sum;
			sum=getsum(r)-getsum(l-1);
			//cout<<"L"<<getsum(l-1)<<endl;
			//cout<<"R"<<getsum(r)<<endl;
			cout<<sum<<endl;	
		}
	}
	return 0;
}
```



## 7-3 特殊约瑟夫问题

```c++
#include<bits/stdc++.h>
using namespace std;
typedef struct tagNode//结构体构造链表，每个结点包括向前的指针、数据、向后的指针
{
	int data;
	struct tagNode *pre,*next;
}Node,*LinkList;

void InitList(LinkList *L)//初始化
{
	*L=(LinkList)malloc(sizeof(Node));
	//获取Node的字段长度，然后强转为LinkList类型。L变量就代表地址长度和Node一样所占内存空间同样大小的LinkList
	(*L)->next=(*L)->pre=*L;
	//初始化：两个指针都指向自身 
}

int main()
{
	int n,m,k,i;
	cin>>n>>m>>k;
	LinkList L;
	InitList(&L);
	struct tagNode *p,*q,*g;
	p=(LinkList)malloc(sizeof(Node));
	g=q=p;
	p->data=1;
	p->next=p;//p为头结点
	for(i=2;i<=n;i++)
	{
		q = (q->next=(LinkList)malloc(sizeof(Node)));//动态q，每次循环移向下一个位置
		q->pre=g;//g用于保存前一个位置，此处相当于将新的结点插入前一个结点后面
		q->data=i;
		q->next=p;
		g=g->next;
	}
	p->pre=g;//头结点的前端指向尾结点，构成循环链表
    //至此，双向循环链表已经构建完成，下面是模拟报数的过程
	q=p;//动态q回到头结点位置，开始报数
	for(int cnt=1;cnt<=n;cnt++)
	{
		if(cnt&1)//报数次为奇数次，逆时针，每次向前一个结点移动
		{
			if (m == 1)
			{
				printf("%d", q->data);
				q->next->pre = q->pre;
				q->pre->next = q->next;
				q = q->pre;
			}
			else
			{
				for (i=2;i<m;i++)
					q=q->pre;
				printf("%d ",q->pre->data);
				q->pre=q->pre->pre;
				q->pre->next=q;
				q = q->pre;
			}
		}
		else //报数次为偶数次，顺时针，每次向后一个结点移动
		{
			if (k == 1)
			{
				printf("%d", q->data);
				q->next->pre=q->pre;
				q->pre->next=q->next;
				q = q->next;
			}
			else
			{
				for (i=2;i<k; i++)
					q=q->next;
				printf("%d ", q->next->data);
				q->next=q->next->next; 
				q->next->pre=q;
				q=q->next;
			}
		}
	}
	return 0;
}
```



## 7-4 程序设计综合实践 1.4

一开始自己企图用最朴实的数组（如下）。。。按理说没啥问题，但一直报答案错误，可能是因为内存或者时限？不知道不清楚不明白不理解，白嫖WTW题解。很好懂倒是，就是有的细节问题格式问题要注意一下。

```
#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000],c[100000];

int main()
{
	int i=0,p=0,k=0,x;
	while(cin>>x) 
    {
        a[i++]=x;
        if('\n'==getchar())
        {
            a[i]='\0';
            break;
        }
    }
    if(a[0]=='\0')
    	return 0;
	sort(a,a+i);
	for(int j=0;j<i;j++)
	{
		if(a[j]&1)
            b[p++]=a[j];
        else
            c[k++]=a[j];
        if(j<i-1)
            cout<<a[j]<<"->";
	}
	cout<<a[i-1]<<endl;
	for(int j=0;j<p-1;j++)
		cout<<b[j]<<"->";
	cout<<b[p-1]<<endl;
	for(int j=0;j<k-1;j++)
		cout<<c[j]<<"->";
	cout<<c[k-1]<<endl;
	return 0;
}
```

```C++
#include <bits/stdc++.h>
using namespace std;

vector<int>a;
list<int>l1,l2,l3;
int main()
{
    int num;
    unsigned int i;
    while(cin>>num) 
		a.push_back(num);
    sort(a.begin(),a.end());
    if(!a.empty())
	{
	    printf("%d",a[0]);
	    for(int i = 1;i < a.size();i++) 
			printf("->%d",a[i]);
    }
    cout<<endl;
    for(i = 0;i < a.size();i++)
		l1.push_back(a[i]);
	list<int>::iterator it;
    for(it= l1.begin();it != l1.end();it++)
	{
        if(*it & 1) 
			l2.push_back(*it);
        else 
			l3.push_back(*it);
    }
    vector<int>v1(l2.begin(),l2.end()),v2(l3.begin(),l3.end());
	if(!v1.empty())
	{
	    printf("%d",v1[0]);
	    for(int i = 1;i < v1.size();i++) 
			printf("->%d",v1[i]);
    }
    cout<<endl;
    if(!v2.empty())
	{
	    printf("%d",v2[0]);
	    for(int i = 1;i < v2.size();i++) 
			printf("->%d",v2[i]);
    }
    a.clear();
	l1.clear();
	l2.clear();
	l3.clear();
	v1.clear();
	v2.clear();
    return 0;
}
```



## 7-5 括号匹配

我不知道自己的是不是常规思路，大概就是先用string保存原样，然后用stack把能配对的去掉（这里跟7-8差不多），最后留下的必然是)))))(((这样一个形式，看看栈内剩了几个没对象的括号，分分类：左括号有几个？右括号有几个？计一下数，然后在之前的string左端加若干个(，右端加若干个)。

```
#include<bits/stdc++.h>
using namespace std;
stack<char>st;

int main()
{
	string s;
	while(cin>>s)
	{
		 while(!st.empty())
 			st.pop();
		for(int i=0;i<s.size();i++)
		{
			char c=s[i];
			if(c=='(')
				st.push(c);
			if(c==')')
			{
				if(st.empty())
				{
					st.push(c);
					continue;
				}
				//cout<<st.top()<<endl;
				if(st.top()=='(')
				{
					st.pop();
				}
				else
				{
					st.push(')');
				}
			}
		}
		if(st.empty())
			cout<<"Match"<<endl;
		else
		{
			int cap=st.size();
			cout<<cap<<endl;
			int cnt=0;
			while(st.top()=='(')
			{
				cnt++;
				st.pop();
			}
			s.insert(s.size(),cnt,')');
			s.insert(0,cap-cnt,'(');
			cout<<s;
			cout<<endl;
		}
	} 
	return 0;
}
```



## 7-8括号配对

栈的经典题，是左括号就压入栈，是右括号就尽量拉一个陪葬，没有陪葬的就nonono,最后看看栈空不空。

```c++
#include<bits/stdc++.h>
using namespace std;
stack<char>st;

int main()
{
	string s;
	int i;
	cin>>s;
	//cout<<s<<endl;
	char c;
	for(i=0;i<s.size();i++)
	{
		c=s[i];
		if(c=='['||c=='(')
			st.push(c);
		if(c==']')
		{
			//cout<<st.top()<<endl;
			if(st.top()=='[')
			{
				st.pop();
			}
			else
			{
				cout<<"no"<<endl;
				return 0;
			}
		}
		if(c==')')
		{
			//cout<<st.top()<<endl;
			if(st.top()=='(')
			{
				st.pop();
			}
			else
			{
				cout<<"no"<<endl;
				return 0;
			}
		}
	}
	if(st.size())
		cout<<"no";
    else
        cout<<"yes";
	return 0;
}
```



## 7-6 字符串对称

这道题宛如救命稻草一样横空出世，让我知道寄几兴许还能找到会做的题。但是自己懒得写reverse，还忘了参数怎么写，查了一下：	reverse(s.begin(),s.end());



## 7-7魔王解释语言

题目看懂很费神，看懂了还好，但是我有几个字符串操作老是搞不定，最后只能放弃那种做法。烦。



## 7-10 列车车厢重排

我怀疑班里没别的人这么做：二分答案。。。时间效率大概也不是特别好，大概有O（n^2*logn)，反正数据范围那么小，随便瞎搞。但是一旦想到二分答案思路是很清晰的，就是我自己写的时候绕了好半天才把check写好，出了一大堆乱七八糟的毛病。

```c++
#include<bits/stdc++.h>
using namespace std;
int a[100],b[100],c[100];
int n,i;
bool check(int t,int n)
{
	for(i=0;i<n;i++)
		b[i]=a[i];
	//cout<<"t"<<t<<"n"<<n;
	int cnt=t;
	for(i=0;i<n&&cnt;i++)
	{
		if(b[i]==0)
		{
			continue;
		}
		else
		{
			//cout<<"i"<<i<<endl;
			int min=b[i];
			//cout<<"min"<<min;
			b[i]=0;
			cnt--;
			
				for(int j=i+1;j<n;j++)
				{
					if(b[j]==0) 
					continue;
					if(b[j]<min)
					{
						//cout<<"b[j]"<<b[j]<<' ';
						min=b[j];
						b[j]=0;
					}
				}
			
		}
	}
	int flag=1;
	for(i=0;i<n;i++)
	{
		if(b[i])
		flag=0;
	}
	if((!cnt&&flag==1)||cnt)
	{
		//cout<<t<<"true";
		return true;
	}
	//cout<<t<<"false";
		return false;
}

int main()
{
	int n,i,ans;
	cin>>n;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int min=a[0],p=1;
	c[0]=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]<min)
		{
			c[p++]=a[i];
			min=a[i];
		}
	}
	for(i=0;i<p-1;i++)
	cout<<c[i]<<' ';
	cout<<c[p-1];
	cout<<endl;
	int l=1,r=n;
	while(l<=r)
	{
		//cout<<"left"<<l<<' '<<"right"<<r<<endl;
		int mid=(l+r)/2;
		if(check(mid,n))
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	cout<<ans;
	return 0;
}
```



