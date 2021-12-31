#include<bits/stdc++.h>
using namespace std;

bool v[10000010];

int main()
{
	int n; cin >> n;
	int ans = 0;
	for(int i = 2; i <= n; ++i)
	{
		if(v[i]) continue;
		++ans;
		for(int j = i; j <= n; j += i) v[j] = 1;
	}
	printf("%d\n", ans);
	return 0;
}