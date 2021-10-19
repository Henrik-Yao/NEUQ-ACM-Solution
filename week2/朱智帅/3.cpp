#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<list>
#include<queue>
#include<vector>
#include<stack>
#include<string.h>
using namespace std;
void merge(int a[], int l, int mid, int r)
{
	int newa[100001], i, j, k;
	for (i = l; i <= r; i++)
		newa[i - l] = a[i];
	i = l, j = mid + 1;
	for (k = l; k <= r; k++)
	{
		if (i > mid)
		{
			a[k] = newa[j - l];
			j++;
		}
		else if (j > r)
		{
			a[k] = newa[i - l];
			i++;
		}
		else if (newa[i-l]<newa[j-l])
		{
			a[k] = newa[i - l];
			i++;
		}
		else
		{
			a[k] = newa[j - l];
			j++;
		}
	}
}
void number_sort(int a[], int l, int r)
{
	if (l >= r) return;
	else
	{
		int mid = (r + l) / 2;
		number_sort(a, l, mid);
		number_sort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}
int main()
{
	int n, i, a[100001];
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	number_sort(a, 0, n - 1);
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}