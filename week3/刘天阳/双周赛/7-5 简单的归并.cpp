#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ans[209];

int main () {
	int t;
	int a, b;
	
	cin >> t;
	while(t--) {
		cin >> a;
		for (int i = 1; i <= a; i++) cin >> ans[i];
		
		cin >> b;
		for (int i = a+1; i <= a+b; i++) cin >> ans[i];
		
		sort(ans+1, ans+a+b+1);
		
		for (int i = 1; i <= a+b; i++) {
			cout << ans[i];
			
			if(i < a+b) cout << " ";
			else if(t) cout << endl;
		}
	}
	
	
	return 0;
}
