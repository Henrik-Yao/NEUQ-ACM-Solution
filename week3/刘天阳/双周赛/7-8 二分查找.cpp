#include <iostream>

using namespace std;

int main (){
	int n, a, k;
	bool f = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if(a >= k && f) {
			cout << i;
			f = 0;
		}
	}
	if(f) cout << n+1;
	
	return 0;
}
