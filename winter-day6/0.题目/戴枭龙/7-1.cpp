#include <bits/stdc++.h>
using namespace std;

void InsertSort(vector<int> &v) {
	for (int i = 1; i < v.size(); i++) {
		int temp = v[i];
		int j;
		for (j = i - 1; j >= 0 && temp < v[j]; j--) {
			v[j + 1] = v[j];
		}
		v[j + 1] = temp;
		for (int j = 0; j < v.size(); j++) {
			cout << v[j];
			if (j == v.size() - 1)
				cout << endl;
			else
				cout << " ";
		}
	}
}

int main() {
	int n;
	while (cin >> n) {
		vector<int>a;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		InsertSort(a);
	}
	return 0;
}