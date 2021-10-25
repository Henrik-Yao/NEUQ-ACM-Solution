# WEEK2 周报
## 7-1 汉诺塔问题
### 题面

给定一个由n个圆盘组成的塔，这些圆盘按照大小递减的方式套在第一根桩柱上。现要将整个塔移动到另一根桩柱上，每次只能移动一个圆盘，且较大的圆盘在移动过程中不能放置在较小的圆盘上面。

**输入格式:**
输入由四行： 第一行是圆盘数量n(1<=n<=10); 第二行到第四行分别是三根桩柱的名字(字符串)，n个盘子套在第一根桩柱上。

**输出格式:**
输出移动步骤，每行输出一步。

**输入样例:**
在这里给出一组输入。例如：
```
2
a
b
c
结尾无空行
```
**输出样例:**
在这里给出相应的输出。例如：
```
a->b
a->c
b->c
结尾无空行
```
### 思路
把挪n个圆盘的大问题拆解成挪n-1个圆盘和挪第n个圆盘的小问题，要注意n==1时的特殊情况

### 代码
```c++
#include<iostream>
using namespace std;
void hanoi(string now,string target,string temp,int time)
{
	if(time==2)
	{
		cout<<now<<"->"<<temp<<endl;
		cout<<now<<"->"<<target<<endl;
		cout<<temp<<"->"<<target<<endl;
	}
	else if(time==1)
	{
		cout<<now<<"->"<<target<<endl;
	}
	else
	{
		hanoi(now,temp,target,--time);
		cout<<now<<"->"<<target<<endl;
		hanoi(temp,target,now,time);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	string a,b,c;
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	hanoi(a,c,b,n);
	return 0;
}
```

## 7-2 分而治之
### 题面

分而治之，各个击破是兵家常用的策略之一。在战争中，我们希望首先攻下敌方的部分城市，使其剩余的城市变成孤立无援，然后再分头各个击破。为此参谋部提供了若干打击方案。本题就请你编写程序，判断每个方案的可行性。

**输入格式:**
输入在第一行给出两个正整数 N 和 M（均不超过10 000），分别为敌方城市个数（于是默认城市从 1 到 N 编号）和连接两城市的通路条数。随后 M 行，每行给出一条通路所连接的两个城市的编号，其间以一个空格分隔。在城市信息之后给出参谋部的系列方案，即一个正整数 K （≤ 100）和随后的 K 行方案，每行按以下格式给出：
`Np v[1] v[2] ... v[Np]`
其中`Np`是该方案中计划攻下的城市数量，后面的系列`v[i]`是计划攻下的城市编号。

**输出格式:**
对每一套方案，如果可行就输出`YES`，否则输出`NO`。

**输入样例:**
```
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
**输出样例:**
```
NO
YES
YES
NO
NO
结尾无空行
```

### 思路
把所有的连接存在multimap(`Connect`)里，把要攻下的城市存在数组(`attack[]`)里，然后用`Connect.erase(attack[i])`把键城市被攻下的连接清除，再开另一个multimap(`T`)把`Connect`里剩下的元素键值翻转存进去，然后同样的操作把`T`里键城市被攻下的连接清除。
如果`T`最后是空的说明全部被攻下了。

### 代码
```c++
#include<iostream>
#include<map>
using namespace std;
typedef pair<int,int>apair;
int main()
{
	int n,m,k;
	scanf("%d %d",&n,&m);
	multimap<int,int>Connect;
	int f,l;
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&f,&l);
		Connect.insert(apair(f,l));
	}
	scanf("%d",&k);
	while(k)
	{
		k--;
		multimap<int,int>C(Connect.begin(),Connect.end());
		int cityNum,attackCity;
		scanf("%d",&cityNum);
		int nn=cityNum,j=0;
		int attack[nn];
		while(cityNum)
		{
			scanf("%d",&attack[j]);
			C.erase(attack[j]);
			j++;
			cityNum--;
		}
		if(C.empty()) printf("YES\n");
		else
		{
			multimap<int,int>T;
			for(auto ita=C.begin();ita!=C.end();ita++)
			{
				T.insert(apair(ita->second,ita->first));
			}
			for(int i=0;i<nn;i++)
			{
				T.erase(attack[i]);
			}
			if(T.empty()) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
```

## 7-3 归并排序
### 题面

知识点：归并排序
给定你一个长度为 n 的整数数列,请你使用归并排序对这个数列按照从小到大进行排序,并将排好序的数列按顺序输出。

**输入格式:**
输入共两行，第一行包含整数 n(1≤n≤100000)。第二行包含 n 个整数（所有整数均在 1∼10^9 范围内），表示整个数列。

**输出格式:**
输出共一行，包含 n 个整数，表示排好序的数列。

**输入样例:**
```
5
3 1 2 4 5
结尾无空行
```
**输出样例:**
```
1 2 3 4 5 
结尾无空行
```

### 思路
~~先分开再合上~~

### 代码
```c++
#include<iostream>
using namespace std;
void mergeSort(int a[],int begin,int end);
void merge(int a[],int begin,int mid,int end);
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
void mergeSort(int a[],int begin,int end)
{
	if(end-begin==1)
	{
		if(a[begin]>a[end])
		{
			swap(a[begin],a[end]);
		}
	}
	else if(begin==end)
	{
		return;
	}
	else
	{
		mergeSort(a,begin,(begin+end)/2);
		mergeSort(a,(end+begin)/2+1,end);
		merge(a,begin,(begin+end)/2,end);
	}
}
void merge(int a[],int begin,int mid,int end)
{
    int len=end-begin+1;
    int temp[len];
    int i=0;
    int lBegin=begin;
    int rBegin=mid+1;
    while(lBegin<=mid && rBegin<=end)
    {
    	if(a[lBegin]<=a[rBegin])
    	{
    		temp[i]=a[lBegin];
    		lBegin++;
		}
		else
		{
			temp[i]=a[rBegin];
			rBegin++;
		}
		i++;
	}
    while(lBegin<=mid)
    {
    	temp[i]=a[lBegin];
    	lBegin++;
    	i++;
	}
    while(rBegin<=end)
	{
    	temp[i]=a[rBegin];
    	rBegin++;
    	i++;
	}
    for(i=0;i<len;++i)
    {
    	a[begin+i]=temp[i];
	}
}
```
