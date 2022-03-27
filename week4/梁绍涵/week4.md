7-1 素数

编写一个程序，求出【a,b】范围内的素数。

### 输入格式:

输入数据有多组，每组占一行,输入两个数a,b。(整型范围内)

### 输出格式:

输出【a,b】区间内的素数，空格隔开。（2<=a,b<=10000）

### 输入样例:

在这里给出一组输入。例如：

```in
5 10
3 15结尾无空行
```

### 输出样例:

在这里给出相应的输出。例如：

```out
5 7
3 5 7 11 13
结尾无空行
```

### 思路：

对于多组输入，不能多次寻找，要用数组将每次的答案保存下来。对于大数据，用埃氏筛找素数。

埃氏筛远离：对于一个素数，他的倍数一定不是素数，因此将这个数的所有倍数全部打上标记。

算法复杂度nloglogn

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
int vis[100000],is_prime[100000];
bool prime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		return 0;
	}
	return 1;
}
int main()
{
	int a,b;
	memset(is_prime,-1,sizeof(is_prime));
	is_prime[1]=0;
	is_prime[2]=1;
	while(cin>>a>>b)
	{
		for(int i=3;i<=b;i++)
		{
			if(!prime(i))
			{
				for(int j=i+i;j<=b;j+=i)
				{
					is_prime[j]=0;
				}
			}
			else
			is_prime[i]=1;
		}
		int flag=1;
		for(int i=a;i<=b;i++)
		{
			if(is_prime[i]==1&&flag==1)
			{
				cout<<i;
				flag=0;
				continue;
			}
			if(is_prime[i]==1&&flag==0)
			cout<<" "<<i;
		}
		
		cout<<endl;
	}
}
```

7-2 炒鸡楼梯

你知道吗？有一种编程题需要自己推导公式，得出公式一下子就能解决问题。

具体步骤就是自己先按顺序推算几个比较小的情况，看看这几个之间有没有规律，找到规律你就能解决问题了。试着解决下面这个问题吧。

```
有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
```

### 输入格式:

输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，每行包含一个整数M（1<=M<=40）,表示楼梯的级数。

### 输出格式:

对于每个测试实例，请输出不同走法的数量

### 输入样例:

```in
2
2
3结尾无空行
```

### 输出样例:

```out
1
2结尾无空行
```

### 分析：

斐波那契数列，注意第一种情况是0

### 代码：

```C++
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a[50];
	a[1]=0;a[2]=1;a[3]=2;
	for(int i=4;i<50;i++)
	{
		a[i]=a[i-2]+a[i-1];
	}	
	int t;
	cin>>t;
	while(t--)
	{
		int num;
		cin>>num;
		cout<<a[num]<<endl;
	}
} 
```

7-3 求素数个数

求素数的个数。本题要求编写一个程序，求1~n的素数个数。 要求至少给出两种解法，对于相同的n，给出这两种解法的结果，通过相关数据进行测试，目的是通过对比同一问题不同解法的绝对执行时间体会如何设计“好”的算法。

### 输入格式:

输入在一行中给出1个整数n(<= 10 000 000)。

### 输出格式:

对每一组输入，在一行中输出1~n的素数个数。

### 输入样例1:

```in
5
结尾无空行
```

### 输出样例1:

```out
3
结尾无空行
```

### 输入样例2:

```in
14
结尾无空行
```

### 输出样例2:

```out
6
结尾无空行
```

### 分析：

还是埃氏筛，不过这次要求更严格了（指200ms）

第二次循环可以从i*i开始循环，时间从200->170

vis数组从int改成bool，时间从200->78

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;
int vis[10000001];
int main()
{
	int b;
	long long ans=0;
	cin>>b;
	for(int i=2;i<=b;i++)
	{
		if(!vis[i])
		{
			ans++;
			for(int j=i;j<=b;j+=i)
			vis[j]=1;
		}		
	}
	cout<<ans;
}

```

7-4 幂次取余

给定三个正整数A，B和C，求*A**B* mod C的结果，其中mod表示求余数。

### 输入格式:

首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据输入三个正整数A，B，C（A，B，C≤1000000）。

### 输出格式:

```

```

对于每组测试，输出计算后的结果，每组测试的输出占一行。

### 输入样例:

```in
2
3 3 5
4 4 6
```

### 输出样例:

```out
2
4
```

### 分析：

一道板子题（反正就是这么算的qwq）

### 代码：

```C++
#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,p,ans=1;
int qm(int x,int y,int z)
{
	int ans=1;
	x=x%z;
	if(y==0)
	{
		ans=1%z;
	}
	while(y>0)
	{
		if(y%2==1)
			ans=(ans*x)%z;
		y=y/2;
		x=(x*x)%z;
	}
	return ans;
}
signed main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b>>p;
		if(t==i)
		cout<<qm(a,b,p);
		else
		cout<<qm(a,b,p)<<endl; 
	}

}	
```

