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