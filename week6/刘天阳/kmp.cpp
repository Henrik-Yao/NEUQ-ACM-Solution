#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
string a, b;
int kmp[N];
void Vkmp()
{
	int j = 0;
	for (int i = 2; i < b.size(); i++)
	{
		while(j && b[j+1] != b[i]) j = kmp[j];
		if(b[j+1] == b[i]) j++;
		kmp[i] = j;
	}
}
int main()
{
	cin >> a >> b;
	a = " "+a;
	b = " "+b;
	Vkmp();
	int j = 0, ans = 0;
	for (int i = 1; i < a.size(); i++)
	{
		while(j && a[i] != b[j+1]) j = kmp[j];
		if(a[i] == b[j+1]) j++;
		if(j == b.size()-1)
		{
			ans ++;
			j = kmp[j];
		}
	}
	cout << ans;
	return 0;
}
