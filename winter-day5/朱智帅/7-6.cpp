#include<iostream>
#include<algorithm>
using namespace std;
int n, q, i, number[105];
void Find(int x)
{
	int left = 1, right = n, cnt = 0;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		//cout << mid << " " << number[mid] << endl;
		if (number[mid] == x)
		{
			cnt++;
			cout << mid;
			return;
		}
		else
		{
			cnt++;
			if (number[mid] < x) left = mid + 1;
			else right = mid - 1;
		}
	}
	cout << 0;
}
int main()
{
	while (cin >> n) {
		int x;
		
		for (i = 1; i <= n; i++) cin >> number[i];
		sort(number + 1, number + n + 1);
		cin >> q;
		cout << number[1];
		for (i = 2; i <= n; i++) cout << " " << number[i];
		cout << endl;
		cin >> x;
		Find(x);
		for (i = 2; i <= q; i++)
		{
			cin >> x;
			cout << " ";
			Find(x);

		}
        cout<<endl;
	}
	return 0;
}
