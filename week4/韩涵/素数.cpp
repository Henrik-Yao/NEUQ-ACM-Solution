/*#include<iostream>
#include<math.h>
using namespace std;
int temp[10001];

int main() {
    int a, b;
    temp[0] = 2;
    temp[1] = 3;
    int t = 1;
    while (cin >> a >> b) {
        for (int max = temp[t] + 2; max < b; max+=2) {
            bool flag = false;
            for (int j = 0; j < t && temp[j] <= sqrt(max); j++) {
                if (max % temp[j] == 0) {
                    flag = true;
                    break;
                }
            }
            if (!flag) temp[++t] = max;
        }
        for (int i = 0; i <= t; i++) {
            if (temp[i] > b) break;
            if (temp[i] >= a) cout << temp[i] << " ";
        }
        cout << endl;
    }
}*/