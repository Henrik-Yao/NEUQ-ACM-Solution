#include <iostream>
#include <vector>
using namespace std;

string s;

void f(string s1) {
	int res = 0, l = s1.length();
	for (int i = 0; i + l <= s.length(); i++) {
		if(s1 == s.substr(i, l)) res++;
	}
	cout << res << endl;
}

int main() {
	int n;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		string s1;
		cin >> s1;
		f(s1);
	}
}