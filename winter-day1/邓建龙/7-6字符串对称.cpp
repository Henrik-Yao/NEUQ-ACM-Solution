#include <bits/stdc++.h>
using namespace std;
vector<char> vec;
int top = -1;
int len;
string str;
bool pop()
{
    if (top > -1) { top--;  return true; }
    else return false;
}
bool check()
{
    for (int i = 0; i < len; i++) {
        if (str[i] != vec[top]) { return false; }
        pop();
    }
    return true;
}
int main()
{
    cin >> str;
    len = str.size();
    for (int i = 0; i < len; i++) vec.push_back(str[i]), top++;
    if (check()) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}