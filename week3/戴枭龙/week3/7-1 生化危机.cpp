#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int safe[N], gl[N][N];
int main() {
	int m, n, k, s, d, p, q, flag = 0;
	cin >> m >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> safe[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> p >> q;
		gl[p][q] = 1;
		gl[q][p] = 1;
	}
	cin >> s >> d;
	for (int i = 0; i < n; i++) {
		if (d == safe[i]) {
			flag = 1;
			break;
		}
	}
	if (!flag)
		printf("The city %d is not safe!", d);
	else {
		if (flag && gl[s][d]) {
			printf("The city %d can arrive safely!", d);
		} else
			printf("The city %d can not arrive safely!", d);

	}
	return 0;
}