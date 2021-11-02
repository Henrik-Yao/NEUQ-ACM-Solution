#include<iostream>
#include<set>
using namespace std;
int city[10001][2] = { 0 };
set<int>test;
bool judge(int n) {
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (test.find(city[i][0]) == test.end() && test.find(city[i][1]) == test.end()) {
            flag = false;
            break;
        } 
    }
    test.clear();
    return flag;
}
int main() {
    int n, m, p;
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> city[i][0] >> city[i][1];
    int a;
    cin >> a;
    while (a--) {
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
            cin >> p;
            test.insert(p);
        }
        if (judge(m)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}