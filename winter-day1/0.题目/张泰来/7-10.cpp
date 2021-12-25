#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int n,t,ans;
int f[105];
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= 100; i++)
	{
		f[i] = 200;
	}
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",&t);
		int minn = 200,pos = 0;
		for (int j = 1;j <= ans; j++)
		{
			if (f[j] >= t && minn > f[j])
			{
				minn = f[j];
				pos = j;
			}
		}
		if (!pos)
		{
			f[++ans] = t;
			if (ans == 1) v.push_back(t);
		} else {
			f[pos] = t;
			if (pos == 1) v.push_back(t);
		}
	}
	for (int i = 0;i < v.size(); i++)
	{
		printf("%d%c",v[i]," \n"[i == v.size() - 1]);
	}
	printf("%d\n",ans);
	return 0;
}
