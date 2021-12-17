# WEEK 8

### 最少失约

经典的贪心算法题，核心是 贪心是有方向的，这道题的方向是活动尽早点结束
总而言之，贪心算法就是见好就收，没有全局观

```C++
#include <bits/stdc++.h>
using namespace std;
struct activity
{
    int num;   //该活动编号
    int begin; //该活动的开始时间
    int end;   //该活动的结束时间
    int mark;  //该活动是否加入最优解行列
};
void greedselect(activity act[], int n)
{
    int best = act[1].begin;
    for (int i = 1; i <= n; i++)
    {
        if (act[i].begin >= best)
        {//如果活动相容
            best = act[i].end;
            act[i].mark = 1;
        }
    }
}
bool cmp(activity a, activity b)
{
    return a.end < b.end;
}
//核心是 贪心是有方向的，这道题的方向是活动尽早点结束
//总而言之，贪心算法就是见好就收，没有全局观
int main()
{
    int k; //测试组数
    cin>>k;
    for (int j = 1; j <= k; j++)
    {
        activity act[1000];
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> act[i].begin;
            cin >> act[i].end;
            act[i].num = i;  //编号进行赋值
            act[i].mark = 0; //初始状态为均未加入行列
        }
        sort(act + 1, act + n, cmp);
        greedselect(act, n);
        int miss=0;
        for(int i=1;i<=n;i++)
        {
            if(act[i].mark==0)
            miss++;
        }
        cout<<miss<<endl;
    }
    return 0;
}
```

### 跳一跳

通过定义一个max值来记录此时的跳跃最远距离，当max值更新时，跳跃次数需要加1.

注意：需要将本区间内的 ***最大*** 值找到！

```C++
#include <bits/stdc++.h>
using namespace std;
int sum = 0; //为跳跃的总次数
int path[1000001];
int flag = 0;
int f[1201011];
int getmax(int m, int n)
{
    int max = path[m] + m;
    for (int i = m; i <= n; i++)
    {
        if (path[i] + i > max)
            max = path[i] + i;
    }
    return max;
}
void greedsearch(int n)
{
    int max = 0; //6 3 1 1 1 1 2 2 3 1
    int l = 1, r = 1;
    while (r <= n)
    {
        int remp = getmax(l, r);
        for (int j = r + 1; j <= remp; ++j)
            f[j] = f[r] + 1;
        l = r + 1;
        r = remp;
    }
}
int main()
{
    int num;
    cin >> num; //道路个数
    for (int i = 1; i <= num; i++)
        cin >> path[i];
    // generate_max(num);
    greedsearch(num);
    cout << f[num];
    return 0;
}
```

