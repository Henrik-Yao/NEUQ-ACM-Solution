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
		if (b[i] == a[R])
		{
			pos = i;
			break;
		}
	}
	if (pos > l)
	{
		lson[a[R]] = a[L + pos - l - 1];
		build(L,L + pos - l - 1,l,pos - 1);
	}
	if (pos < r)
	{
		rson[a[R]] = a[R - 1];
		build(L + pos - l,R - 1,pos + 1,r);
	}
	return;
}
void print(int x)
{
	cout << x << " ";
	if (lson[x]) print(lson[x]);
	if (rson[x]) print(rson[x]);
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
	print(a[n]);
	printf("\n");
	return 0;
}
