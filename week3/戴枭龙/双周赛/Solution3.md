# 最大子段和

当和为负数，前面全部舍弃。

```c++
#include <bits/stdc++.h>
using namespace std;
int a[100001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max1 = 0, temp = 0;
	for (int i = 0; i < n; i++) {
		temp += a[i];
		if (temp < 0)
			temp = 0;
		else {
			if (temp > max1)
				max1 = temp;
		}

	}
	cout << max1;

	return 0;
}
```

# 汉诺塔问题

经典

```c++
#include <bits/stdc++.h>
using namespace std;

void hannuota(int n, string a, string b, string c) {
	if (n == 1)
		cout << a << "->" << c << endl;
	else {
		hannuota(n - 1, a, c, b);
		cout << a << "->" << c << endl;
		hannuota(n - 1, b, a, c);
	}
}

int main() {
	int n;
	cin >> n;
	string x, y, z;
	cin >> x >> y >> z;
	hannuota(n, x, y, z);
	return 0;
}
```

# 汉诺塔2

设F[n]为所求的最小步数.显然，当n=1时，F[n]=1;当n=2时，F[n]=3

1.将x(1<=x<=n)个盘从a柱依靠b,d柱移到c柱，这个过程需要的步数为F[x];

2.将a柱上剩下的（n-x）个盘依靠b柱移到d柱；这个移动方式相当于是一个经典汉诺塔，即这个过程需要的步数为2^(n-x)-1；

3.将c柱上的x个盘依靠a,b柱移到d柱上，这个过程需要的步数为F[x];

第3步结束后任务完成。

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[66], n;
	a[1] = 1;
	a[2] = 3;
	for (int i = 3; i < 65; i++) {
		int min = 666666;
		for (int j = 1; j < i; j++) {
			if (2 * a[j] + pow(2, i - j) - 1 < min)
				min = 2 * a[j] + pow(2, i - j) - 1;
		}
		a[i] = min;
	}
	while (cin >> n) {
		cout << a[n] << endl;
	}
	return 0;
}
```

# 汉诺塔3

将n个圆盘从第一根杆移到第三根杆需要 F(n)

将n-1个圆盘从第一根杆移到第三根杆   F(n-1)

将最大的一个圆盘从第一根杆移到第二根杆  1

将n-1个圆盘从第三根杆移到第一根杆    F(n-1)

将最大的一个圆盘从第二根杆移到第三根杆   1

将n-1个圆盘从第一根杆移到第三根杆    F(n-1)   

```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		long long a = 2;
		for (int i = 1; i < n; i++) {
			a = a * 3 + 2;
		}
		cout << a << endl;
	}
	return 0;
}

```

# 简单的归并

```c++
#include <bits/stdc++.h>
using namespace std;
int a[101];
int b[101];
int c[202];

int main() {
	int x, m, n;
	cin >> x;
	while (x--) {
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> a[i];
		}
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}
		int k = 1, i = 1, j = 1;
		while (i <= m && j <= n) {
			if (a[i] <= b[j]) {
				c[k++] = a[i++];
			} else {
				c[k++] = b[j++];
			}
		}
		while (i <= m)
			c[k++] = a[i++];
		while (j <= n)
			c[k++] = b[j++];
		for (int i = 1; i <= k - 2; i++) {
			cout << c[i] << " ";
		}
		cout << c[k-1] << endl;
	}

	return 0;
}
```

# 字符串的全排列

由于输出要求字典序从小到大，所以把字符取出后排序一下，然后dp

```c++
#include <bits/stdc++.h>
using namespace std;
string a;
int v[8];
char b[8];
string t[8];
int n, k;

void dps(int x) {
	if (x == n) {
		for (int i = 0; i < n ; i++) {
			cout << t[i];
		}
		cout << endl;
	} else {
		for (int j = 0; j < n; j++) {
			if (v[j] == 0) {
				v[j] = 1;
				t[x] = b[j];
				dps(x + 1);
				v[j] = 0;
			}
		}
	}
}

int main() {
	cin >> a;
	n = a.length();
	for (int j = 0; j < n; j++) {
		b[j] = a[j];
	}
	sort(b, b + n);
	dps(0);
	return 0;
}

```

# 逆序对

注意说明

说明：样例中如1和3不是逆序对，而3和2是1对逆序对，例子中共有14对逆序对。题目中可能有某些数字出现多次的情况。

归并排序的本质是递归分治，最小的状态就是1个数的时候，左部的所有数的逆序关系会在排序的同时已经得知。

```c++
#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int n;
long long sum = 0;

void mergesort(int L, int R) {
	if (L == R) {
		return ;
	}
	int m = (L + R) / 2;
	int i = L, j = m + 1, k = L;
	mergesort(L, m);
	mergesort(m + 1, R);
	while (i <= m && j <= R) {
		if (a[i] <=a[j]) {
			b[k] = a[i];
			k++;
			i++;
		} else {
			b[k] = a[j];
			k++;
			j++;
			sum = sum + m - i + 1;
		}
	}
	while (i <= m)
		b[k++] = a[i++];
	while (j <= R)
		b[k++] = a[j++];
	for (int k = L; k <= R; k++)
		a[k] = b[k];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	mergesort(1, n);
	cout << sum << endl;
	return 0;
}

```

# 二分查找

注意看题输出的是大于等于查找值的位置

输出在数组中第一个大于等于查找值的位置，如果数组中不存在这样的数，则输出数组长度加1。

```c++
#include <bits/stdc++.h>
using namespace std;
int a[1000010];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int i = 1, j = n, mid;
	while (i <= j) {
		mid = (i + j) / 2;
		if (m <= a[mid])
			j = mid - 1;
		else
			i = mid + 1;
	}
	if (a[i] >= m)
		cout << i ;
	else
		cout << n + 1 ;
	return 0;
}
```

