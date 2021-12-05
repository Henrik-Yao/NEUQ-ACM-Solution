#include<bits/stdc++.h>
using namespace std;
map<string,string>v;
int main()
{
	int n, m;
	cin >> n >> m;
	while(n--)
	{
		string a, b;
		cin >> a >> b;
		v[b] = a;
	}
	while(m--)
	{
		string a;
		cin >> a;
		if(v.count(a)) cout << v[a] << endl;
		else cout << "eh" << endl;	
	}
	return 0;
}
