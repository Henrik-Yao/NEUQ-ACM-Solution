# 7-1相邻数对
~~~c++
#include <iostream>
using namespace std;
main()
{
	int n;
	int sum = 0;
	cin >> n;
	int list[n];
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (list[i] - list[j] == 1||list[i] - list[j]==-1)
			{
				sum++;
			}
		}
	}
	cout << sum<<endl;
}
~~~
# 7-2文本智能提示
~~~c++
#include <iostream>
#include <map>
#include <deque>
#include <algorithm>
using namespace std;
bool compare(pair<string, unsigned long long>, pair<string, unsigned long long>);
map<string, unsigned long long> dict;
deque<pair<string, unsigned long long>> que;
main()
{
	int n, m, k;
	string key;
	unsigned long long numb;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> numb >> key;
		if (dict.count(key)) //存在
		{
			if (dict[key] < numb) //并且新数据更符合要求
				dict[key] = numb;
		}
		else //不存在
			dict[key] = numb;
	}
	string target;
	for (int i = 0; i < m ; i++)
	{
		cin >> target;
		int length = target.length();
		for (auto it = dict.begin(); it != dict.end(); it++) //还可以进行优化
		{
			bool is = 1;
			for (int j = 0; j < length; j++)
			{
				if (it->first[j] != target[j])
				{
					is = 0;
					break;
				}
			}
			if (is == 1 && it->first != target)
			{
				que.push_back({it->first, it->second});
			}
		}
		if (que.size() == 0)
		{
			cout << "no suggestion" << endl
				 << endl;
			continue;
		}
		sort(que.begin(), que.end(), compare);
		for (int j = 0; j < que.size() && j < k; j++)
		{
			cout << (que.begin() + j)->first << endl;
		}
		if(i<m-2)
		{
			cout << endl;
		}
		que.clear();
	}
}
bool compare(pair<string, unsigned long long> a, pair<string, unsigned long long> b)
{
	return a.second > b.second;
}
~~~
# 7-3两个有序序列的中位数
~~~c++
#include <iostream>
using namespace std;
main()
{
	int n;
	cin >> n;
	int a[n], b[n], cache[2 * n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	int pointa = 0,pointb = 0,pointc=0;
	while (pointa!=n&&pointb!=n)
	{
		if(a[pointa]>b[pointb])
		{
			cache[pointc++] = b[pointb++];
		}
		else
			cache[pointc++] = a[pointa++];
	}
	while(pointb!=n)
	{
		cache[pointc++] = b[pointb++];
	}
	while(pointa!=n)
	{
		cache[pointc++] = a[pointa++];
	}
	cout << cache[(2 * n - 1) / 2];
}
~~~
# 7-4二分查找
~~~c++
#include <iostream>
using namespace std;
int find(int, int *);
int n;
int deep=0;
main()
{

	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int t;
	cin >> t;
	cout << find(t, a) << endl
		 << deep;
}
int find(int target, int *list)
{
	int l = 0;
	int r = n - 1;
	while (l<=r)
	{
		deep++;
		int mid = l + (r - l) / 2;
		if(target==list[mid])
		{
			return mid;
		}
		else if(target>list[mid])
		{
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return -1;
}
~~~
# 7-5冰岛人
~~~c++
#include <iostream>
#include <map>
using namespace std;
struct People
{
	string firstname;
	string seccondname;
	int order;
	int orderoffather = -1;
	bool isman = 1;
};
map<string, int> name2order;
People list[100];
int path[100],p=0;
int path2[100], p2 = 0;
int deep=0,deep2=0;
void dls(int);
void dls2(int);
main()
{
	int n;
	cin >> n;
	string firstname, secondname;
	for (int i = 0; i < n; i++)
	{
		cin >> firstname >> secondname;
		name2order.insert({firstname, i});
		list[i].firstname = firstname;
		list[i].seccondname = secondname;
		if (secondname[secondname.length() - 1] == 'f' || secondname[secondname.length() - 1] == 'r')
		{
			list[i].isman = 0;
		}
		if (list[i].seccondname[secondname.length() - 1] == 'f' || list[i].seccondname[secondname.length() - 1] == 'm')
		{
			list[i].seccondname.pop_back();
		}
		if (list[i].seccondname[secondname.length() - 1] == 'r')
		{
			list[i].seccondname.erase(secondname.length() - 7,secondname.length() - 1);
		}
		if (list[i].seccondname[secondname.length() - 1] == 'n')
		{
			list[i].seccondname.erase(secondname.length() - 4,secondname.length() - 1);
		}
		list[i].orderoffather = name2order[list[i].seccondname];
	}
	cin >> n;
	string a, b, c, d;
	for (int i = 0; i < n;i++)
	{
		cin >> a >> b >> c >> d;
		if(list[name2order[a]].seccondname != b||list[name2order[c]].seccondname != d)
		{
			cout << "NA" << endl;
			continue;
		}
		if(list[name2order[a]].isman==list[name2order[c]].isman)
		{
			cout << "Whatever" << endl;
			continue;
		}
		deep = 0,deep2=0;
		p = 0, p2 = 0;
		dls(name2order[a]), dls2(name2order[c]);
		bool done = 0;
		for (int k = 0; k < p; k++)
        {
            for (int l = 0; l < p2; l++)
            {
                if (path[k] == path2[l])
                {
                    done = 1;//优化
                    break;
                }
            }
            if (done == 1)//优化
            {
                break;
            }
        }
		if(done==1)
		{
			cout << "No" << endl;
		}
		else
			cout << "Yes" << endl;
	}
}
void dls(int a)
{
	if(a==-1||deep==4)
	{
		return;
	}
	path[p++] = a;
	deep++;
	dls(list[a].orderoffather);
	deep--;
}
void dls2(int a)
{
	if(a==-1||deep2==4)
	{
		return;
	}
	path2[p2++] = a;
	deep2++;
	dls2(list[a].orderoffather);
	deep2--;
}
~~~
# 7-6二分查找
~~~c++
#include <iostream>
#include <algorithm>
using namespace std;
int find(int, int *);
int n;
int deep = 0;
main()
{
	while (cin >> n)
	{
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = 0; i < n - 1; i++)
		{
			cout << a[i] << ' ';
		}
		cout << a[n - 1]<<endl;
		int k;int t;
		cin >> k;
		for (int i = 0; i < k-1; i++)
		{
			
			cin >> t;
			cout << find(t, a)<<' ';
		}
		cin >> t;
		cout << find(t, a)<<endl;
	}
}
int find(int target, int *list)
{
	int l = 0;
	int r = n - 1;
	while (l <= r)
	{
		deep++;
		int mid = l + (r - l) / 2;
		if (target == list[mid])
		{
			return mid+1;
		}
		else if (target > list[mid])
		{
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return 0;
}
~~~
# 7-7愤怒的牛
~~~c++
#include <bits/stdc++.h>
using namespace std;
int n, m, a[200000];
bool check(int mid)
{
	int tri = 1, point = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (a[i] - a[tri] >= mid)
		{
			tri = i;
			point++;
		}
	}
	return point >= m;
}
main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int l = 0, r = 1061109567, ans = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid))
		{
			l = mid + 1, ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans << "\n";
}
~~~