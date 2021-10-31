#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
//STL版本
/*
int main() {
	ios::sync_with_stdio(false);
	vector<int>num; num.reserve(1000000);
	int n, m;
	cin >> n >> m;
	int temp;
	for (size_t i = 0; i < n; i++)
	{
		cin >> temp;
		num.push_back(temp);
	}
	if (num.back()>=m) {
		cout << lower_bound(num.begin(), num.end(), m)-num.begin()+1;
	}
	else cout << n + 1;
}
*/

//普通版本
/*
int num[1000005];
int lower_bound(int* A, int x, int y, int v) {
	int m;
	while (x < y)
	{
		m = x + (y - x) / 2;
		if (A[m] >= v)y = m;
		else x = m + 1;
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (size_t i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	if (num[n - 1] >= m)cout << 1 + lower_bound(num, 0, n - 1, m);
	else cout << n + 1;
}
*/