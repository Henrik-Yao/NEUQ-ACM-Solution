#include <bits/stdc++.h>
using namespace std;
int a[100005];
int m[50];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	for (int i = 0; i < 50; i++) {
		if (m[i] > 0) {
			cout << i << ":" << m[i] << endl;
		}
	}
	return 0;
}