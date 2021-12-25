#include<iostream>
#include<algorithm>
using namespace std;

int line[10086];
int m, n;

bool judge(int a, int b) {
    return a > b;
}
int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> line[i];
    sort(line, line + m);
    int ans = line[m - 1] - line[0] + 1;
    for (int i = 1; i < m; i++) line[i - 1] = line[i] - line[i - 1] - 1;
    line[m - 1] = 0;
    sort(line, line + m - 1, judge);
    n = n - 1;
    while (n--) {
        ans -= line[n];
    }
    cout << ans;
}