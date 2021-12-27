#include <bits/stdc++.h>
using namespace std;
stack<char>sta;

int main() {
	string s;
	int f = 1;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			sta.push(')');
		else if (s[i] == '{')
			sta.push('}');
		else if (s[i] == '[')
			sta.push(']');
		else if (sta.empty() || sta.top() != s[i])
			f = 0;
		else
			sta.pop();
	}
	if (!f)
		cout << "yes";
	else
		cout << "no";
	return 0;
}