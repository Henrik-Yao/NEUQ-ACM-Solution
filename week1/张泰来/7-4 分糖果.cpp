#include <bits/stdc++.h>
using namespace std;
int n,ans;
void dfs(int left,int step)
{
	if (step > n) return;
	if (left == 1) 
	{
		ans++;
		return;
	}
	for (int i = 1;i < left; i++)
	{
		if (left % i) continue;
		dfs(i,step + 1);
	}
	ans++;//²»·Ö 
	return;
}
int main()
{
	scanf("%d",&n);
	dfs(n,1);
	printf("%d\n",ans);
	return 0; 
}
