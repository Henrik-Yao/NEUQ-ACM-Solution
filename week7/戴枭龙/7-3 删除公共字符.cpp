#include <bits/stdc++.h>
using namespace std;
map<char, int >a[1000];

int main() {
	int cnt = 0;
	string text, pattern;
	while (getline(cin, text) && getline(cin, pattern)) {
		for (int i = 0; i < pattern.length(); i++)
			a[cnt][pattern[i]] = 1;
		for (int i = 0; i < text.length(); i++) {
			if (a[cnt][text[i]] != 1)
				cout << text[i];
		}
		cnt++;
		cout << endl;
	}
	return 0;
}