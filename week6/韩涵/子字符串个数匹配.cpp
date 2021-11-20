/*#include<iostream>
#include<string>
using namespace std;

string text, patten;
int textLen, pattenLen;
string temp;
int KMPnext[1000001];

void buildNext() {
    int i = 2, j = 1;
    KMPnext[1] = 0;
    KMPnext[2] = 1;
    while (i < pattenLen) {
        if (j == 0 || patten[i - 1] == patten[j - 1]) {
            i++; j++;
            KMPnext[i] = j;
        }
        else j = KMPnext[j];
    }
}

int main() {
    getline(cin, text);
    getline(cin, patten);
    textLen = text.length();
    pattenLen = patten.length();
    buildNext();
    int i = 1, n = 1, ans = 0;
    bool flag = true;
    while (i <= textLen) {
        if (text[i] >= 'A' && text[i] <= 'Z') text[i] += 32;
        if (patten[n] >= 'A' && patten[n] <= 'Z') patten[n] += 32;
        if (text[i - 1] < 'a' || text[i - 1] > 'z') {
            n = 1;
            i++;
            flag = true;
            continue;
        }
        if (n == 0 || text[i - 1] == patten[n - 1]) {
            i++; n++;
            if (n == pattenLen + 1) {
                i--;
                if (flag) {
                    ans++;
                    flag = false;
                }
                n = KMPnext[n - 1];
            }
        }
        else n = KMPnext[n];
    }
    cout << ans;
}*/