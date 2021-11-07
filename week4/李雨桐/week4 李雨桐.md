# week 4 线性筛和组合数学

### 7-1 素数

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

### 代码：

暴力筛即可通过

```c++
#include <bits/stdc++.h>
using namespace std;

int prime(int a) //0表示是素数，1表示不是素数
{
    if(a==2)
        return 0;
    else
    {
        for(int i=2;i<=sqrt(a);i++)
        {
            if(a%i==0)
            return 1;
        }
        return 0;
    }
}

int main()
{
    int a,b;
    while(cin>>a,cin>>b)
    {
        int cnt=0;
        for(int i=a;i<=b;i++)
        {
            if(prime(i)==0 && cnt==0)
                {
                    cout<<i;
                    cnt=1;
                }
            else if(prime(i)==0 && cnt!=0)
                cout<<' '<<i;

        }
        cout<<endl;
    }

    return 0;
}

```

---------------------------------------------

### 7-2 炒鸡楼梯

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
2
结尾无空行
```

### 代码：

关键是找到规律，可发现是斐波那契数列

```
#include <bits/stdc++.h>

using namespace std;


int main()
{
    long long f[55];
    int n,t;

    f[1]=0;
    f[2]=1;
    f[3]=2;
    for(int i=4;i<50;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }

    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<f[n]<<endl;
    }

    return 0;
}

```

------------------------------------

### 7-3 求素数个数

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

### 代码：

本题用埃氏筛建立了一个prime 函数

```c++
#include <bits/stdc++.h>

using namespace std;


bool vis[10000005];
int ans=0;

void prime(int n) //0表示是素数，1表示不是素数
{
    for(int i=2;i<=n;i++)
	    vis[i]=0;

    vis[0]=1;
    vis[1]=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(!vis[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                vis[j]=1;
            }
        }
    }

}

int main()
{
    int n;
    cin>>n;

    prime(n);
    for(int k=2;k<=n;k++)
    {
        if(vis[k]==0)
            ans++;
    }
    cout<<ans<<endl;

    return 0;
}

```

--------------------------------

### 7-4 幂次取余

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

### 代码：

```c++
#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll mod(ll a,ll b,ll c )
{
    ll ans =1;

    if(b==0)
        ans = 1%c;

    while(b)
    {
        if(b%2==1)
            ans = a*ans%c;
        b/=2;
        a = (a*a)%c;
    }

    return ans;
}

int main()
{
    ll t,a,b,c;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        cout<<mod(a,b,c)<<endl;

    }

    return 0;
}

```

