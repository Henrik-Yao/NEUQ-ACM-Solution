## 7-1 相邻数对

给定n个不同的整数，问这些数中有多少对整数，它们的值正好相差1。

很简单的判断，给个数组看是否出现即可

~~~#include <iostream>
#include<string.h>
using namespace std;
int gs = 0;
int ma[10002];//是否出现
int ss[10002];
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l; cin >> l;
		ma[l] = 1;
		ss[i] = l;

	}
	for (int i = 0; i < n; i++)
	{
		if (ma[ss[i] - 1])gs++;
		if (ma[ss[i] + 1])gs++;
	}
	cout << gs / 2 << endl;
	return 0;
}
~~~

## 7-2 文本智能提示

百度、谷歌等搜索引擎，以及输入法等各种软件通常包含这样一个功能，当用户在输入框输入信息时，软件会提供一种“智能提示”。对用户所输入的信息，自动补全、列出可能的完整单词，提示给用户，以方便用户输入，提升用户体验。



## 7-3 两个有序序列的中位数

已知有两个等长的非降序序列S1, S2, 设计函数求S1与S2并集的中位数。有序序列*A*0,*A*1,⋯,*A**N*−1的中位数指*A*(*N*−1)/2的值,即第⌊(*N*+1)/2⌋个数（*A*0为第1个数）。

~~~#include <iostream>
using namespace std;
int a[100001], b[100001];
int main()
{
	int cnt = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int aq = 1, bq = 1, ans = a[1];
	while (cnt < (2 * n + 1) / 2)
	{
		cnt++;
		if (aq <= n && (bq == n + 1 || a[aq] <= b[bq]))
		{
			ans = a[aq];
			aq++;
		}
		else
		{
			ans = b[bq];
			bq++;
		}
	}
	cout << ans;
	return 0;
}
~~~

## 7-4 二分查找

输入n值(1<=n<=1000)、n个非降序排列的整数以及要查找的数x，使用**二分查找算法**查找x，输出x所在的下标（0~n-1）及比较次数。若x不存在，输出-1和比较次数。

~~~#include <iostream>
using namespace std;
int sum = 0;
int a[10009];
int ans = -1;
int main()
{
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> x;
	int l = 0, r = n - 1;
	while (l <= r)
	{
		sum++;
		int m = (l + r) / 2;
		if (x == a[m]) { ans = m; break; }
		if (x > a[m]) l = m + 1;
		else r = m - 1;
	}
	cout << ans << endl << sum << endl;
	return 0;
}
~~~

## **7-5 冰岛人**

### **愿天下有情人终成兄妹.jpg**

一开始想着直接dfs搜，卡时间了

## 7-6 二分查找

对于输入的n个整数，先进行升序排序，然后进行二分查找。

~~~#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int a[101];
int f;
int en;
int main()
{
	int n;
	while (cin >> n)
	{
		f = 0;
		memset(a, 0, 101);
		en = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			if (f)
				cout << " " << a[i];
			else { cout << a[i]; f = 1; }
		}
		f = 0; cout << endl;
		int m; cin >> m;
		while (m--)
		{
			en = 0;
			int s; cin >> s;
			int q1 = 0, q2 = n - 1;
			int mid = (q1 + q2) / 2;
			while (q1 <= q2)
			{
				if (a[mid] < s) { q1 = mid+1; mid = (q1 + q2) / 2; }
				else if (a[mid] > s) { q2 = mid-1; mid = (q1 + q2) / 2; }
				else { en = mid+1; break; }
			}
			if (f)cout << " " << en;
			else { cout << en; f = 1; }
		}
		cout << endl;
	}
}
~~~

## 7-7 愤怒的牛

农夫约翰建造了一座有*n*间牛舍的小屋，牛舍排在一条直线上，第*i*间牛舍在*x**i*的位置，但是约翰的*m*头牛对小屋很不满意，因此经常互相攻击。约翰为了防止牛之间互相伤害，因此决定把每头牛都放在离其它牛尽可能远的牛舍。也就是要最大化最近的两头牛之间的距离。

牛们并不喜欢这种布局，而且几头牛放在一个隔间里，它们就要发生争斗。为了不让牛互相伤害。John 决定自己给牛分配隔间，使任意两头牛之间的最小距离尽可能的大，那么，这个最大的最小距离是多少呢？

### **跟之前某道过河拆石头的题同类**

~~~#include <iostream>
#include<algorithm>
using namespace std;
int a[100010];
int l, r;
int n, c;

bool pd(int m)
{
    int lsz = 1, last = 1;          
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - a[last] >= m)
        {
            lsz++;          
            last = i;
        }
    }
    if (lsz >= c)return true;         
    return false;
}

int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)cin >> a[i];
    l = 1; r = a[n] - a[1];
    sort(a + 1, a + 1 + n);
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (pd(mid))l = mid + 1;
        else r = mid - 1;
    }
    cout << r;
    return 0;
}
