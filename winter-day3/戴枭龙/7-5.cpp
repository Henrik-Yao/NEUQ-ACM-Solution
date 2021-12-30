#include <iostream>
using namespace std;
int m[20005][20005], vis[2005][2005];
int flag = 1;

int dx[4] = {1, 0, -1, 0};

int dy[4] = {0, 1, 0, -1};

void search(int i, int j) {
	vis[i][j] = flag;
	for (int p = 0; p < 4; p++) {
		int x = i + dx[p];
		int y = j + dy[p];
		if (m[x][y] == 1 && vis[x][y] == 0)
			search(x, y);
	}
}

int main() {
	int m1, n;
	cin >> m1 >> n;
	for (int i = 1; i <= m1; i++)
		for (int j = 1; j <= n; j++)
			cin >> m[i][j];
	for (int i = 1; i <= m1; i++) {
		for (int j = 1; j <= n; j++) {
			if (m[i][j] == 1 && !vis[i][j]) {
				search(i, j);
				flag++;
			}
		}
	}
	cout << flag - 1;
	return 0;
}