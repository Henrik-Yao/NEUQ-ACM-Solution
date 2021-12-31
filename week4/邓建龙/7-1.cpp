#include <iostream>

using namespace std;

int main()
{
    int arr[10010];
    for (int & i : arr) {
        i = 1;
    }
    arr[0] = arr[1] = 0;
    for (int i = 2; i < 10010; i++) {
        if (arr[i] == 1) {
            for (int j = i * i; j < 10010; j += i) {
                arr[j] = 0;
            }
        }
    }
    int from, to;
    int first = 1;
    while (cin >> from >> to) {
        for (int k = from; k <= to; k++) {
            if (arr[k] == 1) {
                if (first == 1) {
                    cout << k;
                    first = 0;
                } else {
                    cout << " " << k;
                }
            }
        }
        cout << endl;
        first = 1;
    }
    return 0;
}

