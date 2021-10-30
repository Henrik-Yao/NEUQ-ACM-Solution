#include <bits/stdc++.h>
using namespace std;
int a[100001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max1 = 0, temp = 0;
	for (int i = 0; i < n; i++) {
		temp += a[i];
		if (temp < 0)
			temp = 0;
		else {
			if (temp > max1)
				max1 = temp;
		}

	}
	cout << max1;

	return 0;
}