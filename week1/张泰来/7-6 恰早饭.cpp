#include <bits/stdc++.h>
using namespace std;
int n,T,v,t,ans = -1e9;
int main()
{
	scanf("%d%d",&n,&T);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d%d",&v,&t);
		if (t > T) ans = max(ans,v - t + T);
		else ans = max(ans,v);
	}
	printf("%d\n",ans);
	return 0;
}
