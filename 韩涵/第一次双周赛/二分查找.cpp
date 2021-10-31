/*#include <iostream>
using namespace std;
int main() {
    int a, b;
    int aa[1000001];
    cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        cin >> aa[i];
    }
    int fir = 1, las = a;
    while (fir <= las) {
        int temp = (fir + las) / 2;
        if (aa[temp] >= b) {
            for (int i = temp - 1; i >= 1; i--) {
                if (aa[i] >= b) temp = min(temp, i);
            }
            cout << temp << endl;
            break;
        }
        else fir = temp + 1;
    }
    if (fir > las) cout << a + 1 << endl;
    return 0;
}*/