#include <bits/stdc++.h>
using namespace std;
long long arr[50];

int main() {

	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= 41; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int n;
	cin >> n;
	while (--n > 0) {
		int t;
		cin >> t;
		cout << arr[t] << endl;
	}
	int t;
	cin >> t;
	a
	cout << arr[t];
	return 0;
}