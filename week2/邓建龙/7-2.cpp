#include <iostream>

using namespace std;

const int N = 1e4 + 10;

struct city {
    int a,b;
}citys[N];

int main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> citys[i].a >> citys[i].b;
    }
    int k;
    cin >> k;
    while (k--) {
        int all[N] = {0};
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int num;
            cin >> num;
            all[num] = 1;
        }
        int is = 1;
        for (int i = 0; i < m; i++) {
            if (all[citys[i].a] == 0 && all[citys[i].b] == 0) {
                is = 0;
                break;
            }
        }
        if (is) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

