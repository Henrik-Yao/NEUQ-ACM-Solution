#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<set>
#include<vector>
#include<sstream>
#include <algorithm>
using namespace std;

const int maxv = 1000 + 10;

int p[maxv];

int findroot(int x) { return p[x] == x ? x : (p[x] = findroot(p[x])); }

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)p[i] = i;
	int t1, t2;
	for (int i = 0; i < m; i++)
	{
		cin >> t1 >> t2;
		//unite
		if (t1 == t2)continue;
		t1 = findroot(t1);
		t2 = findroot(t2);
		p[t2] = t1;
	}
	for (int i = 0; i < q; i++)
	{
		cin >> t1 >> t2;
		if (findroot(t1) == findroot(t2))cout << "In the same gang." << endl;
		else cout << "In different gangs." << endl;
	}
	set<int>cnt;
	for (int i = 1; i <= n; i++)
	{
		cnt.insert(findroot(i));
	}
	cout << cnt.size()<<endl;
}