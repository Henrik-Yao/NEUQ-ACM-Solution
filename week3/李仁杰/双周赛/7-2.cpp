#include <iostream>
using namespace std;
string name[3];

void han(int n, int b, int t, int e) {
    if (n == 1) {
        cout << name[b] << "->" << name[e] << endl;
        return;
    }
    han(n - 1, b, e, t);
    cout << name[b] << "->" << name[e] << endl;
    han(n - 1, t, b, e);
}

using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < 3; i++) cin >> name[i];
    han(n, 0, 1, 2);
}