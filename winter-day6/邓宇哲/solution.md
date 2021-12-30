# 7-1 直接插入排序
~~~c++
#include <iostream>
#include <cstring>
using namespace std;
main()
{
	int list[105];
	int n;
	while (cin >> n)
	{
		memset(list, 0, sizeof(list));
		for (int i = 1; i <= n; i++)
		{
			cin >> list[i];
		}
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (list[i] >= list[j - 1] && list[i] <= list[j])
				{
					int t = list[i];
					for (int m = i; m >= j + 1; m--)
					{
						list[m] = list[m - 1];
					}
					list[j] = t;
					break;
				}
			}
			for (int j = 1; j < n; j++)
			{
				cout << list[j] << ' ';
			}
			cout << list[n] << endl;
		}
	}
}
~~~
# 7-2 成绩排序
~~~c++
#include <iostream>
#include <algorithm>
using namespace std;
class Student
{
public:
	string name;
	int grade;
} list[25];
bool compare(Student, Student);
main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> list[i].name >> list[i].grade;
	}
	sort(list + 1, list + n + 1, compare);
	for (int i = 1; i <= n; i++)
	{
		cout << list[i].name << " " << list[i].grade << endl;
	}
}
bool compare(Student a, Student b)
{
	return (a.grade > b.grade || (a.grade == b.grade && a.name < b.name));
}
~~~
# 7-3 统计工龄
~~~c++
#include <iostream>
#include <algorithm>
using namespace std;
int list[100005];
main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	sort(list, list + n);
	for (int i = 0; i < n;)
	{
		int t = list[i], numb = 0;
		while (i < n && list[i] == t)
		{
			i++;
			numb++;
		}
		cout << t << ":" << numb << endl;
	}
}
~~~
# 7-4 最接近神的人
~~~c++
#include <bits/stdc++.h>
using namespace std;
long long a[1000001], cache[1000001];
long long sum = 0, k = 1;
void count(int, int);
main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	count(1, n);
	cout << sum;
}
void count(int l, int r)
{
	if (l >= r)
		return;
	int mid = (l + r) / 2;
	count(l, mid);
	count(mid + 1, r);
	k = 1;
	int i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (a[i] > a[j])
		{
			sum += (mid - i + 1);
			cache[k++] = a[j++];
		}
		else
			cache[k++] = a[i++];
	}
	while (i <= mid)
		cache[k++] = a[i++];
	while (j <= r)
		cache[k++] = a[j++];
	for (int m = 1; m < k; m++)
		a[m + l - 1] = cache[m];
}
~~~
# 7-5 堆排序
~~~c++
#include <iostream>
using namespace std;
int a[10000];
void heapify(int, int);
void heap_sort(int);
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	heap_sort(n);
}
void heap_sort(int n) //进行堆排序
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(i, n - 1);
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heapify(0, i - 1);
		for (int j = 0; j < n; j++)
		{
			cout << a[j] << " ";
		}
		cout << endl;
	}
}
void heapify(int start, int end) //建立堆
{
	int dad = start, son = 2 * start + 1;
	while (son <= end)
	{
		if (son + 1 <= end && a[son] < a[son + 1])
		{
			son++;
		}
		if (a[son] < a[dad])
		{
			return;
		}
		else
		{
			swap(a[son], a[dad]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}
~~~
# 7-6 快速排序
~~~c++
#include <iostream>
using namespace std;
int a[1024];
int n;
void sort(int, int);
main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
void sort(int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int temp = a[l];
	int i = l, j = r;
	while (i < j)
	{
		while (a[j] > temp && j > i)
			j--;
		while (a[i] <= temp && i < j)
			i++;
		if (i < j)
		{
			swap(a[j], a[i]);
		}
	}
	swap(a[i], a[l]);
	for (int o = 0; o < n; o++)
	{
		cout << a[o] << " ";
	}
	cout << endl;
	sort(l, i - 1);
	sort(j + 1, r);
}
~~~