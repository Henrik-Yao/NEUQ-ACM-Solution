#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 0;
int all[10000001]{};
vector<int> zhi;

int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (all[i] == 0) {
			zhi.push_back(i);
			ans++;
		}
		for (int j = 0; j < zhi.size() && zhi[j] <= i; j++) {
			if (i * zhi[j] <= n) all[zhi[j] * i] = 1;
			else break;
		}
	}
	cout << ans;
}