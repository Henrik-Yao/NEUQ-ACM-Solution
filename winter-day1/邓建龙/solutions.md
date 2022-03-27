# day1

## 7-1

> 树状数组
>
> 重点是数据的更新  以及 **`lowbit`**
>
> 相关文章： https://blog.csdn.net/weixin_44828107/article/details/104187366

```c++
#include <bits/stdc++.h>
#define lowbit(i) ((i)&(-i))
#define ll long long
using namespace std;
const int N = 1e6 + 10;
ll n, q, x, c[N];
void update(int x, int v) { // 节点值更新
    for (int i = x; i <= n; i += lowbit(i)) c[i] += v;
}
ll getSum(int x) { // 求区间和
    ll ans = 0;
    for (int i = x; i > 0; i -= lowbit(i)) ans += c[i]; return ans;
}
int main()
{
    // 树状数组
    cin >> n >> q;
    for (int i = 1; i <= n; i++) scanf("%d", &x), update(i, x);
    while (q--) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) update(l, r);
        else cout << getSum(r) - getSum(l - 1) << endl;
    }
    return 0;
}
```

## 7-3

> 链表问题，但这题比较简单，用的数组

链表：双向链表，头尾相连循环，如果 `该指针->next != 该指针` 说明剩余人数不止一人继续执行，剔除第 m 、k 个报错的人，否者退出循环

数组，记录当前报数号码，以及每人是否已经退出即可，注意报号到最后一人时下一人应为第一人

```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int s[N], q[N], n, m, k;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) q[i] = 1, s[i] = 1;
    int num = n, op = 1;
    int i = 1;
    while (num) {
        if (op == 1) {
            int x = 1;
            while (x < m) {
                i--; if (i < 1) i = i + n;
                if (s[i] == 1) x++;
            }
            cout << i << " ";
            s[i] = 0; i--; num--; op = -1 * op;
        } else {
            int x = 1;
            while (x < k) {
                i++; if (i > n) i = i - n;
                if (s[i] == 1) x++;
            }
            cout << i << " "; s[i] = 0; i++; num--; op = -1 * op;
        }
    }
    return 0;
}
```

## 7-5

> 开两个变量 `l` 、`r` 分别记录单独的左括号和右括号数量
>
> 如果 l + r 为 0 则 “Match”
>
> 需要注意 `l` 、`r` 的增与减
>
> 最后在头部添加 `r` 个左括号， 尾部添加 `l` 个右括号即可

```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while (cin >> str) {
        int l = 0, r = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') l++; // 单独左括号
            else {
                if (l == 0) r++; // 单独右括号
                else l--;
            }
        }
        if (l == 0 && r == 0) cout << "Match"<< endl;
        else {
            cout << l + r << endl;
            for (int i = 0; i < r; i++) cout << '(';
            cout << str;
            for (int i = 0; i < l; i++) cout << ')';
            cout << endl;
        }
    }
    return 0;
}
```

## 7-6

> 字符串
>
> 解决方法很多
>
> 定义两个指针分别指向头尾，同时向后向前移动进行比较即可

```c++
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
```

## 7-7

> 字符串
>
> 方法：栈，递归
>
> 首先要明白题意
>
> 1. `B->tAdA` 需要将字符串中 B 转化成 tAdA
> 2. `A->sae` 需要将字符串中 A 转化成 sae
>
> **如果转化两次，这里需要先转化B， 如果先转化A，B 转化成的 A需要再转化一次**
>
> 3. `(θδ1δ2...δn)->θδnθδn-1...θδ1θ` 括号中的内容需要按这样的规律转化

> 我的方法是栈
>
> 1. 把全部字符串存入栈0
> 2. 把栈0中左括号右端或者右括号左端内容存入栈1（左右根据栈0入栈顺序）
> 3. 把栈1中右括号左端或者左括号右端内容存入栈2（栈2中内容完全是括号中内容）
> 4. 借助栈3将栈2中内容按上述第 3 点 `(θδ1δ2...δn)->θδnθδn-1...θδ1θ)` 规律处理
> 5. 然后拼接栈1栈2栈3，**返回上层，这里括号可能不止一层**

```c++
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
```

## 7-8

> 栈
>
> 先通过 `check()` 函数判断读入字符是不是括号，不是跳过，是则继续操作
>
> 通过 `check1()` 函数判断字符是不是左括号，是则存**入栈**中，不是则继续操作
>
> 通过 `check2()` 函数判断字符是不是右括号，是则从栈中**取出栈顶** (一定是左括号，如果栈为空说明右括号多了，退出，返回不匹配)，通过 `check3()` 函数判断栈顶和该字符是不是**配对的括号**（因为有三种），是则跳过，不是则返回不匹配
>
> 最后判断栈是否为空（如果都匹配，每遇到一次右括号，就会从栈顶取出对应左括号，栈会被清空），为空说明匹配，不为空说明左括号多了，返回不匹配。

```c++
#include <bits/stdc++.h>
using namespace std;
stack<char> stc;
bool check(char ch)
{
    if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}') return true;
    return false;
}
bool check1(char ch)
{
    if (ch == '(' || ch == '[' || ch == '{') return true;
    return false;
}
bool check2(char ch)
{
    if (ch == ')' || ch == ']' || ch == '}') return true;
    return false;
}
bool check3(char left, char right) {
    if ((left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}')) return true;
    return false;
}
int main()
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (check(ch)) {
            if (check1(ch)) stc.push(ch);
            if (check2(ch)) {
                if (stc.empty()) {
                    cout << "no" << endl;
                    break;
                }
                else {
                    char tmp = stc.top();
                    stc.pop(); // 弹出左括号
                    if (!check3(tmp, ch)) {
                        cout << "no" << endl;
                        break;
                    }
                }
            }
        }
    }
    if (stc.empty()) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}
```

## 7-10

> 队列
>
> 题意就是将一个数列，拆成多组降序排列的数列，并找出 1 所在数列，输出该数列长度
>
> 结论：1 一定在第一个数列中

```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
queue<int> q[N];
int num = 1; // 表示队列数量
int n, x;
int main()
{
    cin >> n;
    for (int i = 0; i < N; i++) q[i].push(0); // 预先向队列中添加第一个元素 0
    for (int i = 0; i < n; i++) {
        cin >> x;
        int flag1 = 1;
        for (int i = 0; i < num; i++) {
            if (q[i].back() > x) {
                q[i].push(x);
                flag1 = 0;
                break;
            }
        }
        if (flag1 == 1) {
            num++;
            q[num - 1].push(x);
        }
    }
    // num = ans + 1   ans = num - 1
    q[1].pop(); // 删除预先添加的 0
    int flag = 1;
    while (!q[1].empty()) {
        if (flag == 1) flag = 0, printf("%d", q[1].front());
        else printf(" %d", q[1].front());
        q[1].pop();
    }
    cout << endl;
    cout << num - 1 << endl;
    return 0;
}
```

