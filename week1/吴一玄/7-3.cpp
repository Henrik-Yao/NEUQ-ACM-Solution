#include<bits/stdc++.h>
using namespace std;

double dis(double x1, double y1, double x2, double y2)
{
    double xx = (x2 - x1) * (x2 - x1);
    double yy = (y2 - y1) * (y2 - y1);
    return sqrt(xx + yy);
}

int main()
{
    double r, d, n;
    cin >> r >> d >> n;
    d = fabs(d), n = fabs(n);
    if(2.0 * d <= r)
    {
        if(dis(0, 0, d, n) <= r) {puts("0.00"); return 0;}
        printf("%.2f\n", dis(0, 0, d, n) - r);
        return 0;
    }
    if(dis(0, 0, d, n) <= r || n <= r)
    {
        printf("%.2f\n", 2.0 * d - r);
        return 0;
    }
    double s = dis(0, 0, d, n - r);
    printf("%.2f\n", 2.0 * s - r);
    return 0;
}