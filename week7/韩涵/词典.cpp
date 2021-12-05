#include<iostream>
using namespace std;

typedef struct dictionary {
    string word;
    string translation;
};

dictionary dic[100001];
string need;
int a, b;

void translate() {
    for (int i = 0; i < a; i++) {//Öð¸ö±©Á¦Æ¥Åä
        if (need == dic[i].translation) {
            cout << dic[i].word << endl;
            return;
        }
    }
    cout << "eh" << endl;
}

int main() {
    cin >> a >> b;
    for (int i = 0; i < a; i++) cin >> dic[i].word >> dic[i].translation;
    while (b--) {
        cin >> need;
        translate();
    }
}