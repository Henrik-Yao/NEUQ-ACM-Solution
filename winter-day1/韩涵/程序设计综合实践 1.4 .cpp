/*
#include<iostream>
#include<algorithm>
using namespace std;

int a[100010];
int dan[10001];
int shuang[10001];

int main() {
    int i;
    for (i = 0; cin >> a[i]; i++);
    sort(a, a + i);
    int lend = 0, lens = 0;
    for (int j = 0; j < i; j++) {
        if (j > 0)cout << "->";
        cout << a[j];
        if (a[j] % 2 != 0) {
            dan[lend] = a[j];
            lend++;
        }
        else {
            shuang[lens] = a[j];
            lens++;
        }
    }
    cout << endl;
    for (int j = 0; j < lend; j++) {
        if(j > 0)cout << "->";
        cout << dan[j];
    }
    cout << endl;
    for (int j = 0; j < lens; j++) {
        if (j > 0)cout << "->";
        cout << shuang[j];
    }

}
*/