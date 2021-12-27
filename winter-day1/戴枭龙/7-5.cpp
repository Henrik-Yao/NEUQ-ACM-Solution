#include<bits/stdc++.h>
using namespace std;
vector<char>v;
int main() {
	string s;
	while (cin >> s) {
		v.clear();
		for (int i = 0; i < s.size(); i++) {
			if (v.empty())
				v.push_back(s[i]);
			else if (s[i] == ')' && v.back() == '(') {
				v.pop_back();
				continue;
			} else
				v.push_back(s[i]);
		}
		if (v.empty()) {
			cout << "Match"<<endl;
			continue;
		}
		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++)
			if (v[i] == ')')
				cout << "(";
		cout << s;
		for (int i = 0; i < v.size(); i++)
			if (v[i] == '(')
				cout << ")";
		cout << endl;
	}
	return 0;
}