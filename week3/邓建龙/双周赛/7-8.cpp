#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int q[n];
    int is = 0,index;
    for (int i = 0; i < n; i++) {
        cin >> q[i];
        if (q[i] >= m && is == 0) {
            is = 1;
            index = i + 1;
        }
    }
    if (is == 1) {
        cout << index << endl;
    } else {
        cout << n + 1 << endl;
    }
    return 0;
}