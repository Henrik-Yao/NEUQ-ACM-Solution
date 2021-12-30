#include<iostream>
using namespace std;
int age[51];
int main() {
    int n;
    int a;
    int i = 0;
    cin >> n;
    while (n--) {
        cin >> a;
        age[a]++;
    }
    for (; i <= 50; i++)
        if (!age[i])
            continue;
        else
            cout << i << ":" << age[i] << endl;
    return 0;
}