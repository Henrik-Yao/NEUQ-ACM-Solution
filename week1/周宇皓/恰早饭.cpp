#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, t,v,t1,max,s;
	cin >> n >> t;
	max = -10000;
	while (n--) {
		cin >> v >> t1;
		if (t1 > t) {
			s = v + t - t1;
		}
		else
			s = v;
		if (s > max)
			 max=s;
	}
	cout << max;
}
