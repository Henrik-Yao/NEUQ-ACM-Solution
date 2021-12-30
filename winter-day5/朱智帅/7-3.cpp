#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	int n, i, number[1000001];
	cin >> n;
	for (i = 0; i < 2 * n; i++) cin >> number[i];
	sort(number, number + 2 * n);
	cout << number[(2 * n - 1) / 2] << endl;
}