
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double a, b, c;

int t;
int main()
{
    cin >> c >> a >> b;
    b = fabs(b);
    if (b >= c) cout << setiosflags(ios::fixed) << setprecision(2) << (2.0 * sqrt(a * a + (b - c) * (b - c)) - c);
    else
        cout << setiosflags(ios::fixed) << setprecision(2) << (2 * a - c);
    return 0;
}