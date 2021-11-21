#include <bits/stdc++.h>

using namespace std; 

#define int unsigned long long

const int N = 110; 

int n; 
int f[N], g[N];

void init()
{
	g[1] = 1; 
	for(int i = 2; i <= 64; i ++)
	{
		g[i] = g[i - 1] * 2 + 1; 
	}
	f[1] = 1; 
	for(int i = 2; i <= 64; i ++)
	{
        f[i] = 2 * f[1] + g[i - 1];
		for(int j = 1; j < i; j ++)
		{
			f[i] = min(f[i], 2 * f[j] + g[i - j]);
		}
	}
}



signed main()
{
    init();
	while(cin >> n)
	{
		cout << f[n] << endl;
	}
}