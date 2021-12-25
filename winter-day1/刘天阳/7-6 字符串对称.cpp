#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin >> a;
	int r = a.length()-1, l = 0;
	while(l < r)
	{
		if(a[l++] != a[r--]) 
		{
			cout << "no" ;
			return 0;
		}
	}
	cout << "yes";
	return 0;
}
