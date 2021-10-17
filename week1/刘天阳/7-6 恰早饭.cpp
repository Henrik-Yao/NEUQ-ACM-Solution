#include <iostream>

using namespace std;

int main () {
	
	int tim, n;
	int t, v;
	int ans;
	
	cin >> n >> tim;
	
	cin >> v >> t;
	
	if(t > tim) ans = v - (t - tim);
	else ans = v;
	
	for (int i = 1; i < n; i++) {
		cin >> v >> t;
		
		if(t > tim) ans = max(ans,v - (t - tim));
			else ans = max(ans,v);
	
	}
	
	cout << ans;
	
	return 0;
}
