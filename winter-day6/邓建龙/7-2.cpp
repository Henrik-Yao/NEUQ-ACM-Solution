#include <bits/stdc++.h>
using namespace std;
struct Bnode {
    char name[23];
    int s;
};
int n;
int main()
{
    cin >> n;
    Bnode man[n];
    ios::sync_with_stdio(false);
    for (int i = 0; i < n; i++) {
        cin >> man[i].name >> man[i].s;
    }
    for (int i = 1; i < n; i++) { // 后
        for (int j = 0; j < i; j++) { // 前
            if (man[i].s > man[j].s || (man[i].s == man[j].s && strcmp(man[i].name, man[j].name) < 0)) swap(man[i], man[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << man[i].name << " " << man[i].s << endl;
    }
    return 0;
}