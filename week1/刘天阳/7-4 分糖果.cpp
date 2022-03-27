#include <iostream>

using namespace std;

int ans[1009];

int ChuLi(int a) {
	
	if(ans[a]) return ans[a];
	else {
		for (int i = 1; i < a; i++) {
			if(!(a%i)) ans[a] += ChuLi(i);
		}
		ans[a]++;
		return ans[a];
	}
	
}

int main() {
	
	int n;
	
	cin >> n;
	
	ans[0] = 1, ans[1] = 1;
	
	for (int i = 2; i <= n; i++) ChuLi(i);
	
	cout << ans[n];
	
	return 0;
}
