/*include<iostream>
using namespace std;

bool num[100000001] = { false };
int prime[100000001] = { 0 };
int question[100000001];

void primenum(int n) {
    int pos = 2;
    for (int i = 2; i <= n; i++) {
        if (!num[i]) prime[pos++] = i;
        for (int j = 2; j < pos && i * prime[j] <= n; j++) {
            num[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    int t, max = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> question[i];
        max = max > question[i] ? max : question[i];
    }
    primenum(max);
    for (int i = 0; i < t; i++) {
        int temp = question[i];
        if (temp % 2 == 0) {
            if (temp == 2) cout << '1' << endl;
            else cout << '2' << endl;
            continue;
        }
        if (!num[temp]) cout << '1';
        else {
            if (!num[temp - 2]) cout << '2';
            else cout << '3';
        }
        cout << endl;
    }
}*/