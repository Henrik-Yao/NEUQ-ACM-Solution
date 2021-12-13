## **7-1 最少失约**

*某天，诺诺有许多活动需要参加。但由于活动太多，诺诺无法参加全部活动。请帮诺诺安排，以便尽可能多地参加活动，减少失约的次数。假设：在某一活动结束的瞬间就可以立即参加另一个活动。*

**对活动按结束日期排序**

~~不知道是不是贪心~~

```#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct act
{
    int q1, q2;
};

bool cmp(act a1, act a2)
{
    return (a1.q2 < a2.q2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;vector<act>a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].q1 >> a[i].q2;
        }
        sort(a.begin(), a.end(), cmp);
        int gs = 1;//参加活动次数
        int ent = a[0].q2;
        for (int i = 1; i < n; i++)
        {
            if (a[i].q1 >= ent)
            {
                gs++;
                ent = a[i].q2;
            }
        }
        cout << n - gs << endl;
    }
}
```



## **7-2 跳一跳**

*Drizzle 面前有一条由一堆非负整数组成的道路，从第一个数字起步，每次他都能跳出不大于当前数字的距离，每个数字之间的距离为1，那么他最少需要跳多少次才能到达终点？*

**记录比较每一格能到的最远值**

~~~#include<iostream>
using namespace std;
int jl[1000001];
int jl1[1000001];
int main()
{
    int n, cs = 0, now = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> jl[i];
    jl1[1] = jl[1] + 1;
    for (int i = 2; i <= n; i++)
        jl1[i] = max(jl1[i - 1], jl[i] + i);
    while (1)
    {
        now = jl1[now];
        cs++;
        if (now >= n) break;
    }
    cout << cs;
}