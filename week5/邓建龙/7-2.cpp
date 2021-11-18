#include <iostream>
#include <cmath>

using namespace std;

bool check(int n)
{
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            cout << 2 << endl;
            continue;
        }
        if (check(arr[i])) {
            cout << 1 << endl;
            continue;
        }
        if (check(arr[i] - 2)) {
            cout << 2 << endl;
            continue;
        }
        cout << 3 << endl;
    }
    return 0;
}

