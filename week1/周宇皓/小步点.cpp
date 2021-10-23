#include<bits/stdc++.h>
using namespace std;
int main() {
	int r, d, n;
    double sum1;
	cin >> r >> d >> n;
	if (fabs(n) > r)
		sum1 = 2 * sqrt(d*d + pow((fabs(n) - r), 2)) - r;
	else
		sum1 = 2 * fabs(d) - r;
	cout << fixed<<setprecision(2)<<sum1;
}
