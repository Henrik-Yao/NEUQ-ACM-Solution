# WEEK9 周报
## 7-1 求解区间覆盖问题
### 题面
用i表示x轴上坐标为[i-1,i]的区间（区间长度为1），并给出n个不同的整数来表示n个这样的区间。现在要求画出几条线段覆盖住所有的区间，条件是：每条线段可任意长，但要求所画线段长度之和最小，并且线段的数目不超过m。

**输入格式:**
第一行输入表示区间个数n和最大线段数m。 第2行输入n个点的坐标。

**输出格式:**
输出能覆盖所有区间的线段最小长度和。

**输入样例:**
在这里给出一组输入。例如：
```
5 3
1 3 8 5 11
结尾无空行
```
**输出样例:**

```
7
结尾无空行
```
### 思路
贪心法，将输入的所有线段进行排序，并计算出相邻两条线段相差的距离，存入数组d[]，将距离数组d[]排序，从最终线段长度dis中减去lns条最长的距离即是结果

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int cmp(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, lns;
    cin >> N >> lns;
    int a[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    qsort(a, N, sizeof(int), cmp);
    int d[N - 1];
    for (int i = 0; i < N - 1; ++i)
    {
        d[i] = a[i] - a[i + 1] - 1;
    }
    qsort(d, N - 1, sizeof(int), cmp);
    int len = a[0] - a[N - 1] + 1;
    for (int i = 0; i < lns - 1; ++i)
    {
        len = len - d[i];
    }
    cout << len;
    return 0;
}
```

## 7-1 铺满方格
### 题面
有一个1×n的长方形，由边长为1的n个方格构成，例如，当n=3时为1×3的方格长方形如下图所示。求用1×1、1×2、1×3的骨牌铺满方格的方案总数。
**输入格式:**
测试数据有多组，处理到文件尾。每组测试输入一个整数n（1≤n≤50）。
**输出格式:**
对于每组测试，输出一行，包含一个整数，表示用骨牌铺满方格的方案总数。
**输入样例:**
```
3
结尾无空行
```
**输出样例:**
```
4
结尾无空行
```

### 思路
递龟，在数组中填入n=1,2,3时的情况，n>4时递龟解决，a[i] = a[i - 1] + a[i - 2] + a[i - 3]
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n)
    {
        long long a[51];
        a[1] = 1;
        a[2] = 2;
        a[3] = 4;
        if (n >= 4)
        {
            for (int i = 4; i <= n; ++i)
            {
                a[i] = a[i - 1] + a[i - 2] + a[i - 3];
            }
        }
        cout << a[n] << endl;
    }
}
```

