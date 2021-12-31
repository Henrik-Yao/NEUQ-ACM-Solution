#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    stack<char>s, s1, s2, s3;
    int times = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        s.push(str[i]);
        if (str[i] == '(') times++;
    }
    while (times--) { // s B(einxgz)B# 栈顶在左  --> B#
        while (s.top() != ')') {
            s1.push(s.top());
            s.pop();
        }
        s.pop(); // s1 B(einxgz 栈顶在右 --> B
        while (s1.top() != '(') {
            s2.push(s1.top());
            s1.pop();
        }
        s1.pop(); // s2 einxgz 栈顶在左  --> empty
        char flag = s2.top();
        s2.pop();
        while (!s2.empty()) {
            s3.push(s2.top());
            s2.pop();
        } // s3 inxgz 栈顶在右
        while (!s3.empty()) {
            s1.push(flag);
            s1.push(s3.top());// -->B e z e g e x e n e i e
            s3.pop();
        }
        s1.push(flag); // 右半部分 s1 --> B e z e g e x e n e i e B #  栈顶在右
    }
    while (!s.empty()) {
        s1.push(s.top());
        s.pop();
    }
    // 调换栈顶
    stack<char> res;
    while (!s1.empty()) {
        res.push(s1.top());
        s1.pop();
    } // res B e z e g e x e n e i e B # 栈顶在左
    string ans = "";
    while (!res.empty()) {
        ans += res.top();
        res.pop();
    }
    for (int i = 0; i < 2; i++) {
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 'B') ans = ans.substr(0, i) + "tAdA" + ans.substr(i + 1);
            if (ans[i] == 'A') ans = ans.substr(0, i) + "sae" + ans.substr(i + 1);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        char ch = ans[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) printf("%c", ch);
    }
    return 0;
}