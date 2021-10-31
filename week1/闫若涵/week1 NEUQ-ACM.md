# week1 NEUQ-ACM

### 7-1 string

可通过判断模式串的长度，每个元素的值来判断模式串出现的次数

从字符串的第一个字符开始遍历 新定义一个新的字符串b并设置为空，若相等则把字符加到新定义的字符串上

代码如下:

```c++
#include<bits/stdc++.h>
using namespace std;
char s[50000];
string a;
int n,m;
int main()
{
  cin>>n;
  cin>>s+1;
   int t = strlen(s+1);
   for (int i=1;i<=n;i++)
   {
   	  int num=0;
   	  cin>>a;
   	  int len = a.length();
   	  for (int i=1;i<=t-len+1;i++)
   	  {
   	  	 string b;
   	  	 b.clear();
   	  	 for (int j=i;j<=i+len-1;j++) b+=s[j];
   	  	 if (a==b) ++num;
   	  }
   	  cout<<num;
	  if (i!=n) cout<<"\n";
   }
   return 0;
}
```

### 7-2 区间

最终区间是[1,i]和[i+1,n]

使用枚举断点寻找最优答案,预处理一个$pre_i,suf_i$来表示$[1,i$]中不同数的个数和$[i+1,n]$中不同数的个数即可，处理过程可以用桶来记录一个数是否出现过

代码如下：

```c++
#include<bits/stdc++.h>
const int N = 1e6 + 10;
using namespace std;
bool judge[N];
int n,r,a[N],pre[N],suf[N];
int main()
{
 cin>>n;
 for(int i=1;i<=n;i++)
 cin>>a[i];
 for(int j=1;j<=n;j++)
 {
  pre[j]= pre[j-1]+(!judge[a[j]]);
  judge[a[j]] = 1;
 }
 memset(judge,0,sizeof(judge));//全赋值为false 
 for(int k=n;k;k--)
 {
  suf[k]=suf[k+1]+(!judge[a[k]]);
  judge[a[k]]=1;
 }
 for(int i=1;i<n;i++) 
 r=max(r,pre[i]+suf[i+1]);
 cout<<r;
}
```

### 7-3 小步点

由题意可知以两个坐标为半径做圆，求两条线段的最短距离

(d,n-R)的点为最小

在坐标系中，会出现正负现象，因为在计算时要用绝对值计算

分为R<n和R>=n两种情况

代码如下:

```c++
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double R,d,n;
	double  s;
	cin>>R>>d>>n;
	if(d<0)	d=-d;
	if(n<0)	n=-n;
	if(R<n)
		s=2*sqrt(d*d+(n-R)*(n-R))-R;
	else 
		s=2*d-R;
		printf("%.2f",s);
		return 0;
}
```

### 7-3 分糖果

思路为递归思想

截至条件为n=1

否则判断是否为合数，若为合数，则对其因子在进行函数的递归调用，若满足条件则对其加1；

代码如下：

```c++
#include<iostream>
using namespace std;
int f(int n)
{
 if(n==1)		
 return 1;
 int t=1;
 for(int i=1;i<=n/2;i++)
 {
 	if(n%i==0)
	 t+=f(i);
 }
 return t;
}
int main()
{   int n;
  	cin>>n;
  	int a=f(n);
  	cout<<a;
}
```

### 7-5 找眼镜

分为圈内和圈外两种情况即里左=外右

是一个循环数列，每当到达n值时会产生两种情况：数组下标从0变到n-1或为从0变到1

代码如下：

```c++
#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	string ch[100];
	int a[n],b[m],c[m];
	
	for(int i=0;i<n;i++)
		cin>>a[i]>>ch[i];
	
	for(int j=0;j<m;j++)
		cin>>b[j]>>c[j];

	int t=0;
	int flag=a[0];
	for(int k=0;k<m;k++)
	{
		if(((b[k]==0)&&(a[t]==0))||((b[k]==1)&&(a[t]==1)))
		{
			t=t-c[k];
			while(true){
				if(t>=0)	break;
				t=t+n;
			}
		}
		else 
		{
			t=t+c[k];
			while(true){
				if(t<n)	break;
				t=t-n;
			}
		}
	}
	cout<<ch[t];
}

```



### 7-6 恰早饭

从诸多早饭中进行运算，按t与T的关系存储快乐值，用sort函数进行排序输出最大的快乐值

代码如下：

```c++
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,T;
	cin>>n>>T;
	int max[n];
	int m=n; 
	for(int i=0;i<m;i++)
	{
		int v,t;
		cin>>v>>t;
		if(t<=T)  max[i]=v;
		else      max[i]=v-(t-T);
	}
	sort(max,max+m);
	cout<<max[m-1];
}

```



