# **寒假集训—day5（查找）**

## **7-1**

排序，遍历，记录，没啥好说的



## **7-2**

大模拟

**最初的想法**

​	用结构体记录下字典，然后让字典以使用频率降序进行排序，在查找时遍历字典，符合就输出。

​	然鹅，n ≤ 10000, m ≤ 20000，所以该算法复杂度O(mn)在数据不水时会超时，但抱着~~pta99.9%数据都很水~~的想法，我交了上去，果然，运行超时。

**优化**

​	基本思路没毛病，尝试优化。

​	m维优化不了，那就只能**在查找时的n上优化**：

​		**查询**

​		1.让字典结构体以单词ACSII码升序排序

​		2.在查找时用二分寻找在字典中第一个ASCII码大于等于查询单词的位置，然后从该位置开始遍历字典

​		3.直到遍历到字典的单词ASCII码不在以查询单词为前缀

​		4.遍历过程中满足条件的单词就输出

​	但是这样就**不能满足使用频率最大**的先输出：

​		比如 ：

​				要查找 the

​			     数据中有 100 thea   和    50 theb

​				如果按照字典序的话，先输出的会是theb，但thea的使用频率大，要先输出

**怎么办，~~我也不知道~~，**

​	想了好久终于想到了！！！

​	用**大根堆（以使用频率为比较元素）**把 **字典中第一个ASCII码大于等于查询单词的位置** 到 **上边查询的结束位置**之间的元素全部加入大根堆

​	输出时输出k个堆顶元素即可



**AC代码**

~~~cpp
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
ll n,m,k;
struct node//node类型存储字典
{
	ll num;
	ll asc;
	string s;
}e[10005];
struct cmpp//定义比较结构体，使大根堆可以比较node型数据
{
	bool operator() (node a, node b) 
    {
    	if(a.num<b.num)return true;//频率为第一关键字
    	else if(a.num>b.num)return false;
    	else
    	{
    		return a.s>b.s;//ASCII码为第二关键字
		}
    }
};
ll asc[10005];
map<string,ll>q;//用于记录某单词的最大使用次数

map<string,ll>qq;//用于在查询时记录某单词是否已经加入大根堆

bool cmp(node a,node b)//对字典进行排序
{
	if(a.s<b.s)return true;//ASCII码为第一关键字
	else if(a.s>b.s)return false;
	else
	{
		return a.num>b.num;//使用频率为第二关键字
	}
}

int search(string x,node e[])//找到字典中第一个大于等于x的字符 
{
	int l=1,r=n;
	int ans=n+1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(e[mid].s>=x)
		{
			ans=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}

int main()
{
	cin>>n>>m>>k;
	for(ll i=1;i<=n;i++)
	{
		ll a;
		cin>>a;
		cin>>e[i].s;
		if(a>q[e[i].s])
		{
			q[e[i].s]=a;
		}
		e[i].num=q[e[i].s];
	}
    
	sort(e+1,e+1+n,cmp);//以ASCII码顺序排序 
    
	while(m--)
	{
		priority_queue< node ,vector<node>, cmpp >w;//大根堆，加上 vector<node>,cmpp是为了实现将使用频率最大，ASCII码最小的单词排在最上边
		qq.clear();
		ll time=0;//记录输出的单词数
		string x;//要查询的前缀
		cin>>x;
		int be=search(x,e);//二分查位置
		for(ll i=be;i<=n;i++)//将符合前缀的字符串加入大根堆
		{
			if(strstr(e[i].s.c_str(),x.c_str())!=(e[i].s.c_str()))break;//判断x是否是前缀，不是的话直接结束
			if(!qq[e[i].s])//没加过
			{
				w.push(e[i]);//加入
				qq[e[i].s]=1;
			}
		}
		while(!w.empty())
		{
			node a=w.top();
			w.pop();
			if(strstr(a.s.c_str(),x.c_str())==(a.s.c_str())&&a.s.length()!=x.length())//x是前缀并且x不是原单词
			{
				cout<<a.s<<endl;
				time++;
			}
			if(time==k)break;
		}
		if(!time)
		{
			cout<<"no suggestion"<<endl;
		}
		if(m)cout<<endl;
	}
	return 0;
}

~~~



## **7-3**

emmm，排序，计算



## **7-4**

说实话，我一直不知道二分的边界和答案应该怎样处理，基本都是乱打然后蒙对，直到某天晚上18级竞赛队长的讲解，让我醍醐灌顶

其实二分只要理解好以下5个模板即可

首先是**基本模板：**

~~~cpp
int search(int x)
{
	int ans=0;
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(条件)
		{
			ans=mid;//该句位置根据具体情况变
			l=mid+1;
		}
		else
		{
			//上边注释句的另一个位置
			r=mid-1;
		}
	}
	return ans;
}
~~~

**找第一个大于x的值**

~~~cpp
int search(int x)
{
	int ans=0;
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]>x)
		{
			ans=mid;//因为a[mid]>x,所以mid满足大于x的要求，那该句就放在这里
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}
~~~

**找第一个小于x的值**

~~~cpp
int search(int x)
{
	int ans=0;
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]>=x)
		{
			l=mid+1;
		}
		else
		{
			ans=mid;//该分支条件相当于a[mid]<x,因为a[mid]<x,所以mid满足小于x的要求，那该句就放在这里
			r=mid-1;
		}
	}
	return ans;
}
~~~

**找第一个大于等于x的值**

~~~cpp
int search(int x)
{
	int ans=0;
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]>=x)
		{
            ans=mid;//因为a[mid]>=x,所以mid满足大于等于x的要求，那该句就放在这里
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return ans;
}
~~~

**找第一个小于等于x的值**

~~~cpp
int search(int x)
{
	int ans=0;
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]>x)
		{
			l=mid+1;
		}
		else
		{
            ans=mid;//该分支条件相当于a[mid]<=x,因为a[mid]>=x,所以mid满足大于等于x的要求，那该句就放在这里
			r=mid-1;
		}
	}
	return ans;
}
~~~



### 二分总结

​	**在塌陷时，哪个分支满足求解的条件，ans=mid就放在那个分支里。**



## **7-5**

大模拟，真磨时间，~~我实在是de不动了，就用了别人的代码，欸嘿~~

**注意：**

1. “五代之内” 指的是四代（自己 -> 爸爸 -> 爸爸的爸爸 -> 爸爸的爸爸的爸爸）
2. 查询并没有保证两个人是同辈。
3. 共同祖先（有的话）不能是任何一方的五代之内，比如一个是 8 代，另一个是 3 代，这就是不行的。
4. 题目可能会问你，某人能不能和他的祖先结婚。



## **7-6**

二分上边已经讲的很清楚了



## **7-7**

**二分答案**

不难，但是，虽然写的是：

​		作者			USACO 2005 Feb. Gold

​		单位			西安工业大学

但是我一眼就看出来的，这熟悉的农夫和牛，是Farmer John 2！！！！！

久违了，FJ2yyds

