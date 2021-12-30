# day5

## 7-1 相邻数对

> 非常简单，开个数组记录数列中是否存在比它小 1 的数即可

```c++
#include <bits/stdc++.h>
using namespace std;
int a[1010];
int has[1010];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 1; i < n; i++) {
        // 增序后如果 后一个数比前一个数大 1 ，说明后一个数存在比它小 1 的数
        if (a[i] == a[i - 1] + 1) has[i] = 1;
        else {
            // 如果后一个数和前一个数相同并且前一个数存在比它小 1 的数，则后一个数一样也存在
            if (a[i] == a[i - 1] && has[i - 1] == 1) has[i] = 1;
        }
    }
    int total = 0;
    // 遍历一遍加起来即可
    for (int i = 1; i < n; i++) if (has[i] == 1) total++;
    cout << total << endl;
    return 0;
}
```

## 7-3 两个有序序列的中位数

> **不用去重**，排序即可
>
> 输出中位数

```c++
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> vec;
int main()
{
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num); vec.push_back(num);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &num); vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    cout << vec[(n * 2 - 1) / 2] << endl;
    return 0;
}
```

## 7-4 二分查找

> **二分查找算法**，注意**边界问题**即可

```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
int a[N];
int x;
int tot = 0;
int BinarySearch(int l, int r) {
    while (l < r) {
        tot++;
        int mid = l + r >> 1;
        if (a[mid] == x) return mid;
        if (a[mid] > x) r = mid - 1; // 如果上面的成立，这里大于等于只是大于, 不需要写等于
        if (a[mid] < x) l = mid + 1;
    }
    tot++; // 一定要加这一次  不然比较次数错误
    if (a[l] == x) return l;
    else return -1;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    cin >> x;
    int i = 0, j = n - 1;
    int ans = BinarySearch(i, j);
    cout << ans << endl << tot << endl;
    return 0;
}
```

## 7-5 冰岛人

> 记录每个人的 **parent**、在查询的两人的 上三代人中查找是否有相同的人即可

```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m;
map<string, string> parent; // 映射父母
map<string, int> gender; // 映射性别 1 为 男
set<string> exist; // 记录某人是否存在
int check(string last1, string last2) {
    int f1 = 1, f2 = 1;
    for (string sa = last1; sa.size() > 0; sa = parent[sa], f1++) {
        f2 = 1;
        for (string sb = last2; sb.size() > 0; sb = parent[sb], f2++) {
            if (f1 > 4 && f2 > 4) return 1;
            if (sa == sb && (f1 <= 4 || f2 <= 4)) return 0;
        }
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string last, family;
        cin >> last >> family;
        int len = family.size();
        if (family[len - 1] == 'n') {
            gender[last] = 1; exist.insert(last);
            parent[last] = family.substr(0, len - 4);
        } else if (family[len - 1] == 'r') {
            gender[last] = 0; exist.insert(last);
            parent[last] = family.substr(0, len - 7);
        } else if (family[len - 1] == 'm') {
            gender[last] = 1; exist.insert(last);
        } else if (family[len - 1] == 'f') {
            gender[last] = 0; exist.insert(last);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        string last1, family1, last2, family2;
        cin >> last1 >> family1 >> last2 >> family2;
        if (!exist.count(last1) || !exist.count(last2)) {
            cout << "NA" << endl;
        } else if (gender[last1] == gender[last2]) {
            cout << "Whatever" << endl;
        } else {
            if (check(last1, last2) == 1) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        
    }
    return 0;
}
```

## 7-6 二分查找

> **二分查找算法**， 注意**边界问题和数在数列中是否存在**即可（先排序）

```c++
int l = 0, r = n - 1;
while (l < r) {
    int mid = l + r >> 1;
    if (a[mid] >= num) r = mid;
    else l = mid + 1;
}
if (flag == 1) {
    flag = 0;
    if (a[l] == num) printf("%d", l + 1);
    else printf("0");
} else {
    if (a[l] == num) printf(" %d", l + 1);
    else printf(" 0");
}
```

## 7-7 愤怒的牛

> **二分答案**
>
> 重点是 `check()` 如果去写，以及**边界问题**

```c++
bool check(int x) {
    int sum = 0, base = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] - base >= x) {
            sum++; base = a[i];
        }
        if (sum >= m) return true;
    }
    if (sum + 1 < m) return false;
    return true;
}

for (int i = 2; i <= n; i++) l = min(l, a[i] - a[i - 1]); // 最小的左端
r = a[n] - a[1]; // 最大的右端
while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (check(mid)) l = mid;
    else r = mid - 1;
}
cout << l << endl;
```

