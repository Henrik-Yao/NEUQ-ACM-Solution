#include <bits/stdc++.h>
using namespace std;
int n;
int a[15],b[15],lson[1005],rson[1005];
void build(int L,int R,int l,int r)
{
	if (L == R && l == r) return;
	int pos;
	for (int i = l;i <= r; i++)
	{
		if (b[i] == a[L])
		{
			pos = i;
			break;
		}
	}
	if (pos > l)
	{
		lson[a[L]] = a[L + 1];
		build(L + 1,L + pos - l,l,pos - 1);
	}
	if (pos < r)
	{
		rson[a[L]] = a[L + pos - l + 1];
		build(L + pos - l + 1,R,pos + 1,r);
	}
	return;
}
void print(int x)
{
	if (lson[x]) print(lson[x]);
	if (rson[x]) print(rson[x]);
	printf("%d ",x);
	return;
}
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",a + i);
	}
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",b + i);
	}
	build(1,n,1,n);
	
	print(a[1]);
	printf("\n");
	return 0;
}
