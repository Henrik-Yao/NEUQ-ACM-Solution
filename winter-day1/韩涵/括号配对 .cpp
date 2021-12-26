/*
#include<iostream>
#include <stack>
using namespace std;
#define ch(a) (a + a % 2 + 1)
int main() {
    stack <char> kuohao;
    char temp = NULL;
    string a;
    cin >> a;
    for (int i = 0; i < a.length(); i++) {
        char temp = a[i];
        if (temp == '[' || temp == '{' || temp == '(')
            kuohao.push(ch(temp));
        else if (temp == ']' || temp == '}' || temp == ')') {
            if (kuohao.empty() || kuohao.top() != temp) {
                cout << "False";
                return 0;
            }
            else kuohao.pop();
        }
    }
    if (kuohao.empty()) cout << "yes";
    else cout << "no";
}
*/