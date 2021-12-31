/*
#include<iostream>
using namespace std;

int bag[1505];
int weight[405];
int price[405];

int main() {
    int n, c;
    while (cin >> n >> c) {
        for (int i = 1; i <= n; i++) cin >> weight[i];
        for (int i = 1; i <= n; i++) cin >> price[i];
        for (int i = 0; i < n; i++) bag[i] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = c; j >= weight[i]; j--) {
                bag[j] = bag[j] > bag[j - weight[i]] + price[i] ? bag[j] : bag[j - weight[i]] + price[i];
            }
        }
        int ans = bag[c];
        cout << ans << endl;
        for (int i = 0; i <= c; i++) bag[i] = 0;
    }

}
*/