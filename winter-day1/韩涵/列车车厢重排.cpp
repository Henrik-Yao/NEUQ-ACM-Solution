#include<iostream>
using namespace std;

int rail[101] = { 0 };
int rail1[101] = { 0 };
int main() {
    int num;
    cin >> num;
    rail[0] = num;
    int ra = 0, ra1 = -1;
    for (int i = 0; i < num; i++) rail[i] = num + 1;
    while (num--) {
        int box;
        cin >> box;
        if (box == rail[0]) {
            rail[0]--;
        }
        else {
            int i, flag = 1;
            for (int i = 1; i <= ra; i++) {
                if (rail[i] > box) {
                    rail[i] = box;
                    if (i == 1) rail1[++ra1] = box;
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                rail[++ra] = box;
                if (ra == 1) rail1[++ra1] = box;
            }
        }
    }
    for (int i = 0; i <= ra1; i++) {
        if (i > 0) cout << " ";
        cout << rail1[i];
    }
    cout << endl << ra;
}