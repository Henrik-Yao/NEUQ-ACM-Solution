#include <iostream>
using namespace std;
main()
{
    long long sign[41] = {0, 0,1,2};
    for (int i = 4; i <= 40;i++)
    {
        sign[i] = sign[i - 1] + sign[i - 2];
    }
        int n;
    cin >> n;
    for (int p = 0; p < n;p++)
    {
        int a;
        cin >> a;
        cout << sign[a]<<endl;
    }
}