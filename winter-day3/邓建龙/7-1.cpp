#include <bits/stdc++.h>
using namespace std;
const int N = 20010;
vector<pair<int, int>> gh[N];
bool has[N];
int n, e, a, b, c;
void quick_sort(int l, int r, int idx)
{
    if (l >= r) return;
    int x = gh[idx][l + r >> 1].first, i = l - 1, j = r + 1;
    while (i < j) {
        do {i++;} while (gh[idx][i].first < x);
        do {j--;} while (gh[idx][j].first > x);
        if (i < j) swap(gh[idx][i], gh[idx][j]);
    }
    quick_sort(l, j, idx), quick_sort(j + 1, r, idx);
}
int main()
{
    memset(has, false, sizeof has);
    ios::sync_with_stdio(false);
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        has[a] = true;
        gh[a].push_back({b, c});
    }
    for (int i = 0; i < n; i++) {
        if (has[i]) quick_sort(0, gh[i].size() - 1, i);
    }
    for (int i = 0; i < n; i++) {
        if (has[i]) {
            printf("%d:", i);
            for (int j = 0; j < gh[i].size(); j++) {
                printf("(%d,%d,%d)", i, gh[i][j].first, gh[i][j].second);
            }
            printf("\n");
        }
    }
    return 0;
}