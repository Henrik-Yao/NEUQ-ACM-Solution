#include <bits/stdc++.h>
using namespace std;
int T,n;
long long f[45];
int main()
{
	f[0] = 1;
	for (int i = 1;i <= 35; i++)
	{
		f[i] = f[i - 1] * 3;
	}
	while (cin >> n)
	{
		cout << f[n] - 1 << endl;
	}
	return 0;
}
