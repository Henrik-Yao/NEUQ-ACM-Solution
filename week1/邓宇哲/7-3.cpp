#include <iostream>
#include <iomanip>
#include  <cmath>
using namespace std;
main()
{
    double R, d, n;
    cin >> R >> d >> n;
    if(abs(n)-R>0)
    cout << fixed << setprecision(2) << 2 * (sqrt((abs(n) - R) * (abs(n) - R) + d * d)) - R;
    else cout << fixed << setprecision(2) <<2*abs(d)-R;
}
