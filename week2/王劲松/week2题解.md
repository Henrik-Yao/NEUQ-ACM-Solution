7-1 汉诺塔问题

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
c结尾无空行
```

### 输出样例:

在这里给出相应的输出。例如：

```out
a->b
a->c
b->c
```

------

思路：有n个圆盘，先把n-1个移动到柱2（辅助柱），然后把最后一个移到柱3（目的柱），再把n-1个移到柱3，在第一步中，把辅助柱看成目的柱，

即f(n,a,b,c)=f(n-1,a,c,b)+a->c+f(n-1,b,a,c);

```
#include<bits/stdc++.h>
using namespace std;
void f(int n,string s1,string s2,string s3);
int main(){
	int n;
	cin>>n;
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	f(n,s1,s2,s3);
	return 0;
}
void f(int n,string s1,string s2,string s3){
	if(n==1){
		cout<<s1<<'-'<<'>'<<s3<<endl;
	}
	else if(n!=1){
	f(n-1,s1,s3,s2);
	cout<<s1<<'-'<<'>'<<s3<<endl;
	f(n-1,s2,s1,s3);
	}
}
```

------

7-2 分而治之

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
7 9 8 7 6 5 4 2结尾无空行
```

### 输出样例：

```out
NO
YES
YES
NO
NO
```

------

思路：通过一个列数为2的二维数组lj记录城市的通道关系，再用一个数组p记录城市是否有通路，最后判断p[lj]是否同时有关系。

```
#include<stdio.h>
int main(){
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	int lj[m][2],p[n+1];
	for(i=0;i<=n;i++){
		p[i]=0;
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&lj[i][0],&lj[i][1]);
	}
	int k;
	
	scanf("%d",&k);
	for(i=0;i<k;i++){
		int nb=0;
		for(j=0;j<m;j++){
			p[lj[j][0]]=1;
			p[lj[j][1]]=1;
		}
		int ml;
		scanf("%d",&ml);
		for(j=0;j<ml;j++){
			int t;
			scanf("%d",&t);
			p[t]=0;
		}
		//for(j=1;j<=n;j++){
		//	printf("%d",p[j]);
		//}
		for(j=0;j<m;j++){
			if(p[lj[j][0]]==1&&p[lj[j][1]]==1){
				nb=1;
				break;
			}
		}
		if(nb==0)printf("YES\n");
		else printf("NO\n");
		
	}
	return 0;
}
```

------

7-3 归并排序

知识点：归并排序

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
3 1 2 4 5结尾无空行
```

### 输出样例:

```out
1 2 3 4 5 
```

------

思路：归并排序（MERGE-SORT）是建立在归并操作上的一种有效的排序算法,该算法是采用[分治法](https://baike.sogou.com/lemma/ShowInnerLink.htm?lemmaId=7824380&ss_c=ssc.citiao.link)（Divide and Conquer）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为二路归并。

```
#include<bits/stdc++.h>
using namespace std;
void mergesort(int a[],int l,int r);
void merge(int a[],int mid,int l,int r);
int main(){
	int m,i;
	cin>>m;
    int a[m];
    for(i=0;i<m;i++){
        cin>>a[i];
    }
	mergesort(a,1,m);
	for(i=0;i<m;i++){
		cout<<a[i]<<' ';
        
	}
	return 0;
}
void mergesort(int a[],int l,int r){
	if(l>=r)return;
	int mid =l+(r-l)/2;
	mergesort(a,l,mid);
	mergesort(a,mid+1,r);
	merge(a,mid,l,r);
	//return;
}
void merge(int a[],int mid,int l,int r){
	int i=l,j=mid+1,k=0;
	int *p=new int[r-l+1];
	while(i<=mid&&j<=r){
		if(a[i-1]<=a[j-1]){
			p[k++]=a[i-1];
			i++;
		}
		else p[k++]=a[j-1],j++;
	}
	while(i<=mid){
		p[k++]=a[i-1],i++;
	}
	while(j<=r){
		p[k++]=a[j-1],j++;
	}
	for(i=l,k=0;i<=r;i++,k++){
		a[i-1]=p[k];
	}
	delete []p;
}
```

