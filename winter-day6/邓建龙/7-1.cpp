#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
const int N = 110;
int n;
int a[N];
int main()
{
    while (cin >> n) {
        vec.clear();
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        vec.push_back(a[0]);
        for (int i = 1; i < n; i++) {
            vec.push_back(a[i]);
            sort(vec.begin(), vec.end());
            for (int j = i + 1; j < n; j++) vec.push_back(a[j]);
            int flag = 1;
            for (auto &i : vec) {
                flag == 1 ? printf("%d", i), flag = 0 : printf(" %d", i);
            }
            puts("");
            for (int j = i + 1; j < n; j++) vec.pop_back();
        }
    }
    return 0;
}