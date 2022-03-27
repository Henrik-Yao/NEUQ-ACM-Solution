## 7-1  **求解区间覆盖问题**

*用i表示x轴上坐标为[i-1,i]的区间（区间长度为1），并给出n个不同的整数来表示n个这样的区间。现在要求画出几条线段覆盖住所有的区间，条件是：每条线段可任意长，但要求所画线段长度之和最小，并且线段的数目不超过m。*

**排序，消除距离最大的几段**

~~话说这是不是就是贪心思想~~

```#include<iostream>
#include<algorithm>
using namespace std;
int a[100000];
int jl[99999];//统计相邻数差值
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++)
        jl[i] = a[i + 1] - a[i] - 1;
    sort(jl, jl + n - 1);
    int len = a[n - 1] - a[0] + 1;
    int gs = n - 2;
    for (int j = 0; j < m - 1; j++)
    {
        len = len - jl[gs];
        gs--;
    }
    cout << len;
}
```



## **7-1 铺满方格**

*有一个1×n的长方形，由边长为1的n个方格构成，例如，当n=3时为1×3的方格长方形如下图所示。求用1×1、1×2、1×3的骨牌铺满方格的方案总数。*

**统计规律，找到规律后很简单**

```#include<iostream>
using namespace std;
int main()
{
	long long n;
	long long a[51];
	a[1]=1;
	a[2]=2;
	a[3]=4;
	for(int i=4;i<=50;i++)
    {
        a[i]=a[i-1]+a[i-2]+a[i-3];
    }
	while(cin>>n)
    {
        cout<<a[n]<<endl;
    }
}
```

