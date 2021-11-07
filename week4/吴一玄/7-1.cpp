#include<bits/stdc++.h>
using namespace std;

bool Check(int x)
{
	for(int i = 2; i * i <= x; ++i)
		if(x % i == 0) return 0;
	return 1;
}

int v[10010];

int main()
{
	for(int i = 2; i <= 10000; ++i)
		v[i] = Check(i);
	int a, b;
	while(cin >> a >> b)
	{
		vector<int> ans;
		for(int i = a; i <= b; ++i)
			if(v[i]) ans.push_back(i);
		for(int i = 0; i < ans.size(); ++i)
			printf("%d%c", ans[i], i == (ans.size() - 1) ? '\n' : ' ');
	}
	return 0;
}