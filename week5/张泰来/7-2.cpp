#include <bits/stdc++.h>
using namespace std;
int T,N;
bool prime(int x)
{
	for (int i = 2;i <= sqrt(x); i++)
	{
		if (x % i == 0) return 0;
	}
	return 1;
}
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N;
		if (prime(N)) printf("1\n");
		else if (N % 2 == 0 || prime(N - 2)) printf("2\n");
		else printf("3\n");
	}
	
	return 0;
}
