#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[100010];
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            int j = i;
            while (j > 0 && a[j] < a[j - 1]) {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                j--;

            }
            for (int i = 0; i < n; i++) {
                if (i != 0)cout << " ";
                cout << a[i];
            }
            cout << endl;
        }
    }
    return 0;
}