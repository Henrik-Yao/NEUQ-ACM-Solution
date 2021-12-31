#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a, b;
	while(getline(cin, a))
	{
		bool v[1009];
        memset(v,0,sizeof(v));
		getline(cin, b);
		for (int i = 0; i < b.size(); i++) v[b[i]] = 1;
		for (int i = 0; i < a.size(); i++) if(!v[a[i]]) cout << a[i];
		cout << endl;
	}
	return 0;
}
