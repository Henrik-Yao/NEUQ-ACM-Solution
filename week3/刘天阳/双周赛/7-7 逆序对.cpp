#include <iostream>

using namespace std;

const int N = 1e6+9;
int a[N], ans[N];
long long sum = 0;

void gb(int s, int e) {
	int l = e-s+1;
	if(s == e) {
		ans[e] = a[e];
	}
	else if(s != e){
		int m = (s+e) / 2;
		gb(s, m), gb(m+1, e);
		int st = s, et = m+1, t = 0;
		while(st <= m || et <= e) {
			if(st <= m) {
				if(et <= e) {
					if(a[et] < a[st]) {
						sum += m-st+1; 
						ans[s+t] = a[et];
						t++, et++;
					}
					else {
						ans[s + t++] = a[st++];
					}
				}
				else for (;st <= m; st++) {
					ans[s + t ] = a[st];
					t++;
				}
			}
			else for (; et <= e; et++) {
				ans[s + t++ ] = a[et];
			}
		}
		for (int i = s; i <= s+t-1; i++) {
			 a[i] = ans[i];
		}
	}
}

int main(){
	int n;
	
	cin >> n;
	
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	gb(1, n);
	
	cout << sum;
	
	
	return 0;
}
