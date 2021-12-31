#include <iostream>
using namespace std;
int a[1000000], c[1000000];
long long ans=0;
void mergesort(int a[], int left, int right)
{
	if (left >= right)
		return;
	int mid = (right + left) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);
	int k = 0;
	int i = left, j = mid + 1;
	while (i <= mid&&j<=right) {
		if (a[i] <= a[j])
			c[k++] = a[i++];
		else
			c[k++] = a[j++] , ans += mid - i + 1;
	}
	while (j <= right)
			c[k++] = a[j++];
	while (i <= mid)
			c[k++] = a[i++];
	for (i = left, j = 0; i <= right; i++, j++)
	{
		a[i] = c[j];
	}
}   
int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	mergesort(a, 0, n - 1);
	// for (int i = 0; i < n; i++)
	// 	cout << a[i];
    cout<<ans;
	return 0;
}

