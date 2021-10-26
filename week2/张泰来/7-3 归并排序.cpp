#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005],b[100005];
void merge_sort(int l,int r)
{
	if (l == r) return;
	int mid = (l + r) >> 1,cnt = l - 1;
	merge_sort(l,mid);
	merge_sort(mid + 1,r);
	int now1 = l,now2 = mid + 1;
	while (now1 <= mid && now2 <= r)
	{
		if (a[now1] <= a[now2])  
		{
			b[++cnt] = a[now1];
			now1++;
		} else {
			b[++cnt] = a[now2];
			now2++;
		}
	}
	if (now1 <= mid)
	{
		for (int i = now1;i <= mid; i++)
		{
			b[++cnt] = a[i];
		}
	}
	if (now2 <= r)
	{
		for (int i = now2;i <= r; i++)
		{
			b[++cnt] = a[i];
		}
	}
	for (int i = l;i <= r; i++)
	{
		a[i] = b[i];
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",a + i);
	}
	merge_sort(1,n);
	for (int i = 1;i <= n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
