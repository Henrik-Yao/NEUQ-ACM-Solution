#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k, * a, * b, be, en, flag = 0;
multimap<int, int> r;
set<int> s;

void serach(int f) {
	s.insert(f);
	for (auto it = r.find(f); it != r.end() && (*it).first == f; it++) {
		if (flag) return;
		if (s.find((*it).second) != s.end() || b[(*it).second] == 0) continue;
		if ((*it).second == en) {
			cout << "The city " << en << " can arrive safely!";
			flag = 1;
			return;
		}
		serach((*it).second);
	}
}

int main() {
	cin >> n >> m >> k;
	a = new int[n];
	b = new int[n] {};
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		b[num] = 1;
	}
	for (int i = 0; i < k; i++) {
		int c, d;
		cin >> c >> d;
		r.insert(make_pair(c, d));
		r.insert(make_pair(d, c));
	}
	cin >> be >> en;
	b[be] = 1;
	if (b[en] == 0) cout << "The city " << en << " is not safe!";
	else {
		serach(be);
		if (!flag) cout << "The city " << en << " can not arrive safely!";
	}

}