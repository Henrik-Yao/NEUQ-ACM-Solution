#include <bits/stdc++.h>
using namespace std;
int n;
string s,s1;
int main()
{
	scanf("%d",&n);
	cin >> s;
	int len = s.size();
	for (register int i = 1;i <= n; i++)
	{
		cin >> s1;
		int ans = 0;
		int len1 = s1.size();
		for (register int j = 0;j + len1 <= len; j++)
		{
			bool flag = 1;
			for (register int k = 0;k < len1; k++)
			{
				if (s1[k] != s[j + k]) 
				{
					flag = false;
					break;
				}
			}
			if (flag) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
