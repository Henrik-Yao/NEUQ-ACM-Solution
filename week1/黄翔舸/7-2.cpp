#include<cstdio>
#include<iostream>
#include<cstring>
const int N = 1e6 + 1;
using namespace std;
int n, ans, a[N], arr1[N], arr2[N]; bool in[N];
int main()
{
	int max(int a, int b);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		arr1[i] = arr1[i - 1] + (!in[a[i]]);
		in[a[i]] = 1;
	}
	memset(in, 0, sizeof(in));
	for (int i = n; i; i--)
	{
		arr2[i] = arr2[i + 1] + (!in[a[i]]);
		in[a[i]] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		ans = max(ans, arr1[i] + arr2[i + 1]);
	}
	cout << ans;
	return 0;
}
int max(int a, int b)
{
	return a > b ? a : b;
}