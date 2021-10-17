#include <iostream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int main() {
	int n , ma = 0, all = 0;
	cin >> n;
	int* t = new int[n]{}, *a = new int[n];
	map<int, int> m;
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (m.find(a[i]) == m.end()) {
			t[i]++;
			all++;
			m.insert(make_pair(a[i], i));
		}
		else {
			t[(*m.find(a[i])).second]++;
		}
	}
	for (int i = 0; i < n; i++) {
		s.insert(a[i]);
		if (!(--t[(*m.find(a[i])).second])) all--;
		int now = s.size() + all;
		ma = max(ma, now);
	}
	cout << ma;
}