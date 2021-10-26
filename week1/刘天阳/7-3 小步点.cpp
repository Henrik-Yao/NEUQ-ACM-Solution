#include <iostream>
#include <cmath>

using namespace std;

int main () {
	
	double n, d, r;
	
	cin >> r >> d >> n;
	
	d = abs(d), n = abs(n);
	if(r>=n) {
		printf("%.2f",max(2*d-r,0.0));
		return 0;
	}
		n -= r;
		printf("%.2f", sqrt(n * n + d * d) * 2 - r);
	
	
	
	return 0;
} 
