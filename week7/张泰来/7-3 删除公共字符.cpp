#include <bits/stdc++.h>
using namespace std;
string s1,s2;
bool vis[100005];
int main()
{
	while (getline(cin,s1))
	{
		memset(vis,0,sizeof(vis));
		getline(cin,s2);
		for (int i = 0;i < s2.size(); i++)
		{
			vis[s2[i] - 0] = true;
		}
		for (int i = 0;i < s1.size(); i++)
		{
			if (!vis[s1[i]])
			{
				cout << s1[i]; 
			}
		}
		cout << endl;
	}
	
	
//	cout << ' ' - 0 << endl;
	return 0;
}
