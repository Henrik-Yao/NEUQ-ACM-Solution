#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n, * a, m = 0, temp = 0;
vector<int> v;

int main() {
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		temp += a[i];
		if (temp > m) m = temp;
		if (temp < 0) temp = 0;
	}
	cout << m;
}