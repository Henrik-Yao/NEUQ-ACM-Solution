#include<iostream>
using namespace std;

string func()
{
    string s = "", schild;
    int n;
    char ch;
    while (cin >> ch) {
        if (ch == '[') {
            cin >> n;
            schild = func();
            while (n--) s += schild;
        }
        else {
            if (ch == ']') return s;
            else s += ch;
        }
    }
}

int main()
{
    cout << func();
    return 0;
}