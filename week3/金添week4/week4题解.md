# week4题解

### 7-1素数

用埃式筛法即可，

通过一次循环，将质数的倍数全部标记，到最后未标记的数即为素数。

```C++
#include <bits/stdc++.h>
using namespace std;
int visit[100000]={1,1};//0，1不是素数
int shu[10000]; 
int main()
{
	int a,b;
	for(int i=2;i<=10000;i++)
	{
		if(!visit[i])
		{
			for(int k=i*i;k<=10000;k+=i)
			{
				visit[k]=1;
			}
		}
	}
	
	while(cin>>a>>b)
	{
		int con=0;
		for(int i=a;i<=b;i++)
		if(!visit[i])
		shu[++con]=i;
		
		for(int j=1;j<con;j++)
		cout<<shu[j]<<" ";
		cout<<shu[con]<<endl;
    }
	return 0;
}
```

### 7-2爬楼梯

经典的递归问题，对于第n层，可以从n-1踏上，也可以从n-2踏上 ，F（n）=F（n-1）+F（n-2）。

```c++
#include <bits/stdc++.h>
using namespace std;
long long ans(long long n)
{
	if(n==1)
	return 0;
	else if(n==2)
	return 1;
	else if(n==3)
	return 2;
	else
	return ans(n-1)+ans(n-2); 
}
int main()
{
	int n;
	long long m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		if(i==n)
		cout<<ans(m);
		else
		cout<<ans(m)<<endl;
	}
	return 0;
}
```

### 7-3统计素数

可用欧拉筛法，此题似乎不能用埃式筛法，输入大于10000000会炸，可以用欧拉筛减少标记次数，提高效率。

```C++
#include <iostream>
using namespace std;
bool visit[10000001]={1,1};//0,1不是素数 
int prime[7000000];
int main()
{
	int n;
	cin>>n;
	int num=0;//记录素数的个数 
	for(int i=2;i<=n;i++)//乘数 
	{
		if(!visit[i])
		prime[++num]=i;
		//关键点：当乘数是被乘数的倍数时，停止筛
		for(int j=1;j<=num;j++)//被乘数 
		{
			if((prime[j]*i)>n) break;
			int remp=prime[j]*i;
			visit[remp]=1;
			if(i%prime[j]==0)
			{	
				break;
			}
		} 
	}
	cout<<num<<endl;
	
	return 0;
} 
```

### 7-4快速幂

经典的分治问题，将在乘方过程中将数字变小，进行取余，从而达到效果。

```C++
#include <bits/stdc++.h>
using namespace std;
long long fastpower(long long a,long long b,long long c)
{
	long long ans=1;
	while(b)
	{
		ans%=c;
		if(b&1)
		ans=(ans*a)%c;
	    b/=2;
	    a=(a*a)%c; 
	}
	return ans;
}
int main()
{
	long long n,a,b,c;
	cin>>n;
	while(cin>>a>>b>>c)
	{
		cout<<fastpower(a,b,c)<<endl;
	}

	return 0;
}
```

