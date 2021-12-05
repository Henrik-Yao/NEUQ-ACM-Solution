# WEEK7 周报
## 7-1 最少失约
### 题面
某天，诺诺有许多活动需要参加。但由于活动太多，诺诺无法参加全部活动。请帮诺诺安排，以便尽可能多地参加活动，减少失约的次数。假设：在某一活动结束的瞬间就可以立即参加另一个活动。

**输入格式:**
首先输入一个整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据首先输入一个正整数n，代表当天需要参加的活动总数，接着输入n行，每行包含两个整数i和j（0≤i<j<24），分别代表一个活动的起止时间。

**输出格式:**
对于每组测试，在一行上输出最少的失约总数。

**输入样例:**
在这里给出一组输入。例如：
```
1
5
1 4
3 5
3 8
5 9
12 14
结尾无空行
```
**输出样例:**

```
2
结尾无空行
```
### 思路
将活动时间从小到大排序，接着判断前一个活动的结束时间是否早于后一个活动的开始时间，以及参加活动的总数是否有增加(思路同lis)最后输出失约次数

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
struct duration
{
    int former;
    int latter;
};
bool cmp(duration da, duration db)
{
    return ((da.former < db.former) || ((da.former == db.former) && (da.latter < db.latter)));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        vector<duration> a(N);
        int len[N], max = 1;
        for (int i = 0; i < N; ++i)
        {
            cin >> a[i].former >> a[i].latter;
            len[i] = 1;
        }
        sort(a.begin(), a.end(), cmp);
        for (int i = 1; i < N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (a[i].former >= a[j].latter && len[i] < len[j] + 1)
                {
                    len[i] = len[j] + 1;
                    len[i] > max ? max = len[i] : 1;
                }
            }
        }

        cout << N - max << endl;
    }
    return 0;
}
```

## 7-2 跳一跳
### 题面
Drizzle 面前有一条由一堆非负整数组成的道路，从第一个数字起步，每次他都能跳出不大于当前数字的距离，每个数字之间的距离为1，那么他最少需要跳多少次才能到达终点？
**输入格式:**
第一行输入道路中数字的个数n也就是道路的长度，第二行输入这n个数字
**输出格式:**
输出一个数字，表示最少跳跃次数
**输入样例:**
```
5
2 3 1 1 4
结尾无空行
```
**输出样例:**
```
2
结尾无空行
```

### 思路
寻找当前位置可达范围内步长最大的数组下标，如果没找到比当前位置的步长大的返回可达的第一个位置的下标。然后在上一步找到的位置到当前位置可达的最远处之间寻找落点并更新
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int a[N];
int find(int l, int r)
{
    int re = l + 1;
    for (int i = l; i <= r; i++)
    {
        if (a[i] > a[l])
        {
            a[l] = a[i];
            re = i;
        }
    }
    return re;
}
int renew(int l, int r)
{
    int re = l;
    for (int i = re; i <= r; i++)
    {
        if (a[l] < a[i] + (i - l))
        {
            l = i;
        }
    }
    return l;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int j = 0, temp = 1, step, findj;
    while (j + a[j] < n - 1)
    {
        int step = a[j];
        int findj = find(j, a[j] + j);
        j = renew(findj, step + j);
        temp++;
    }
    cout << temp << endl;
    return 0;
}
```

