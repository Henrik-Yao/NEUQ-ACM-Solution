#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int n,m,k,now;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	now = 0;
	for (int i = 1;i <= n; i++)
	{
		v.push_back(i);
	}
	for (int i = 1;i <= n; i++)
	{
		int len = v.size();
		if (i & 1)
		{
			now = (now - m + 1) % len + len;
			now %= len; 
			printf("%d ",v[now]);
			vector <int>::iterator t = v.begin() + now;
			v.erase(t);
			now--;
			if (now == -1) now = v.size() - 1;
		} else {
			now = (now + k - 1) % len + len;
			now %= len;
			printf("%d ",v[now]);
			vector <int>::iterator t = v.begin() + now;
			v.erase(t);
		}
	}
	return 0;
}
