#include <bits/stdc++.h>

using namespace std; 

#define int long long

const int N = 110; 

int n; 
int f[N];

void init()
{
	f[1] = 2; 
	for(int i = 2; i <= 36; i ++)
	{
		f[i] = 3 * f[i - 1] + 2;
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