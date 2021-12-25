/*#include<iostream>
using namespace std;

int main() {
    int a;
    while (cin >> a) {
        long long int ans[4] = { 0,1,2,4 };
        for (int i = 4; i <= a; i++) {
            ans[i % 4] = ans[(i + 1) % 4] + ans[(i + 2) % 4] + ans[(i + 3) % 4];
        }
        cout << ans[a % 4] << endl;
    }

}*/