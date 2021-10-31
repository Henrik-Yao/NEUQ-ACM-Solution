#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<string.h>
#include<vector>
using namespace std;
int64_t cnt = 0;
void ni_sort(int ni[], int left, int mid, int right)
{
	int newni[1000001], i, j, k;

	for (k = left; k <= right; k++)
	{
		newni[k - left] = ni[k];
	}
	i = left, j = mid + 1;
	for (k = left; k <= right; k++)
	{
		if (i > mid)
		{
			ni[k] = newni[j - left];
			j++;
			cnt += mid - i + 1;
		}
		else if (j > right)
		{
			ni[k] = newni[i - left];
			i++;
		}
		else if (newni[i - left] > newni[j - left])
		{
			ni[k] = newni[j - left];
			j++;
			cnt = cnt + mid - i + 1;
		}
		else
		{
			ni[k] = newni[i - left];
			i++;
			
		}

	}
}
void findni(int ni[], int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	findni(ni, left, mid);
	findni(ni, mid + 1, right);
	ni_sort(ni, left, mid, right);
}
int main()
{
	int n, i;
	int ni[1000001];
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> ni[i];
	}
	findni(ni, 0, n - 1);
	cout << cnt;
	return 0;
}