# day6

## 7-1 直接插入排序

> **选择排序-插入排序**
>
> 从第二个数开始，每插入一个数，将前面的数排序，后面的数不变

```c++
#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
const int N = 110;
int n;
int a[N];
int main()
{
    while (cin >> n) {
        vec.clear();
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        vec.push_back(a[0]);
        for (int i = 1; i < n; i++) {
            vec.push_back(a[i]);
            sort(vec.begin(), vec.end());
            for (int j = i + 1; j < n; j++) vec.push_back(a[j]);
            int flag = 1;
            for (auto &i : vec) {
                flag == 1 ? printf("%d", i), flag = 0 : printf(" %d", i);
            }
            puts("");
            for (int j = i + 1; j < n; j++) vec.pop_back();
        }
    }
    return 0;
}
```

## 7-2 成绩排序

> 可以使用**冒泡排序**
>
> 注意排序规则即可

```c++
#include <bits/stdc++.h>
using namespace std;
struct Bnode {
    char name[23];
    int s;
};
int n;
int main()
{
    cin >> n;
    Bnode man[n];
    ios::sync_with_stdio(false);
    for (int i = 0; i < n; i++) {
        cin >> man[i].name >> man[i].s;
    }
    for (int i = 1; i < n; i++) { // 后
        for (int j = 0; j < i; j++) { // 前
            if (man[i].s > man[j].s || (man[i].s == man[j].s && strcmp(man[i].name, man[j].name) < 0)) swap(man[i], man[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << man[i].name << " " << man[i].s << endl;
    }
    return 0;
}
```

## 7-3 统计工龄

> **桶排序**
>
> 这里能用桶排序是因为工龄的数据范围不大，不需要开很大的数组去存，所以能用桶排序

```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, q[N], x;
int main()
{
    memset(q, 0, sizeof q);
    cin >> n;
    while (n--) {
        scanf("%d", &x);
        q[x]++;
    }
    for (int i = 0; i < N; i++) {
        if (q[i] != 0) cout << i << ":" << q[i] << endl;
    }
    return 0;
}
```

## 7-4 最接近神的人

> **归并排序**
>
> 计算逆序对可以使用归并排序，分治思想

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 6e5 + 10;
LL n, ans = 0;
int q[N], tmp[N];
LL merge_sort(int l, int r)
{
    if (l >= r) return 0;
    int mid = l + r >> 1;
    ans = merge_sort(l, mid) + merge_sort(mid + 1, r);
    int idx = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) q[i] <= q[j] ? tmp[idx++] = q[i++] : (tmp[idx++] = q[j++], ans += mid - i + 1);
    while (i <= mid) tmp[idx++] = q[i++];
    while (j <= r) tmp[idx++] = q[j++];
    for (int u = l, v = 0; u <= r; u++, v++) q[u] = tmp[v];
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    printf("%lld", merge_sort(0, n - 1));
    return 0;
}
```

## 7-5 堆排序

> **堆排序**
>
> 1. 构建最大堆或最小堆
> 2. 调整结构

```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
int a[N];
void adjustHeap(int i, int len) {
    int tmp = a[i];
    for (int k = i * 2 + 1; k < len; k = k * 2 + 1) {
        if (k + 1 < len && a[k] < a[k + 1]) k++;
        if (a[k] > tmp) a[i] = a[k], i = k;
        else break;
    }
    a[i] = tmp;
}
void HeapSort() {
    // 1. 构建大顶堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        adjustHeap(i, n);
    }
    // 
    for (int i = 0; i < n; i++) printf("%d ", a[i]); puts("");
    // 2. 调整堆结构
    for (int i = n - 1; i >= 0; i--) {
        swap(a[i], a[0]);
        adjustHeap(0, i);
        if (i != 0) {for (int j = 0; j < n; j++) printf("%d ", a[j]); printf("\n");}
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    HeapSort();
    return 0;
}
```

## 7-6 快速排序

> **快速排序**
>
> 快速排序是以第一个数为基准，从前向后找到第一个比它大的数，从后向前找到第一个比它小的数，交换两者，循环下去直到前指针等于后指针，然后将两指针所指位置数与基准数交换这样便可以让交换后基准数以前都比它小，以后都比它大
>
> **例如，题目样例步骤**：
>
> 4 5 3 2 1 (先找右小， 后找左大)（NA 表示两指针已经在相同位置，需要交换两指针位置数与基准数）
>
> 1. 基准：4   左大：5 右小：1 ----> 4 1 3 2 5
> 2. 基准：4   左大：NA 右小：2  ----> 2 1 3 4 5
> 3. 基准：2   左大：NA 右小：1 ----> 1 2 3 4 5

```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
int a[N];
void quick_sort(int l, int r) {
    if (l >= r) return;
    int x = a[l];
    int i = l, j = r;
    while (i != j) {
        while (a[j] > x && i < j) j--;
        while (a[i] <= x && i < j) i++;
        if (i < j) swap(a[i], a[j]);
    }
    swap(a[l], a[i]);
    for (int m = 0; m < n; m++) printf("%d ", a[m]); printf("\n");
    quick_sort(l, j - 1), quick_sort(j + 1, r);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quick_sort(0, n - 1);
    for (int m = 0; m < n; m++) printf("%d ", a[m]); printf("\n");
    return 0;
}
```

