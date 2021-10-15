#include <iostream>

using namespace std;

int res = 1;

int func(int n) {
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            res++;
            func(i);
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    func(n);
    cout << res;
    return 0;
}

