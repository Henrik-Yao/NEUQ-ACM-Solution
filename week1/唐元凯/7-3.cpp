#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {
	int R, d, n;
	cin >> R >> d >> n;
	double result;
	d = abs(d);
	n = abs(n);
	if (n <= R)result = 2* d-R;
	else result = 2 * sqrt(d * d + (n-R) * (n-R)) - R;
	cout <<fixed<<setprecision(2)<<result;
}