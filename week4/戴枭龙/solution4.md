# 7-1 素数

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
3 5 7 11 13结尾无空行
```

### 思路：

简单素数，格式有点骚。

```c++
#include <bits/stdc++.h>
using namespace std;
int flag;
int prime;

int main() {
	int a, b;
	while (cin >> a >> b) {
		flag=1;
		for (int i = a; i <= b; i++) {
			int j, prime = 1;
			for (j = 2; j * j <= i; j++)
				if (i % j == 0)
					prime = 0;
			if (flag) {
				if (prime) {
					cout << i ;
					flag = 0;
				}
			} else if (prime) {
				cout << " " << i ;
			}
		}
		cout << endl;
	}

	return 0;
}

```

# 7-2 炒鸡楼梯

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

### 思路：

最后一步可以上一级或者两级推出公式，!!!!输入1 的时候输出0真的骚。

```c++
#include<iostream>
using namespace std;
int a[60];
int main()
{
	a[1]=0;a[2]=1;a[3]=2;
	for(int i=4;i<=50;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	int t,q;
	cin>>t;
	while(t--)
	{
		cin>>q;
		cout<<a[q];
		if(t) cout<<endl;
	}
 }

```

# 7-3 求素数个数

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

### 思路：

暴力解就超时了，欧拉筛。

一个数为素数的时候，它的倍数肯定不是素数。所以我们可以从2开始通过乘积筛掉所有的合数。
将所有合数标记，保证不被重复筛除，时间复杂度为O（n）。

```c++
#include<bits/stdc++.h>
using namespace std; 
   int prime[10000001]; 
   int vis[10000001];
int main()
{
    int n, cnt = 0;

    cin>>n;
    for(int i = 2; i <= n; i++)
    {
        if(!vis[i])
        prime[cnt++] = i;
        for(int j = 0; j<cnt && i*prime[j]<=n; j++)
        {
            vis[i*prime[j]] = true;

            if(i % prime[j] == 0) break;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

```

# 7-4 幂次取余

给定三个正整数A，B和C，求*A**B* mod C的结果，其中mod表示求余数。

### 输入格式:

首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据输入三个正整数A，B，C（A，B，C≤1000000）。

### 输出格式:

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

### 思路：

由(a \* b) % p = (a % p \* b % p) % p 。

以b为偶数来举例。

a^b%c = ((a^2)^b/2)%c;

在这里我们假设b/2还是偶数，那么

我们就以b为偶数来举例。

a^b%c = ((a^2)^b/2)%c;

在这里我们假设b/2还是偶数，那么

((a^2)^b/2)%c = (((a^2)^2)^(b/2)/2)%c

```c++
#include <bits/stdc++.h>
using namespace std;

long long fastPower(long long a, long long b,long long c) {
	long long result = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			result = result * a % c;
		}
		b = b / 2;
		a = (a * a) %c;
	}
	return result;
}


int main() {
	int t, a, b, c;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		cout << fastPower(a, b, c) << endl;
	}
	return 0;
}
```

