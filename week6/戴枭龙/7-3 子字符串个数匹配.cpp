#include <bits/stdc++.h>
using namespace std;
string t[10000];
int cnt = 0, cnt2 = 0;

void find(string t, string p) {
	int n = t.length();
	int m = p.length();
	int i = 0, j = 0;
	while (i < n - m + 1) {
		if (t.substr(i, m) == p) {
			cnt2++;
			break;
		}
		i++;
	}
}

int main() {
	string text, pattern;
	getline(cin, text);
	getline(cin, pattern);
	int n = text.length();
	int m = pattern.length();
	for (int i = 0; i < n; i++) {
		if (text[i] >= 'A' && text[i] <= 'Z')
			text[i] = text[i] + 32;
	}

	for (int i = 0; i < m; i++) {
		if (pattern[i] >= 'A' && pattern[i] <= 'Z')
			pattern[i] = pattern[i] + 32;
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		while (text[i + k] >= 'a' && text[i + k] <= 'z') {
			k++;
		}
		if (k > 0) {
			t[cnt++] = text.substr(i, k);
			i = i + k - 1;
			k = 0;

		}
	}
	for (int i = 0; i < cnt; i++) {
		find(t[i], pattern);
	}
	cout << cnt2 << endl;
	return 0;
}