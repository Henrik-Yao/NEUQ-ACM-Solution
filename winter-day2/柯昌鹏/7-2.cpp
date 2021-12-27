#include <bits/stdc++.h>
using namespace std;
int len,cnt;
int lson[27],rson[27],dep[27];
char s1[27],s2[27];
bool vis[1005];
bool build(int L,int R,int l,int r)
{
	memset(vis,0,sizeof(vis));
	for (int i = L;i <= R; i++)
	{
		vis[s1[i]] = 1;
	}
	for (int i = l;i <= r; i++)
	{
		if (!vis[s2[i]]) return false;
	}
	if (L == R && l == r)	
	{
		lson[R] = rson[R] = -1; 
		return true;
	}
	char x = s1[R];
	int pos;
	for (int i = l;i <= r; i++)
	{
		if (s2[i] == x) 
		{
			pos = i;
			break;
		}
	}
	bool f = 1;
	if (pos > l) 
	{
		lson[R] = L + pos - l - 1;
		dep[L + pos - l - 1] = dep[R] + 1;
		f = f && build(L,L + pos - l - 1,l,pos - 1);
	} else lson[R] = -1;
	if (pos < r)
	{
		rson[R] = R - 1;
		dep[R - 1] = dep[R] + 1; 
		f = f && build(L + pos - l,R - 1,pos + 1,r);
	} else rson[R] = -1; 
	return f;
}
void print(int rt)
{
	printf("%c",s1[rt]);
	if (lson[rt] != -1) print(lson[rt]);
	if (rson[rt] != -1) print(rson[rt]);
	return;
}
int main()
{
	while (scanf("%s",s1) != EOF)
	{
		int ans = 0;
		scanf("%s",s2);
		len = strlen(s1);
		if (!build(0,len - 1,0,len - 1))
		{
			printf("INVALID\n");
			continue;
		}
		for (int i = 0;i < len; i++)
		{
			ans = max(dep[i],ans);
		}
		printf("%d\n",ans);
		print(len - 1);
		printf("\n");
	}
	return 0;
}