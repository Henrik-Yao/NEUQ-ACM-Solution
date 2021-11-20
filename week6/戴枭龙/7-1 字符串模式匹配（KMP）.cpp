#include <bits/stdc++.h>
using namespace std;
int nxt[100];
int cnt = 0;

void text_table(string p, int m) {
	nxt[0] = 0;
	int x = 1, now = 0;
	while (x < m) {
		if (p[now] == p[x]) {
			now++;
			nxt[x] = now;
			x++;
		} else if (now)
			now = nxt[now - 1];
		else
			nxt[x++] = 0;
	}
}

void search( string t, string p, int n, int m) {
	int i = 0, j = 0;
	while (i < n) {
		if (t[i] == p[j]) {
			i++;
			j++;
		} else if (j) {
			j = nxt[j - 1];
		} else
			i++;
		if (j == m) {
			cnt++;
			j = nxt[j - 1];
		}
	}

}

int main () {
	string text, pattern;
	cin >> text >> pattern;
	int n = text.length();
	int m = pattern.length();
	text_table(pattern, m);
	search(text, pattern, n, m);
	cout << cnt << endl;
	return 0;
}