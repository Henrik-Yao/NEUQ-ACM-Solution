#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, i, number[1000001];
void Find(int x)
{
	int left = 0, right = n - 1, cnt = 0;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		//cout << mid << " " << number[mid] << endl;
		if (number[mid] == x)
		{
			cnt++;
			cout << mid << endl;
			cout << cnt << endl;
			return;
		}
		else
		{
			cnt++;
			if (number[mid] < x) left = mid + 1;
			else right = mid - 1;
		}
	}
	cout << -1 << endl;
	cout << cnt << endl;
}
int main()
{
	
	cin >> n;
	for (i = 0; i <  n; i++) cin >> number[i];
	int x;
	cin >> x;
	Find(x);
}
