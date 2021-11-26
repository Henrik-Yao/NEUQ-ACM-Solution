#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1000010;
int n, m;
char p[N], s[N];
int ne[N];
int main()
{
    int ans;
    cin >> s + 1 >> p + 1;
    m = strlen(s + 1), n = strlen(p + 1);
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1])
            j = ne[j];
        if (p[i] == p[j + 1])
            j++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i++) {
        while (j && s[i] != p[j + 1])
            j = ne[j];
        if (s[i] == p[j + 1])
            j++;
        if (j == n) {
            ans++;
            j = ne[j];
        }
    }
    cout << ans << endl;
    return 0;
}

