#include <bits/stdc++.h>
using namespace std;
\

void hannuota(int n, string a, string b, string c) {
	if (n == 1)
		cout << a << "->" << c << endl;
	else {
		hannuota(n - 1, a, c, b);
		cout << a << "->" << c << endl;
		hannuota(n - 1, b, a, c);
	}


}

int main() {
	int n;
	cin >> n;
	string x, y, z;
	cin >> x >> y >> z;
	hannuota(n, x, y, z);

	return 0;
}