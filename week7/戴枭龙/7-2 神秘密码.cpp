#include <bits/stdc++.h>
using namespace std;

string read() {
	int n;
	string s, p;
	char ch;
	while (cin >> ch) {
		if (ch == '[') {
			cin >> n;
			p = read();
			for (int i = 0; i < n; i++)
				s += p;
		} else if (ch == ']')
			return s;
		else
			s += ch;
	}
}

int main() {
	cout << read();
	return 0;
}
