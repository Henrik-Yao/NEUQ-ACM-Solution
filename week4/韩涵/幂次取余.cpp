/*#include<iostream>
#include<math.h>
using namespace std;
typedef unsigned long long ull;
int main() {
    int n;
    cin >> n;
    while (n--) {
        ull a, b, c;
        ull ans = 1;
        cin >> a >> b >> c;
        while (b != 1) {
            a = a % c;
            ans = ans * pow(a, b % 2);
            a = a * a;
            b = b / 2;
            ans = ans % c;
        }
        ans = (ans * a) % c;
        cout << ans << endl;
    }
}*/