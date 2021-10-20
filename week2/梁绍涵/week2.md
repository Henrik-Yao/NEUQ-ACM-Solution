# Week2 递归，分治，归并题解

## **7-1 汉诺塔问题**

### 题目：

给定一个由n个圆盘组成的塔，这些圆盘按照大小递减的方式套在第一根桩柱上。现要将整个塔移动到另一根桩柱上，每次只能移动一个圆盘，且较大的圆盘在移动过程中不能放置在较小的圆盘上面。

### 输入格式:

输入由四行： 第一行是圆盘数量n(1<=n<=10); 第二行到第四行分别是三根桩柱的名字(字符串)，n个盘子套在第一根桩柱上。

### 输出格式:

输出移动步骤，每行输出一步。

### 输入样例:

在这里给出一组输入。例如：

```in
2
a
b
c
结尾无空行
```

#### 输出样例:

在这里给出相应的输出。例如：

```out
a->b
a->c
b->c
结尾无空行
```

### 分析：

​		汉诺塔属于是经典问题了（虽然我还是想了一会，顺手翻了一下之前的代码qwq），可以用递归来写。对于这n个盘子，我们要做的第一步就是先让上面n-1个盘子移动到第二个柱子，然后把最下面的盘子移动到第三个柱子，最后在让第二个柱子上的n-1个盘子移动到第3个柱子上就可以了。

​		我们写一个递归函数 hnt（from,mid,to,x），其解释为x和盘子从from借助mid到达to。在函数中完成递归调用就可以了qwq。

### 代码：

```c++
#include<iostream>
using namespace std;
void hnt(string from,string mid,string to,int sum)
{
	if(sum==1)
	cout<<from<<"->"<<to<<endl;
	else
	{
		hnt(from,to,mid,sum-1);
		cout<<from<<"->"<<to<<endl;
		hnt(mid,from,to,sum-1);
	}
	 
}
int main()
{    
	int n;
	string a,b,c;
	cin>>n>>a>>b>>c;
	hnt(a,b,c,n);
}`
```

------

------

## **7-2 分而治之**

### 题目

分而治之，各个击破是兵家常用的策略之一。在战争中，我们希望首先攻下敌方的部分城市，使其剩余的城市变成孤立无援，然后再分头各个击破。为此参谋部提供了若干打击方案。本题就请你编写程序，判断每个方案的可行性。

### 输入格式：

输入在第一行给出两个正整数 N 和 M（均不超过10 000），分别为敌方城市个数（于是默认城市从 1 到 N 编号）和连接两城市的通路条数。随后 M 行，每行给出一条通路所连接的两个城市的编号，其间以一个空格分隔。在城市信息之后给出参谋部的系列方案，即一个正整数 K （≤ 100）和随后的 K 行方案，每行按以下格式给出：

```
Np v[1] v[2] ... v[Np]
```

其中 `Np` 是该方案中计划攻下的城市数量，后面的系列 `v[i]` 是计划攻下的城市编号。

### 输出格式：

对每一套方案，如果可行就输出`YES`，否则输出`NO`。

### 输入样例：

```in
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 10
2 4
5
4 10 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2
结尾无空行
```

### 输出样例：

```out
NO
YES
YES
NO
NO
结尾无空行
```

### 分析：

​		这道题一开始用的二位数组，发现直接炸了，最后决定用vector<int> Map[10010]。这道题的关键在于判断条件

```
if(map1[Map[i][j]]==1||map1[i]==1)
```

​		map1的作用是存下被摧毁的城市，如果map1[Map[i] [j]]=1或者map1[i]=1则说明i城不能够抵达Map[i] [j]城。

### 代码：

```C++
#include<bits/stdc++.h>
using namespace std;
vector<int> Map[10010];
int map1[10010];
int main()
{
 	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int ui,vi;
		cin>>ui>>vi;
		Map[ui].push_back(vi);
	}
	int t;
	cin>>t;
	while(t--)
	{
		int num;
		cin>>num;
		memset(map1,0,sizeof(map1));
		for(int i=1;i<=num;i++)
		{
			int s;
			cin>>s;
			map1[s]=1;
		}
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<Map[i].size();j++)
			{
				if(map1[Map[i][j]]==1||map1[i]==1) continue;
				else
				{
					cout<<"NO"<<endl;
					flag=0;
					break;
				}	
			}
			if(flag==0)
			break;
		}
		if(flag==1) cout<<"YES"<<endl;
	}
}
```

## **7-3 归并排序**

### 题目：

给定你一个长度为 n 的整数数列。

请你使用归并排序对这个数列按照从小到大进行排序。

并将排好序的数列按顺序输出。

### 输入格式:

输入共两行，第一行包含整数 n(1≤n≤100000)。

第二行包含 n 个整数（所有整数均在 1∼10^9 范围内），表示整个数列。

### 输出格式:

输出共一行，包含 n 个整数，表示排好序的数列。

### 输入样例:

```in
5
3 1 2 4 5
结尾无空行
```

### 输出样例:

```out
1 2 3 4 5 
结尾无空行
```

### 分析：

一道模板题

> **归并排序**（Merge Sort）是建立在[归并](https://baike.baidu.com/item/归并/253741)操作上的一种有效，稳定的[排序算法](https://baike.baidu.com/item/排序算法/5399605)，该算法是采用[分治法](https://baike.baidu.com/item/分治法/2407337)（Divide and Conquer）的一个非常典型的应用。将已有序的子序列[合并](https://baike.baidu.com/item/合并/5615281)，得到完全有序的[序列](https://baike.baidu.com/item/序列/1302588)；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为[二路归并](https://baike.baidu.com/item/二路归并/53201558)。    																																							----百度

​		一种比较稳定的排序算法（说得好，所以我选择sort）

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
int a[100010],temp[100010];
void mergesort(int l,int r)
{
	if(l>=r) return;
	int mid=(l+r)/2;
	mergesort(l,mid);
	mergesort(mid+1,r);
	int k=0;
	int left=l,right=mid+1;
	while(left<=mid&&right<=r)
	{
		if(a[left]<a[right]) temp[k++]=a[left++];
		else temp[k++]=a[right++];
	}
	while(left<=mid) temp[k++]=a[left++];
	while(right<=r) temp[k++]=a[right++];
	int x=0;
	for(int i=l;i<=r;i++)
	{
		a[i]=temp[x];
		x++;	
	}  
}
int main()
{
	int n;
	cin>>n; 
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mergesort(0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
```

