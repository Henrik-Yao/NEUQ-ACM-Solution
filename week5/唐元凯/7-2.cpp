#include<iostream>
#include<cmath>

using namespace std;

bool isprime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, temp;
    cin >> N;
    while (N--) {
        cin >> temp;
        if (!(temp & 1)) {
            cout << 2 << endl;
        }
        else {
            if (isprime(temp))cout << 1 << endl;
            else if (isprime(temp - 2))cout << 2 << endl;
            else cout << 3 << endl;
        }
    }
}
