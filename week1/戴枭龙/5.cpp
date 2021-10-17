#include <iostream>
using namespace std;
int n, m, pos = 1, a, b;

struct club {
	int pos;  //朝向（0朝向圈内，1朝向圈外）
	char p[100];
}
club1[100001];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> club1[i].pos >> club1[i].p;
	}
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		if (a == club1[pos].pos) {
			pos = (pos + n - b - 1) % n + 1;
			continue;
		}
		if (a != club1[pos].pos) {
			pos = (pos + b - 1) % n + 1;
			continue;
		}
	}
	cout << club1[pos].p;



	return 0;
}
