# Week2

### 7-1

> 只关注第 ```i```个圆盘和第 ```i + 1```个圆盘，且第```i```个圆盘大小小于第```i + 1```个圆盘。
>
> 第 i 个圆盘应该放到第二个桩，第 i +1 个圆盘应该放到第三个圆盘。这里序号不一定是最初的序号。

```c++
#include <iostream>

using namespace std;

void func(int n, char a[], char b[], char c[])
{
    // 递归尽头
    if (n == 1) {
        printf("%s->%s\n", a, c);
    } else {
        // 如果有两个 1号放到 b 盘 2 号放到 c 盘 1 号从 b 盘放到 c 盘
        func(n - 1, a, c, b);
        printf("%s->%s\n", a, c);
        func(n - 1,b,a,c);
    }
}

int main()
{
    int n;
    cin >> n;
    char a[233],b[233],c[233];
    cin >> a >> b >> c;
    func(n,a,b,c);
    return 0;
}
```

### 7-2

> 桶记录，将攻城方案中每个数标记为1，如果所有的道路中a、b两值同时满足all[a] == 0 all[b] == 0则该方案不可行 否则可行

```c++
#include <iostream>

using namespace std;

const int N = 1e4 + 10;

struct city {
    int a,b;
}citys[N];

int main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> citys[i].a >> citys[i].b;
    }
    int k;
    cin >> k;
    while (k--) {
        // 桶记录
        int all[N] = {0};
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int num;
            cin >> num;
            all[num] = 1;
        }
        // 方案是否可行 默认为可行
        int is = 1;
        for (int i = 0; i < m; i++) {
            if (all[citys[i].a] == 0 && all[citys[i].b] == 0) {
                is = 0;
                break;
            }
        }
        // 循环 m 个道路 条件成立修改 is 为 0 表示不可行 
        if (is) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
```

### 7-3

> 区间一分为二，双指针分别指向两段开头，较小的数字存到临时数组中，最后存排最后的两段中最大的数。然后再传给原数组。
>
> 详细讲解在 [https://www.acwing.com/activity/content/problem/content/821/](https://www.acwing.com/activity/content/problem/content/821/)

```c++
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int q[N],tmp[N];

void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    int index = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j]) {
            tmp[index++] = q[i++];
        } else {
            tmp[index++] = q[j++];
        }
    }
    while (i <= mid) tmp[index++] = q[i++];
    while (j <= r) tmp[index++] = q[j++];
    for (int m = l,w = 0; m <= r; m++,w++) {
        q[m] = tmp[w];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", q[i]);
    }
    return 0;
}
```

