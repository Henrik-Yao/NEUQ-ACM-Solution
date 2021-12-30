#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, i, number[1001], cnt = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> number[i];
	}
	sort(number, number + n);
	for (i = 1; i < n; i++)
	{
		if (number[i] - number[i - 1] == 1) cnt++;
	}
	cout << cnt << endl;
	return 0;
}