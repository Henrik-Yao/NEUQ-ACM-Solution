#include<bits/stdc++.h>
using namespace std;

int main() {
	int r, d, n;
	double res;
	cin >> r >> d >> n;
	if(fabs(n) <= r){
		res = 2 * fabs(d) - r;
	}
	else
		res = 2 * sqrt(d*d+(fabs(n)-r)*(fabs(n)-r))-r;
	printf("%.2f", res);
	
}
