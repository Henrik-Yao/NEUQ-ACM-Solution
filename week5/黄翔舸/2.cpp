
#include<iostream>
#include<cmath>

using namespace std;

bool isprime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, x;
    cin >> n;
    while (n--) {
        cin >> x;
        if (!(x & 1)) {
            cout << 2 << endl;
        }
        else {
            if (isprime(x)) {
                cout << 1 << endl;
            }
            else if (isprime(x - 2)) {
                cout << 2 << endl;
            }
            else {
                cout << 3 << endl;
            }
        }
    }
    return 0;
}
