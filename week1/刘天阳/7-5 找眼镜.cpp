#include <iostream>
#include <string>

using namespace std;

const int S = 1e5+10;

string Sa[S];
bool Bc[S];

int main () {
	
	int n, m;
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) 	cin >> Bc[i] >> Sa[i];
	
	int l, ans = 1;
	bool c;
	
	for (int i = 1; i <= m; i++) {
		cin >> c >> l;
		if((Bc[ans] && c) || (!Bc[ans] && !c)) {
			ans -= l;
			while(ans <= 0) ans += n;
		}
		else {
			ans += l;
			ans %= n;
			if(!ans) ans = n;
		}
	}
	
	cout << Sa[ans];
	
	return 0;
}
