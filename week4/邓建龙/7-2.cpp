#include <iostream>

using namespace std;

int n, m;

int main()
{
    int N = 41;
    int arr[N];
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 2;
    for (int i = 4; i <= 41; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        i != n - 1 ? cout << arr[m] << endl : cout << arr[m];
    }
    return 0;
}

