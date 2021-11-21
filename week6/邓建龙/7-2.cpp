#include <iostream>
#include <map>

using namespace std;
int n;
map<string, string> users;
map<string, int> hashs;

int getHash(string s) {
    int len = s.length();
    int nums[len];
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') nums[i] = s[i] - 'A' + 10;
        if (s[i] >= 'a' && s[i] <= 'z') nums[i] = s[i] - 'a' + 10;
        if (s[i] >= '0' && s[i] <= '9') nums[i] = s[i] - '0';
    }
    int l1 = 0, l2 = 0, l3 = 0, l4 = 0;
    if (len % 4 == 0)
        l1 = l2 = l3 = l4 = len / 4;
    if (len % 4 == 1)
        l1 = len / 4 + 1, l2 = l3 = l4 = len / 4;
    if (len % 4 == 2)
        l1 = l2 = len / 4 + 1, l3 = l4 = len / 4;
    if (len % 4 == 3)
        l1 = l2 = l3 = len / 4 + 1, l4 = len / 4;
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
    for (int i = 0; i < l1; i++) a1 += nums[i];
    for (int i = l1; i < l1 + l2; i++) a2 += nums[i];
    for (int i = l1 + l2; i < l1 + l2 + l3; i++) a3 += nums[i];
    for (int i = l1 + l2 + l3; i < l1 + l2 + l3 + l4; i++) a4 += nums[i];
    a1 %= 36, a2 %= 36, a3 %= 36, a4 %= 36;
    return ((((a1 * 36) + a2) * 36) + a3) * 36 + a4;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char Type;
        string Name, Pwd;
        cin >> Type >> Name >> Pwd;
        if (Type == 'R') {
            if (users.count(Name)) {
                cout << "Repeated!" << endl;
                continue;
            }
            users[Name] = Pwd;
            hashs[Name] = getHash(Pwd);
            cout << "Signed!" << endl;
        } else {
            if (users[Name] == Pwd) {
                cout << "Success!" << endl;
            } else {
                if (getHash(Pwd) == hashs[Name]) {
                    cout << "Attention!" << endl;
                } else {
                    cout << "Failed!" << endl;
                }
            }
        }
    }
    return 0;
}

