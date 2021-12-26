#include <bits/stdc++.h>
using namespace std;
string a;
void ju(int l, int r)
{
	l++,r--;
	for(int i = r; i > l; i--)
	{
		cout << a[l]<< a[i];
	}
	cout << a[l];
}
int main()
{
	string A = "sae", B = "tsaedsae";
	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		if(a[i] == 'A') cout << A;
		else if(a[i] == 'B') cout << B;
		else if(a[i] == '(') 
		{
			int l = i;
			while(1)
			{
				if(a[++i] == ')') {ju(l, i); break;}
			}
		}
	}
	return 0;
}
