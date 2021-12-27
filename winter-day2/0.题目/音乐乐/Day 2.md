# Day 2

---

## 7-1 二叉树叶结点值和最大层

构建二叉树，如果一个数据后面连着两个0，则表明该数据为叶结点，求叶结点值和的过程相当于BFS，用数组保存每一层的和之后排序找到最大的和对应的层数即可。



## 7-4 罪犯帮派

考察并查集，每次输入a,b,用find函数递归查找是否连通

```
int find(int x)
{
	if(f[x]==x)
	return x;
	else
	return f[x]=find(f[x]);
}
```

如果不连通，就将a所在集纳入b所在集

```
x=find(a);
y=find(b);
if(x!=y) f[x]=y;
```

查找的时候只需判断输入的两个数是否在一个集内即可

```
cin>>x>>y;
if(find(x)!=find(y))
	cout<<"In different gangs."<<endl;
else
	cout<<"In the same gang."<<endl;
```



## 7-6 先序和中序构造二叉树

核心是分治思想。前序遍历的结果的第一个数据是对应树的根结点，在中序遍历结果里找到该点对应的位置，将该树分成左子树和右子树，再如法炮制，直到到叶结点时递归终止。

```
#include<bits/stdc++.h>
using namespace std;
int n;
int front[11],mid[11];
void fun(int ll,int lr,int rl,int rr)
{
	if(ll>lr)
	return;
	int pos;
	int t=front[ll];
	for(int i=rl;i<=rr;i++)
	{
		if(mid[i]==t)
		{
			pos=i;
			break;
		}
	}
	fun(ll+1,ll+pos-rl,rl,pos-1);
	fun(ll+pos-rl+1,lr,pos+1,rr);
	cout<<t<<' ';
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>front[i];
	for(int i=0;i<n;i++)
		cin>>mid[i];
	fun(0,n-1,0,n-1);
	return 0;
}
```



## 7-9 后序和中序构造二叉树

跟上题类似，后序遍历结果的最后一个数据为对应树的根结点，在中序遍历中找到根结点的位置，分出左子树和右子树，递归到叶结点终止。

```
#include<bits/stdc++.h>
using namespace std;
int n;
int mid[11],back[11];
void fun(int ll,int lr,int rl,int rr)
{
	if(ll>lr)
	return;
	cout<<back[lr]<<' ';
	int pos;
	int t=back[lr];
	for(int i=rr;i>=rl;i--)
	{
		if(mid[i]==t)
		{
			pos=i;
			break;
		}
	}
	fun(ll,pos+ll-rl-1,rl,pos-1);
	fun(pos+ll-rl,lr-1,pos+1,rr);
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>back[i];
	for(int i=0;i<n;i++)
		cin>>mid[i];
	fun(0,n-1,0,n-1);
	return 0;
}
```

