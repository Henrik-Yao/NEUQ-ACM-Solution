## Week8

### 7-1 最少失约

某天，诺诺有许多活动需要参加。但由于活动太多，诺诺无法参加全部活动。请帮诺诺安排，以便尽可能多地参加活动，减少失约的次数。假设：在某一活动结束的瞬间就可以立即参加另一个活动。

### 输入格式:

首先输入一个整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据首先输入一个正整数n，代表当天需要参加的活动总数，接着输入n行，每行包含两个整数i和j（0≤i<j<24），分别代表一个活动的起止时间。

### 输出格式:

对于每组测试，在一行上输出最少的失约总数。

### 输入样例:

```in
1
5
1 4
3 5
3 8
5 9
12 14
```

### 输出样例:

```out
2
```

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;

struct activ{
    int a;
    int b;
}p[110];

bool comp(activ s1, activ s2)
{
    return s1.b<s2.b;
}

int main()
{
    int T,n;
    cin>>T;
    for(int m=0;m<T;m++)
        {
        cin >> n;
        for(int j=0;j<n;j++)
        {
            cin>>p[j].a>>p[j].b;
        }

        sort(p,p+n,comp);
        int j=0,num=1;

        for(int i=1;i<n;i++)
        {
            if(p[i].a>=p[j].b)
            {
                j=i;
                num++;
            }
        }
        cout<<n-num<<endl;
    }
    return 0;
}

```

---------------------------------------

### 7-2 跳一跳

**Drizzle** 面前有一条由一堆`非负整数`组成的道路，从第一个数字起步，每次他都能跳出不大于当前数字的距离，每个数字之间的距离为1，那么他最少需要跳多少次才能到达终点？

### 要求:

输入：第一行输入道路中数字的个数`n`也就是道路的长度，第二行输入这n个数字

输出：输出一个数字，表示最少跳跃次数

### 示例:

输入:

```in
5
2 3 1 1 4
结尾无空行
```

输出:

```out
2
结尾无空行
```

解释: 跳到最后一个位置的最小跳跃数是 2。从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

### 范围:

对于 20% 的数据：n≤100
对于 100% 的数据：n≤1000000
所有整数元素在`int`范围内

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int sear(int n, int m);
int bian(int n,int m);

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int k=0,res=1;
	while(k+a[k] < n-1)
	{
        int p=a[k];
		int m = sear(k,a[k]+k);
		k = bian(m,p+k);
		res ++;
	}
	cout<<res;
	return 0;
}

int sear(int n, int m)
{
	int ans = n+1;
	for(int i=n; i<=m;i++)
	{
		if(a[n]<a[i])
        {
			a[n]=a[i];
			ans=i;
		}
	}
	return ans;
}
int bian(int n,int m)
{
	int ans=n;
	for(int i=ans;i<=m;i++)
    {
		if(a[n] < a[i]+i-n)
			n=i;
	}
	return n;
}

```

