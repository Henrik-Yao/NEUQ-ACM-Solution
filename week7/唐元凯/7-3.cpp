#include<iostream>
#include<string>
#include<set>

using namespace std;

int main() {
	set<char>c;
	string s, e;
	while (getline(cin, s)) {
		getline(cin, e);
		for (auto a : e) {
			c.insert(a);
		}
		for (auto a : s) {
			if (!c.count(a))cout << a;
		}
		cout << endl;
		c.clear();
	}
}
