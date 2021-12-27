#include <bits/stdc++.h>
using namespace std;
int a[100009], b[100009], c[100009];
int main()
{
	int n = 0;
	while(cin >> a[++n]); n--;
	sort(a+1,a+1+n);
	int t1 = 0, t2 = 0;
	for(int i = 1; i <= n; i++) 
	{
		cout << a[i];
		if(i < n) cout << "->";
		if(a[i]%2) c[++t2] = a[i];
		else b[++t1] = a[i];
	} 
	cout << endl;
	for(int i = 1; i <= t2; i++) 
	{
		cout << c[i];
		if(i < t2) cout << "->";
	}
	cout << endl;
	for(int i = 1; i <= t1; i++) 
	{
		cout << b[i];
		if(i < t1) cout << "->";
	}
	return 0;
}
