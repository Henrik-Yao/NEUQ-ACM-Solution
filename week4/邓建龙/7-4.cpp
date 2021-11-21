#include <iostream>

using namespace std;

long long pow(long long a, long long b, long long c)
{
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = res * a % c;
        }
        b /= 2;
        a = a * a % c;
    }
    return res;
}

int main()
{
    long long n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        cout << pow(a, b, c) << endl;
    }
    return 0;
}

