#include <bits/stdc++.h>
using namespace std;
int a[10009];

int main()
{
	int n; int k;
	cin >> n;
	int maxx = 0;
	while(n--) {
		cin >> k;
		maxx = max(maxx, k);
		a[k]++;
	}
	
	for (int i = 0; i <= maxx; i++)
	{
		if(a[i]) cout << i << ":" << a[i] << endl;
	}
	return 0;
}
