#include <iostream>

using namespace std;

long long func(int n)
{
    if (n == 1) return 2;
    return func(n - 1) * 3 + 2;
}

int main()
{
    int n;
    while (cin >> n) {
        long long res = func(n);
        cout << res << endl;
    }
    return 0;
}