#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
unsigned long long a[70], f[70];
int main()
{
	memset(f, 2, sizeof(f));
	int n;
	while (cin >> n) {
		a[0] = 0;
		for (int i = 1; i <= n; i++) {
			a[i] = a[i - 1] * 2 + 1;
		}
		f[1] = 1; f[0] = 0;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
				f[i] = min(f[i], f[j] * 2 + a[i - j]);
		}
		cout << f[n]<<endl;
	}
}
