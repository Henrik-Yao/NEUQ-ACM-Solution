#include<iostream>
#include<algorithm>
using namespace std;

int area[10086];
int m, n;

bool cmp(int a, int b) {
    return a > b;
}
int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) cin >> area[i];
    sort(area, area + m);
    int ans = area[m - 1] - area[0] + 1;
    for (int i = 1; i < m; i++) area[i - 1] = area[i] - area[i - 1] - 1;
    area[m - 1] = 0;
    sort(area, area + m - 1, cmp);
    n = n - 1;
    while (n--) {
        ans -= area[n];
    }
    cout << ans;
}