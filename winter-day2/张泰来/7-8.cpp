#include <bits/stdc++.h>
using namespace std;
int n,T,ans,cnt,k;
int a[1005],lson[1000005],rson[1000005];
void print(int x)
{
	if (!x) return;
	if (lson[x]) print(lson[x]);
	if ((++cnt) == k) printf("%d",x);
	else printf("%d ",x);
	if (rson[x]) print(rson[x]);
	return;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		cnt = k = 0;
		memset(lson,0,sizeof(lson));
		memset(rson,0,sizeof(rson));
		scanf("%d",&n);
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",a + i);
            if (a[i]) k++;
		}
		if (n == 1 && a[1] == 0)
		{
			printf("\n0\n");
			continue;
		}
		for (int i = 1;i <= n; i++)
		{
			if (!a[i]) continue;
			if (2 * i <= n) lson[a[i]] = a[2 * i];
			if (2 * i + 1 <= n) rson[a[i]] = a[2 * i + 1];
		}
		print(a[1]);
		printf("\n");
		while (!a[n]) n--;
		ans = floor(log2(n)) + 1;
		printf("%d\n",ans);
	}
	return 0;
}

