#include <bits/stdc++.h>
using namespace std;
int n;
int a[1005];
void rapid_sort(int L,int R)
{
	if (L >= R) return;
	int l = L,r = R,k = a[L];
	while (l < r)
	{
		while (l < r && a[r] > k) r--;
		while (l < r && a[l] <= k) l++;
		swap(a[l],a[r]);
	}
	swap(a[l],a[L]);
	for (int i = 1;i <= n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	rapid_sort(L,l - 1);
	rapid_sort(l + 1,R);
	return;
}
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",a + i);
	}
	rapid_sort(1,n);
	for (int i = 1;i <= n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
