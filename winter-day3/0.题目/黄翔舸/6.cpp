#include <iostream>
#include<algorithm>
using namespace std;

typedef struct {
	int d1;
	int d2;
	int qz; 
}xx;
int a[201];

bool bj(xx xx1, xx xx2) {
	return xx1.qz < xx2.qz;
}

void init() {
	for (int i = 0; i < 201; i++) {
		a[i] = i;
	}
}

int ss(int x) {
	int r = x;
	while (a[r] != r)
		r = a[r];
	return r;
}

int jr(int x, int y) {
	int fx = ss(x);
	int fy = ss(y);
	if (fx != fy) {
		a[fy] = fx;
		return 1;
	}
	return 0;
}

int main() {
	int n, e;
	while (cin >> n >> e) {
		xx xx[e];
		init();
		for (int i = 0; i < e; i++) {
			cin >> xx[i].d1 >> xx[i].d2>> xx[i].qz;
		}
		sort(xx, xx+ e, bj); 
		int cnt = 0, w_sum = 0; 
		for (int i = 0; i < e; i++) {
			if (jr(xx[i].d1, xx[i].d2)) {
				cnt++;
				w_sum += xx[i].qz;
			}
			if (cnt == n - 1)
				break;
		}
		if (cnt == n - 1)
			cout << w_sum << endl;
		else cout << "There is no minimum spanning tree." << endl;
	}

	return 0;
}

