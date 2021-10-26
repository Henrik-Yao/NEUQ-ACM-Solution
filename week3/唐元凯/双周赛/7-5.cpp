#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int>a; a.reserve(100);
	while (N--) {
		a.clear();
		int m, temp; cin >> m;
		while (m--) {
			cin >> temp;
			a.push_back(temp);
		}
		cin >> m;
		while (m--) {
			cin >> temp;
			a.push_back(temp);
		}
		sort(a.begin(), a.end());
		for (auto& c : a) {
			cout << c;
			if (&c != &a.back())cout << " ";
		}
		cout << '\n';
	}
}