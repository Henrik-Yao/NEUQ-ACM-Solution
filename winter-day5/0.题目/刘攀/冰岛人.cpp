#include<iostream>
#include<string.h>
#include<map>
#include<string>
using namespace std;
struct people {
	char sex;
	string father;
};
map<string, people>mp;
int judge(string a, string b) {
	int i = 1, j;
	for (string A = a; !A.empty(); A = mp[A].father, i++) {
		j = 1;
		for (string B = b; !B.empty(); B = mp[B].father, j++) {
			if (i >= 5 && j >= 5) return 1;
			if (A == B && (i < 5 || j < 5)) return 0;
		}
	}
	return 1;
}
int main() {
	int n;
	cin >> n;
	string a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (b.back() == 'r') {
			mp[a] = { 'f',b.substr(0,b.size() - 7) };
		}
		else if (b.back() == 'n') {
			mp[a] = { 'm',b.substr(0,b.size() - 4) };
		}
		else {
			mp[a].sex = b.back();
		}
	}
	int m;
	cin >> m;
	string str;
	for (int i = 0; i < m; i++) {
		cin >> a >> str >> b >> str;
		if (mp.find(a) == mp.end() || mp.find(b) == mp.end()) {
			cout << "NA" << endl;
		}
		else if (mp[a].sex == mp[b].sex) {
			cout << "Whatever" << endl;
		}
		else {
			if (judge(a, b)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}
