#include <bits/stdc++.h>
using namespace std;
map<string,string> dict;
map <string,bool> vis; 
int n,m;
string s1,s2,s;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n; i++)
	{
		cin >> s1 >> s2;
		vis[s2] = true;
		dict[s2] = s1;
	}
	for (int i = 1;i <= m; i++)
	{
		cin >> s;
		if (!vis[s]) printf("eh\n");
		else {
			cout << dict[s] << endl; 
		}
	}
	return 0;
}
 
