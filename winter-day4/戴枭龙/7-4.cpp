#include <bits/stdc++.h>
using namespace std;
int ma[10005][10005];
bool vis[10005][10005];

int dx[4] = {1, -1, 0, 0};

int dy[4] = {0, 0, 1, -1};
int m, n, sx, sy, ex, ey;
int Min = 65535;

struct Node {
	int x;
	int y;
	int sum;
	Node *p;
} s, e;
queue<Node *>q;

void bfs(Node *from, Node *to) {
	Node *ans = new Node;
	from->p = NULL;
	q.push(from);
	while (!q.empty()) {
		Node *temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int x1 = temp->x + dx[i], y1 = temp->y + dy[i];
			if (ma[x1][y1] != -1 && !vis[x1][y1]) {
				vis[x1][y1] = 1;
				Node *t = new Node;
				t->x = x1;
				t->y = y1;
				t->p = temp;
				t->sum += ma[x1][y1];
				q.push(t);
			}
		}
		if (temp->x == to->x && temp->y == to->y && temp->sum < Min) {
			Min = temp->sum;
			ans = temp;
		}
	}
	while (ans->p != NULL) {
		cout << "(" << ans->x << " " << ans->y << ")";
		ans = ans->p;
	}
	cout << "(" << from->x << " " << from->y << ")";
}

int main() {
	cin >> m >> n;
	cin >> sx >> sy >> ex >> ey;
	s.x = sx;
	s.y = sy;
	e.x = ex;
	e.y = ey;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> ma[i][j];
	bfs(&s, &e);
}