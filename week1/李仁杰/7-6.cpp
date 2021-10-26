#include <iostream>
#include <cmath>
#include <vector>
#define INT_MIN -2147483648
using namespace std;

int main() {
	int n, T, m = INT_MIN;
	cin >> n >> T;
	for (int i = 0; i < n; i++) {
		int v, t;
		cin >> v >> t;
		if (t > T) m = max(m, v - t + T);
		else m = max(m, v);
	}
	cout << m;
}