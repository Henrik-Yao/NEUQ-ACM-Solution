# WEEK7 周报
## 7-1 词典
### 题面
你刚从滑铁卢搬到了一个大城市，这里的人们讲一种难以理解的外语方言。幸运的是，你有一本字典来帮助你理解它们。

**输入格式:**
输入第一行是正整数N和M,后面是N行字典条目（最多10000条），然后是M行要翻译的外语单词（最多10000个）。每一个字典条目都包含一个英语单词，后面跟着一个空格和一个外语单词。 输入中的每个单词都由最多10个小写字母组成。

**输出格式:**
输出翻译后的英文单词，每行一个单词。非词典中的外来词汇输出“eh”。

**输入样例:**
在这里给出一组输入。例如：
```
5 3
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay
atcay
ittenkay
oopslay
结尾无空行
```
**输出样例:**

```
cat
eh
loops
结尾无空行
```
### 思路
把字典条目存进map里，键是外语，值是英语，如果找到(dic[quesstring]非空)输出值

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<string, string> dic;
    int N, M;
    cin >> N >> M;
    string keystring, valuestring, quesstring, tempstring;
    for (int i = 0; i < N; ++i)
    {
        cin >> keystring >> valuestring;
        dic[valuestring] = keystring;
    }
    for (int i = 0; i < M; ++i)
    {
        cin >> quesstring;
        //    tempstring = dic[quesstring];
        if (dic[quesstring] != "")
        {
            cout << dic[quesstring] << endl;
        }
        else
        {
            cout << "eh" << endl;
        }
    }
    return 0;
}
```

## 7-2 神秘密码
### 题面
传说二战时X国收到了上帝的一串密码，只有解开密码，才能阻止战争的继续进行，世界才会恢复和平。解开密码的第一道工序就是解压缩密码，上帝对于连续的若干个相同的子串"X"会压缩为"[DX]"的形式(D是一个整数且1<=D<=99),比如说字符串"CBCBCBCB"就压缩为"[4CB]"或者"[2[2CB]]",类似于后面这种压缩之后再压缩的称为二重压缩。如果是"[2[2[2CB]]]"则是三重的。现在我们给你上帝发送的密码，请你对其进行解压缩。
**输入格式:**
一个字符串
**输出格式:**
一个字符串
**输入样例:**
```
AC[3FUN]
结尾无空行
```
**输出样例:**
```
ACFUNFUNFUN
结尾无空行
```

### 思路
用递龟思想，遇到'['跳过并向下递龟，遇到']'结束，返回空串，遇到数字检查数字的位数，并向下寻找待重复的串，如果是其他字符则直接填进新串。
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
string s;
int p = -1;
string getString(int x)
{
    p = max(x, p);
    int i = 0;
    string newString = "";
    if (x == s.length())
    {
        return "";
    }
    if (s[x] == '[')
    {
        newString = getString(x + 1);
        newString += getString(p + 1);
    }
    else if (s[x] == ']')
    {
        return "";
    }
    else if (s[x] >= '0' && s[x] <= '9')
    {
        i = s[x] - '0';
        if ((x + 1) < s.length() && s[x + 1] >= '0' && s[x + 1] <= '9')
        {
            i = i * 10 + (s[++x] - '0');
        }
        string temp = getString(x + 1);
        for (int j = 0; j < i; ++j)
        {
            newString += temp;
        }
    }
    else
    {
        newString = s[x] + getString(x + 1);
    }
    return newString;
}

int main()
{
    getline(cin, s);
    string newString = getString(0);
    cout << newString << endl;
    return 0;
}
```

## 7-3 删除公共字符
### 题面
输入两个字符串，从第一个字符串中删除第二个字符串中的所有字符。例如，输入“They are students.”和“aeiou”，则删除之后的第一个字符串变成“Thy r stdnts”。
**输入格式:**
输入包含多组测试，每个测试输入包含两个字符串。

**输出格式:**
输出删除后的字符串。

**输入样例:**
```
They are students.
aeiou
结尾无空行
```
**输出样例:**
```
Thy r stdnts.
结尾无空行
```

### 思路
先把模式串存进set里，然后把原串一个字符一个字符塞进set里，如果长度增加就取出该字符并输出，然后注意是多组数据。

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set<char> pattern;
    string s, p;
    while (getline(cin, s))
    {
        getline(cin, p);
        for (int i = 0; i < p.length(); ++i)
        {
            pattern.insert(p[i]);
        }
        int cnt = pattern.size();
        for (int i = 0; i < s.length(); ++i)
        {
            pattern.insert(s[i]);
            if (pattern.size() != cnt)
            {
                cout << s[i];
                pattern.erase(s[i]);
            }
        }
        cout << endl;
        s.clear();
        p.clear();
        pattern.clear();
    }

    return 0;
}
```
## 7-4 最长有序子序列
### 题面
对于给定一个数字序列 (a1，a2，…，an) ，如果满足a1<a 2<…<an，则称该序列是有序的。若在序列(a1，a 2，…，an) 中删除若干元素得到的子序列是有序的，则称该子序列为一个有序子序列。有序子序列中长度最大的即为最长有序子序列。
例如，(1，3，5)、(3，5，8)、(1，3，5，9)等都是序列 (1，7，3，5，9，4，8) 的有序子序列；而(1，3，5，9)、(1，3，5，8)、(1，3，4，8)都是序列 (1，7，3，5，9，4，8)的一个最长有序子序列，长度为4。
请编写程序，求出给定数字序列中的最长有序子序列的长度。
**输入格式:**
首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据第一行输入一个整数 n（1≤n≤1000），第二行输入n个整数，数据范围都在[0，10000]，数据之间以一个空格分隔。
**输出格式:**
对于每组测试，输出n个整数所构成序列的最长有序子序列的长度。每两组测试的输出之间留一个空行。
**输入样例:**
```
1
7
1 7 3 5 9 4 8
结尾无空行
```
**输出样例:**
```
4
结尾无空行
```

### 思路
最长有序子序列，限定条件首先是子串是否递增，然后是子串长度是否有增加。注意数据之间有空行
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, N;
    cin >> T;
    int flag=0;
    while (T--)
    {
        if(!flag)
        {
            flag++;
        }
        else
        {
            cout<<endl;
        }
        cin >> N;
        int a[N], len[N], max = 1;
        for (int i = 0; i < N; ++i)
        {
            cin >> a[i];
            len[i] = 1;
        }
        for (int i = 1; i < N; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (a[i] > a[j] && len[i] < len[j] + 1)
                {
                    len[i] = len[j] + 1;
                    len[i] > max ? max = len[i] : 1;
                }
            }
        }
        cout << max << endl;
    }
    return 0;
}
```
## 7-5 0-1背包问题
### 题面
给定n种物品（每种仅一个）和一个容量为c的背包，要求选择物品装入背包，使得装入背包中物品的总价值最大。
**输入格式:**
测试数据有多组，处理到文件尾。每组测试数据输入3行，第1行为两个整数n（1≤n≤400）和c (1≤c≤1500)，分别表示物品数量与背包容量，第二行为n个物品的重量wi（1≤i≤n），第三行为这n个物品的价值vi（1≤i≤n）。物品重量、价值都为整数。
**输出格式:**
对于每组测试，在一行上输出一个整数，表示装入背包的最大总价值（结果保证在int范围内）。
**输入样例:**
```
4 9
2 3 4 5
3 4 5 7
结尾无空行
```
**输出样例:**
```
12
结尾无空行
```

### 思路
背包问题，比较好做，数组范围从1~N，状态转移方程：```dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);```表格末尾即是解
### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int dp[405][1505];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, C;
    while (cin >> N >> C)
    {
        int w[N + 1], v[N + 1];
        for (int i = 1; i <= N; ++i)
            cin >> w[i];
        for (int i = 1; i <= N; ++i)
            cin >> v[i];
        // for (int i = 0; i <= N; ++i)
        // {
        //     for (int j = 0; j <= C; ++j)
        //     {
        //         dp[i][j] = 0;
        //     }
        // }
        memset(dp, 0, sizeof(dp));
        int i, j;
        for (i = 1; i <= N; ++i)
        {
            for (j = 1; j <= C; ++j)
            {
                if (j >= w[i])
                {
                    dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
                // printf("%4d", dp[i][j]);
            }
            // cout << endl;
        }
        cout << dp[N][C] << endl;
    }
}
```
