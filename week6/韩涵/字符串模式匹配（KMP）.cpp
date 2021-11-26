/*#include<iostream>
#include<string.h>
using namespace std;

string text, patten;
int textLen, pattenLen;
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
    cin >> text >> patten;
    textLen = text.length();
    pattenLen = patten.length();
    buildNext();
    int i = 1, n = 1,ans = 0;
    while(i <= textLen) {
        if (n == 0 || text[i - 1] == patten[n - 1]) {
            i++; n++;
            if (n == pattenLen + 1) {
                i--;
                ans++; 
                n = KMPnext[n - 1];
            }
        }
        else n = KMPnext[n];
    }
    cout << ans;
}*/