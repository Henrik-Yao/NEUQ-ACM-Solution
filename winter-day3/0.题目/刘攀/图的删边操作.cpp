#include<bits/stdc++.h>
#include<iostream>
#include<map>
using namespace std;
map<int, map<int, int >>mp;
int main() {
	int n, m, k;
	cin >>n>> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		mp[a][b] = c;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		mp[a].erase(b);
	}
	for (auto i : mp) {
		int a = i.first;
		if (!i.second.empty()) cout << a << ":";
		for (auto j : i.second) {
			cout << "(";
			cout << a << "," << j .first<< "," << j.second;
			cout << ")";
		}
		if (!i.second.empty()) cout << endl;
	}
}
