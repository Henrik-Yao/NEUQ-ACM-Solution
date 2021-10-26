#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double R, d, n;
	cin >> R >> d >> n;
	cout << setiosflags(ios::fixed) << setprecision(2);
	if (n >= R && n > 0) cout << 2 * sqrt(d * d + (n - R) * (n - R)) - R;
	else if ((-n >= R && n < 0)) cout << 2 * sqrt(d * d + (n + R) * (n + R)) - R;
	else cout << 2 * d - R;
	return 0;
}