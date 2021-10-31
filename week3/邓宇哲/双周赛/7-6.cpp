#include <algorithm>
#include <iostream>
using namespace std;
main()
{
    string a;
    cin >> a;
    sort(a.begin(), a.end());
    int l = a.length(), sum = 1;
    for (int i = 1; i <= l; i++)
    {
        sum *= i;
    }
    for (int i = 0; i < sum; i++)
    {

        cout << a << endl;
        next_permutation(a.begin(), a.end());
    }
}
