#include<iostream>
#include<algorithm>
using namespace std;
int a[110000] = {}, n;
int main() {
	while (cin >> n) {
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
	}
	return 0;
}
