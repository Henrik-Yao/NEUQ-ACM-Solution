#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m;
int a[N];
int main()
{
    while (cin >> n) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        sort(a, a + n);
        int flag0 = 1;
        for (int i = 0; i < n; i++) flag0 == 1 ? printf("%d", a[i]), flag0 = 0 : printf(" %d", a[i]);
        puts("");
        cin >> m;
        int flag = 1;
        for (int i = 0; i < m; i++) {
            int num;
            scanf("%d", &num);
            int l = 0, r = n - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (a[mid] >= num) r = mid;
                else l = mid + 1;
            }
            if (flag == 1) {
                flag = 0;
                if (a[l] == num) printf("%d", l + 1);
                else printf("0");
            } else {
                if (a[l] == num) printf(" %d", l + 1);
                else printf(" 0");
            }
        }
        puts("");
    }
    return 0;
}