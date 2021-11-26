#include<iostream>
#include<string.h>
using namespace std;

typedef struct users {
    string user;
    string password;
    char haxi[5] = { 0 };
};

users U[1001];
int useing = 0;

string name, key;
char pat;
int len;
char ha[5] = { 0 };
int temp[4];

void unify() {
    for (int i = 0; i < len; i++)
        if (key[i] >= 'a' && key[i] <= 'z') key[i] -= 32;
}

void calulateArea() {
    int area = len / 4;
    int remainde = len % 4;
    for (int i = 0; i < 4; i++) {
        if (remainde > 0) {
            temp[i] = area + 1;
            remainde--;
        }
        else temp[i] = area;
    }
}

void haxiNum(int piece) {
    int g0 = temp[piece];
    int start = 0;
    int ans = 0;
    for (int i = 0; i < piece; i++) start += temp[i];
    for (int i = start; i < g0 + start; i++) {
        int b = key[i];
        if (b >= 'A' && b <= 'Z') b -= 55;
        else if (b >= '0' && b <= '9') b = b - '0';
        ans += b;
        ans = ans % 36;
    }
    if (ans >= 10) ans += 'A' - 10;
    else ans += '0';
    ha[piece] = ans;
}

bool doR() {
    for (int i = 0; i < useing; i++) {
        if (U[i].user == name) return false;
    }
    U[useing].user = name;
    calulateArea();
    unify();
    U[useing].password = key;
    for (int i = 0; i < 4; i++) {
        haxiNum(i);
        U[useing].haxi[i] = ha[i];
    }
    U[useing].haxi[4] = '\0';
    useing++;
    return true;
}

int doL() {
    calulateArea();
    unify();
    for (int i = 0; i < useing; i++) {
        if (U[i].user == name) {
            if (U[i].password == key) return 1;
            else {
                for (int i = 0; i < 4; i++)  haxiNum(i);
                if (strcmp(U[i].haxi, ha) == 0) return 2;
                else return 0;
            }
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    ha[4] = '\0';
    while (t--) {
        cin >> pat >> name >> key;
        len = key.length();
        if (pat == 'R') {
            if (doR()) cout << "Signed!" << endl;
            else cout << "Repeated!" << endl;
        }
        else if (pat == 'L') {
            int tem = doL();
            if (tem == 0)cout << "Failed!" << endl;
            else if (tem == 1) cout << "Success!" << endl;
            else if (tem == 2) cout << "Attention!" << endl;
        }
    }
}