#include <iostream>
#include <string>

using namespace std;

int main (){
	
	string m, a;
	int n;
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		
		cin >> a;
		
		int ml = m.size(), al = a.size();
		
		for (int j = 0; j <= ml - al; j++) {
			bool ju = 1;
			for (int k = 0; k < al; k++) {
				if(m[j+k] != a[k]) {
					ju = 0;
					break;
				}	
			}
			if(ju) ans ++;
		}
		cout << ans;
		if(i != n) cout << endl;
	}
	
	
	return 0;
}
