#include <bits/stdc++.h>
using namespace std;
int n;
char s[15],ans[15];
bool vis[15];
void dfs(int x,int step)
{
	if (step == n)
	{
		for (int i = 1;i <= n; i++)
			printf("%c",ans[i]);
		printf("\n");
		return;
	}
	for (int i = 0;i < n; i++)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		ans[step + 1] = s[i];
		dfs(i,step + 1);
		vis[i] = 0;
	}
	return;
}
int main()
{
	scanf("%s",s);
	n = strlen(s);
	sort(s,s + n);
	for (int i = 0;i < n; i++)
	{
		vis[i] = 1;
		ans[1] = s[i];
		dfs(i,1);
		vis[i] = 0;
	}
	return 0;
}
