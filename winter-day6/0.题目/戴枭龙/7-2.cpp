#include <bits/stdc++.h>
using namespace std;
map<string, int>mp;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

int main() {
	int n, x;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> x;
		mp[s] = x;
	}
	vector< pair<string, int> > vec;
	for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		vec.push_back( pair<string, int>(it->first, it->second) );
	}
	sort(vec.begin(), vec.end(), cmp);
	for (auto it = vec.begin(); it != vec.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}