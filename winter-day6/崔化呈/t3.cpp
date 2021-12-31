#include <bits/stdc++.h>
using namespace std;
set<int>s;
map<int,int>mp;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d",&num);
		s.insert(num);
		mp[num]++;
	}
	for(auto t:s)
	{
		printf("%d:%d\n",t,mp[t]);
	}
	return 0;
}
