#include <iostream>

using namespace std;

int a[1000009], ans[1000009];

void gb(int s, int e) {
	int n = e - s + 1;
	if(n == 2) {
		int maxx = max(a[s], a[e]), minn = min(a[s], a[e]);
		a[s] = minn, a[e] = maxx;
		ans[s] = minn, ans[e] = maxx;
	}
	
	else if(n == 1)	ans[s] = a[s];
	
	else {
		int m = s + (e-s)/2;
		
	
		
		gb(s, m - 1), gb(m, e);
		
		
		int t = 0, st = s, mm = m;
		while(t < n) {
			if(s <= mm-1) {
				if(m <= e) {
					if(a[s] > a[m]) {
						ans[st+t] = a[m];
						m ++, t ++;
					}
					else {
						ans[st+t] = a[s];
						s ++, t ++;
					}
				}
				else for (int i = s; i < e; i++, t++) ans[st+t] = a[i];
			}
			else 
				for (int i = m; i <= e; i++, t++) 	ans[st+t] = a[i];
				
			}
		for (int i = st; i <= e; i++) a[i] = ans[i];
		}
	}


int main (){
	
	int n;
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	gb(1, n);
	
	
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	
	return 0;
}
