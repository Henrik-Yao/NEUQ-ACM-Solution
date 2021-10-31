#include <bits/stdc++.h>
using namespace std;
#define number 1000001
int v[number], a[number], v2[number];

int main() {
	int n, count = 0, count2 = 0, tmp = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++) {
		if (v[a[i]] == 0)
			count++;
		v[a[i]]++;
	}
	for (int j = 1; j <= n; j++) {
		if (v[a[j]] == 1)
			count--;
		v[a[i]]--;
		if (v2[a[j]] == 0)
			count2++;
		v2[a[j]]++;

		tmp = max(tmp, count + count2);
	}
	cout << tmp;
}
