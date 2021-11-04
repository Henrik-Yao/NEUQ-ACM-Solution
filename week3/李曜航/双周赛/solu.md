## 7-1

没什么好说的，从前往后扫状态方程

add[i]=max(add[i-1]+a[i],a[i]);

## 7-2

上周作业

## 7-3 *****

汗罗塔III

分解子问题：

n个移动到III，则有：

​	n-1个移动到III

​	第n移动到II

​	n-1移动到I

​	第n移动到III

​	n-1移动到III

这样写出来就是：

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll cnt = 0;
void luohan(int num)
{
    if(num==1) {cnt+=2;return;}
    luohan(num-1);
    cnt++;//第n移动到II
    luohan(num-1);//n-1移动到I
    cnt++;//第n移动到III
    luohan(num-1);//n-1移动到III
}
int main()
{
    while(cin>>n)
    {
        luohan(n);
        cout<<cnt<<endl;
        cnt = 0;
    }
}
```

但是会超时，所以要找到递推式

a(n) = a(n-1) + 1 + a(n-1) + 1 + a(n-1) = 3 * a(n-1) + 2

所以就可以打表了...

```cpp
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
int a[50];
int main()
{
    a[1] = 2;
    for (int i = 2; i <= 35; i++)
    {
        a[i] = 3 * a[i - 1] + 2; //递推式
    }
    int n;
    while (cin >> n)
    {
        cout << a[n] << endl;
    }
}
```

## 7-4

一眼看出来需要推公式

手推了半天没推出来 哎

[参考的博客](https://blog.csdn.net/u011721440/article/details/37994473?utm_source=tuicool&utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_title~default-4.no_search_link&spm=1001.2101.3001.4242.3)

直接copy（bushi）

分成了两种情况，如果是借助两个杆取搬运x个，再借助一个杆搬到n-x个，

（1）将x(1<=x<=n)个盘从a柱依靠b,d柱移到c柱，这个过程需要的步数为F[x];

（2）将a柱上剩下的n-x个盘依靠b柱移到d柱（注：此时不能够依靠c柱，因为c柱上的所有盘都比a柱上的盘小）这时移动方式相当于是一个经典汉诺塔，即这个过程需要的步数为2^(n-x)-1;

（3）将c柱上的x个盘依靠a,b柱移到d柱上，这个过程需要的步数为F[x];

总的步数F[n]=F[x]+2^ (n-x)-1+F[x]=2*F[x]+2^(n-x)-1



另外要注意一个点，ll不能用stl的min函数/max函数

## 7-5

相当于归并的merge操作，也可以直接sort

## 7-6

！！！！！！！！！！！！！

这就是我考试心态爆炸的题！！！！！！！！！！！！！！！！！！！

之后debug了很久都不知道问题在哪儿！！！！！！！！！！！！！！！！！

然后我现在知道了。。。。。。。。。。。。。。。。。。。。。。。

当时：一个这玩意儿，多简单；

WA

？？？

然后开始debug，关键是没有bug

然后我随手输了一个有重复字母的数据，发现会输出很多重复的。

我：找到bug了

然后开始想办法删重复的排列

然后 就没有然后了 完全炸了



现在，我血的教训告诉大家

平时全局变量用惯了，然后某一次写了一个非全局

请一定要初始化谢谢。

**一定要初始化谢谢！！！！！！！！**

关键是电脑上又看不出来，鬼知道哪里给你乱来初始值。。。。。



吐槽结束

## 7-7 *

开始做这个题的时候是在蚌埠住了，还剩不到五分

快速打了一个n^2

```cpp
#include <bits/stdc++.h>
using namespace std;
int read()
{
    char c = getchar(); int f = 1, x = 0;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=c-'0'+x*10;c=getchar();}
    return f*x;
}
const int maxN = 1000010;
long long rev[maxN];
long long a[maxN];
long long acc[maxN];
long long cnt;
int main()
{
	int n = read();
	for(int i=1;i<=n;i++)
	{
		a[i] = read();
		for(int j=i;j>=1;j--)
		{
			if(a[j]<=a[i]) acc[i]++;
		}
		cnt += i-acc[i];
	}
	cout<<cnt;
}
```

很明显，超时了。。。

考完ztl大佬给我说树状数组，现在搞懂了

但是我们学的是归并，然后去luogu上看到有

。。。。

最恐怖的是，我看到了luogu上有一个 历史分数100

心态崩了

嗯，归并的时候可以统计逆序的个数，O(log~2~N)

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N = 500005;
int n,a[N],c[N];
ll ans;

void merge(int start,int end)
{
    if(start==end)  
		return;
    int mid=(start+end)/2;
    int i=start,j=mid+1,point=start;
    merge(start,mid),merge(mid+1,end);
    while(i<=mid&&j<=end)
    {
        if(a[i]<=a[j])
    		c[point++]=a[i++];
    	else
        {
    		c[point++]=a[j++];
            ans+=mid-i+1;
        }
    }
    	
    
    while(i<=mid)
    	c[point++]=a[i++];
    while(j<=end)
    	c[point++]=a[j++];
    for(int l=start;l<=end;l++)
    	a[l]=c[l];
} 

int main()
{
    n = read();
    for(int i=1;i<=n;i++)
    	a[i] = read();
    merge(1,n);
    cout<<ans;
    return 0;
}

```



## 7-8

它叫二分查找

那我就二分查找呗

和猜数游戏很像，不过当时是我当那个二分的判断者，当初理解原理用的，用代码实现一下就好了

