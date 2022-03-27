#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int next[1000005],f[1000005];
char s1[1000005],s2[1000005];
int main()
{
	scanf("%s",s1 + 1);
	scanf("%s",s2 + 1);
	s1[0] = s2[0] = 'a';
	int m = strlen(s1);
	int n = strlen(s2);
	n--;
	m--;
	next[1] = 0;
	for (int i = 2,j = 0;i <= n; i++)
	{
		while (j > 0 && s2[i] != s2[j + 1]) j = next[j];
		if (s2[i] == s2[j + 1]) j++;
		next[i] = j;
	}
	for (int i = 1,j = 0;i <= m; i++)
	{
		while (j > 0 && (j == n || s1[i] != s2[j + 1])) j = next[j];
		if (s1[i] == s2[j + 1]) j++;
		f[i] = j;
		if (f[i] == n) ans++;
	}
	printf("%d\n",ans);
	return 0;
} 
