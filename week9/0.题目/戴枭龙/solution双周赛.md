# 7-1 求解区间覆盖问题

用i表示x轴上坐标为[i-1,i]的区间（区间长度为1），并给出n个不同的整数来表示n个这样的区间。现在要求画出几条线段覆盖住所有的区间，条件是：每条线段可任意长，但要求所画线段长度之和最小，并且线段的数目不超过m。

### 输入格式:

第一行输入表示区间个数n和最大线段数m。 第2行输入n个点的坐标。

### 输出格式:

输出能覆盖所有区间的线段最小长度和。

### 输入样例:

```in
5 3
1 3 8 5 11结尾无空行
```

### 输出样例:

```out
7



结尾无空行
```

### 分析：

首先画一条线段刚好覆盖所有的区间

再找出各个区间的间隔大小，从大倒小排序

在总线端上划去m-1个间隔

```c++
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005 ;
int a[maxn], d[maxn] ;

bool cmp(const int &a, const int &b) {
	return a > b ;
}

int main() {
	int n, m ;
	cin >> n >> m ;
	for (int i = 0 ; i < n ; i++) {
		cin >> a[i] ;
	}
	sort(a, a + n);
	for (int i = 0 ; i < n - 1 ; i++) {
		d[i] = a[i + 1] - a[i]-1 ;
	}
	sort(d, d + n, cmp);
	int length = a[n - 1] - a[0] + 1 ;
	cout << length << endl;
	for (int i = 0; i < m - 1; i++) {
		length = length - d[i];
	}
	cout << length << endl;
	return 0 ;
}
```

