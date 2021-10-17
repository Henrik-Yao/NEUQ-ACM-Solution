#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int R,d,n;
    cin >> R >> d >> n;
    if (d < 0) {
        d = -1 * d;
    }
    if (n < 0) {
        n = -1 * n;
    }
    double res;
    if (R > n) {
        res = 2.0 * d - R;
        printf("%.2f",res);
    } else {
        res = 2.0 * sqrt(pow(n - R,2) + pow(d,2)) - R;
        printf("%.2f",res);
    }
    return 0;
}

