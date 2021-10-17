#include<iostream>
#include<string.h>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int r, n, d;
    cin >> r >> d >> n;
    if (r < 0)
        r = -r;
    if (d < 0)
        d = -d;
    if (n < 0)
        n = -n;
    float cd;
    if(n-r>=0)
    {cd = sqrt((d * d) + (n - r) * (n - r));}
    else
    {cd=d;}
    printf("%.2lf", (2 * cd - r));
}