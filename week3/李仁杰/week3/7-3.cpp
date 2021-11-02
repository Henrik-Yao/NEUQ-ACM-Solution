#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, p, l, flag = -1, ** a, ** visit;

void init(int i, int j) {
	if (i >= 0 && j >= 0 && i < n && j < m && a[i][j] != -1) a[i][j]++;
}

void search(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= m) return;
	if (visit[i][j]) return;
	visit[i][j] = 1;
	if (a[i][j] != 0) {
		return;
	}
	search(i, j + 1);
	search(i, j - 1);
	search(i + 1, j);
	search(i - 1, j);
	search(i - 1, j - 1);
	search(i - 1, j + 1);
	search(i + 1, j - 1);
	search(i + 1, j + 1);

}

int print(int c) {
	int ct = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == 1) cout << a[i][j];
			else {
				cout << -1;
				ct++;
			}
			cout << ' ';
		}
		cout << endl;
	}
	return ct;
}

int main() {
	cin >> n >> m >> p >> l;
	a = new int* [n];
	visit = new int* [n];
	for (int i = 0; i < n; i++) {
		visit[i] = new int[m] {0};
		a[i] = new int[m] {0};
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = 0;
	for (int i = 0; i < p; i++) {
		int j, k;
		cin >> j >> k;
		a[j][k] = -1;
		init(j - 1, k - 1);
		init(j - 1, k + 1);
		init(j + 1, k - 1);
		init(j + 1, k + 1);
		init(j, k - 1);
		init(j, k + 1);
		init(j - 1, k);
		init(j + 1, k);
	}
	for (int i = 0; i < l; i++) {
		int j, k;
		cin >> j >> k;
		if (a[j][k] == -1) {
			flag = 0;
			break;
		}
		if (visit[j][k] == 1) continue;
		search(j, k);
		if (print(i) == p) {
			flag = 1;
			break;
		}
		cout << endl;
	}
	if (flag == 1) cout << "You win";
	else if (flag == 0) cout << "You lose";
}