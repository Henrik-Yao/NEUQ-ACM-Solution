#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int a, b;
int all[10001]{};
set<int> zhi;

void search() {
	for (int i = 2; i <= b; i++) {
		if (all[i] == 0) {
			zhi.insert(i);
		}
		for (int j = 2; j <= i; j++) {
			if (i * j <= 10000) all[j * i] = 1;
			else continue;
		}
	}
	auto itend = --zhi.end();
	for (auto it = zhi.begin(); it != itend; it++) {
		if (*it < a) continue;
		cout << *it << ' ';
	}
	cout << *itend << endl;
	zhi.clear();
}

int main() {
	while (cin >> a >> b) {
		search();
	}
}