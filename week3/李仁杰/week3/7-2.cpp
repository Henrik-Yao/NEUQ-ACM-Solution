#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, be, en, flag = 1, ar[500]{};
vector<int> v[500];

int search(int i) {
	if (ar[i] != 0) return ar[i];
	if (v[i].size() == 0) flag = 0;
	for(int j = 0; j < v[i].size(); j++) {
		ar[i] += search(v[i][j]);
	}
	return ar[i];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	cin >> be >> en;
	ar[en] = 1;
	search(be);
	if (flag && m)cout << ar[be] << " Yes";
	else cout << ar[be] << " No";
}