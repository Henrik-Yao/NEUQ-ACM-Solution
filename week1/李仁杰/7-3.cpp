#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double r, d, n;
    cin >> r >> d >> n;
    r = fabs(r);
    d = fabs(d);
    n = fabs(n);
    if (n < r) printf("%.2lf", 2 * d - r);
    else printf("%.2lf", 2 * pow(d * d + (n - r) * (n - r), 0.5) - r);
}