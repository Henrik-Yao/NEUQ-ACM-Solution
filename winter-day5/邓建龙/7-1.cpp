#include <bits/stdc++.h>
using namespace std;
int a[1010];
int has[1010];
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1] + 1) has[i] = 1;
        else {
            if (a[i] == a[i - 1] && has[i - 1] == 1) has[i] = 1;
        }
    }
    int total = 0;
    for (int i = 1; i < n; i++) if (has[i] == 1) total++;
    cout << total << endl;
    return 0;
}