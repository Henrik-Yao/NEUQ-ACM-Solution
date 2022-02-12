# 寒假集训—day1（线性表，栈，队列，字符串）
## 7-1 动态区间求和
### 题面


**输入格式:**


**输出格式:**

对于每个 2 l r 操作输出一行，每行有一个整数，表示所求的结果。

**输入样例:**
在这里给出一组输入。例如：
```
3 2
1 2 3
1 2 0
2 1 3
结尾无空行
```
**输出样例:**
在这里给出相应的输出。例如：
```
6
结尾无空行
```
### 思路
用树状数组，重点是定义lowbit函数（棒读）
~~大佬复读机~~

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define lowbit(i) ((i) & (-i))
long long a[N];
int n;
void add(int k, int num)
{
    for (int i = k; i <= n; i = i + lowbit(i))
    {
        a[i] = a[i] + num;
    }
}
long long Sum(int k)
{
    long long sum = 0;
    for (int i = k; i > 0; i = i - lowbit(i))
    {
        sum = sum + a[i];
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> n >> q;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; ++i)
    {
        int t;
        cin >> t;
        add(i, t);
    }
    int questnum, temp, x, l, r;
    for (int i = 0; i < q; ++i)
    {
        cin >> questnum;
        if (questnum == 1)
        {
            cin >> temp >> x;
            add(temp, x);
        }
        else
        {
            cin >> l >> r;
            cout << Sum(r) - Sum(l - 1) << endl;
        }
    }
    return 0;
}
```
## 7-2 小明打字
### 题面

小明正使用Microsoft Word打一篇文档，文档只包含a-z的小写字母和空格，在打字过程中可能会一次或多次按下Home键、End键、←方向键、→方向键、Insert键、Backspace键。请编写程序，给定小明在键盘上按键的序列，输出小明屏幕上最终显示的文本。 提示：Home键会将当前光标移至文本开始位置，End键当前光标移至文本尾，←键和→键会使当前光标左移或右移一个位置（如果光标在文档头则无法左移，光标在文档尾则无法右移），Insert键会在插入和替换文本间切换（默认是插入状态），Backspace键会删除当前光标前的一个字符。

**输入格式:**
输入为不超过50000个字符，表示小明的按键序列。包含a-z的小写字母、空格以及字符[、]、{、}、-、=。其中字符“[”表示Home键，“]”表示End键，“{”表示←键，“}”表示→键，“-”表示Insert键，“=”表示Backspace键。

**输出格式:**
输出为在小明屏幕上最终显示的文本。最后一个字母后没有回车或换行。

**输入样例:**
在这里给出一组输入。例如：
```
jilin[i lofe{{-v-} ] universiti=y
结尾无空行
```
**输出样例:**
在这里给出相应的输出。例如：
```
i love jilin university
结尾无空行
```
### 思路
用string存字符串，逐个字符处理，定义迭代器，读出空格和小写字母后用insert函数和迭代器把字符存入list，然后读出代表操作的符号便对迭代器进行操作（home迭代器移至l.begin(),end迭代器移至l.end(),←迭代器--（注意不能超过l.begin()），→迭代器++（注意不能超过l.end()），删除操作迭代器先前移，再l.erase(it++)，Insert操作定义状态变量=1，每读到一个‘-’号乘一次-1切换状态）
~~debug真是要人老命，迭代器虽然好用但是是一生之敌~~

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<char> l;
    list<char>::iterator it = l.begin();
    string s;
    getline(cin, s);
    int flag = 1;
    for (int i = 0; i < s.length(); ++i)
    {

        if ((isalpha(s[i]) || isspace(s[i])) && flag == 1)
        {
            l.insert(it, s[i]);
        }
        else if ((isalpha(s[i]) || isspace(s[i])) && flag == -1)
        {
            l.erase(it++);
            l.insert(it, s[i]);
        }
        else
        {
            switch (s[i])
            {
            case '[':
                it = l.begin();
                break;
            case ']':

                it = l.end();
                break;
            case '{':
                if (it != l.begin())
                    it--;
                break;
            case '}':
                if (it != l.end())
                    it++;
                break;
            case '=':
                it--;
                l.erase(it++);
                break;
            case '-':
                flag *= -1;
                break;
            }
        }
    }
    // cout << "*it = " << *it << "|" << endl;
    for (auto iter = l.begin(); iter != l.end(); ++iter)
    {
        cout << *iter;
    }
    return 0;
}
```

## 7-4 程序设计综合实践1.4
### 题面

1.4 编写程序，输入若干正整数，按从小到大次序建立1个带头结点单链表，设计一个实现单链表分离算法的Split函数，将原单链表中值为偶数的结点分离出来形成一个新单链表，新单链表中头结点重新申请，其余结点来自原链表，分离后，原链表中只剩非偶数值所在结点，最后显示2个单链表，在程序退出前销毁单链表。要求Split算法时间复杂性达到O（n）,程序不可存在内存泄漏。

**输入格式:**
若干正整数。

**输出格式:**
每个单链表输出占一行，元素间用分隔符->分隔；初始单链表、剩余元素单链表、偶数元素单链表，共3行。

**输入样例:**
```
100 2 3  50 2 1 5 8
结尾无空行
```
**输出样例:**
```
1->2->2->3->5->8->50->100
1->3->5
2->2->8->50->100
结尾无空行
```

### 思路
偷了懒，建了3个链表，一个装全部元素，一个装奇数元素，一个装偶数元素，然后用list自带的排序输出

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    list<int> l, jishu, oushu;
    while (scanf("%d", &num) != EOF)
    {
        l.push_back(num);
        if (!(num % 2))
        {
            oushu.push_back(num);
        }
        else
        {
            jishu.push_back(num);
        }
    }
    l.sort();
    oushu.sort();
    jishu.sort();
    int temp;
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        if (it != l.begin())
        {
            printf("->");
        }
        temp = *it;
        printf("%d", temp);
    }
    printf("\n");
    for (auto it = jishu.begin(); it != jishu.end(); ++it)
    {
        if (it != jishu.begin())
        {
            printf("->");
        }
        temp = *it;
        printf("%d", temp);
    }
    printf("\n");
    for (auto it = oushu.begin(); it != oushu.end(); ++it)
    {
        if (it != oushu.begin())
        {
            printf("->");
        }
        temp = *it;
        printf("%d", temp);
    }
    
    return 0;
}
```


## 7-5 括号匹配
### 题面

请编写程序判断一个包含“（”和“）”的括号序列是否匹配。如匹配则输出Match；如不匹配，计算出使该序列变为匹配序列所需添加的最少括号数目（只允许在该序列开始和结尾处添加括号），并输出经添加最少括号后得到的合法匹配序列。

**输入格式:**
输入为若干行，每行一个字符串，包含不超过10 
5
 个括号。输入行数不超过10行。

**输出格式:**
对于输入的每个括号序列输出1行或2行信息。若输入的括号序列匹配，则输出Match。若不匹配，则输出分为2行，第1行为一个整数，表示将该序列变为匹配序列所需添加的最少括号数目，第2行为一个字符串，表示经添加最少括号后得到的合法匹配序列。

**输入样例:**
```
(())()
)(
()))((
结尾无空行
```
**输出样例:**

```
Match
2
()()
4
((()))(())

结尾无空行
```

### 思路
用栈模拟，很简单，分情况讨论缺左括号和右括号的情形并计数，最后输出

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;

    while (getline(cin, s))
    {
        int zuo = 0, you = 0;
        stack<char> stk;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')//左括号入栈
            {
                stk.push(s[i]);
            }
            else if ((stk.empty() || stk.top() != '(') && s[i] == ')')//如果栈空或者栈顶是右括号，未匹配成功的右括号数加一
            {
                zuo++;
            }
            else if (stk.top() == '(' && s[i] == ')')//如果右括号匹配到左括号把左括号弹出
            {
                stk.pop();
            }
        }
        if (stk.empty() && zuo == 0)//注意全是右括号的情形
        {
            printf("Match\n");
        }
        else
        {
            you = stk.size();
            printf("%d\n", zuo + you);
            for (int i = 0; i < zuo; ++i)
            {
                printf("(");
            }
            cout << s;
            for (int i = 0; i < you; ++i)
            {
                printf(")");
            }
            printf("\n");
        }
    }

    return 0;
}
```

## 7-6 字符串对称
### 题面

编写一个算法利用顺序栈判断一个字符串是否是对称串。所谓对称串是指从左向右读和从右向左读的序列相同。

**输入格式:**
输入一个无空格的字符串。

**输出格式:**
输入一个无空格的字符串。

**输入样例:**
```
abba
结尾无空行
```
**输出样例:**
```
abba
结尾无空行
```

### 思路
输入到string里从两端比较

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);

    bool flag = 0;
    for (int i = 0, j = s.length() - 1; i < s.length() / 2; ++i, --j)
    {
        if (s[i] != s[j])
        {
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}
```
## 7-7 魔王语言解释
### 题面

有一个魔王总是使用自己的一种非常精练而抽象的语言讲话，没人能听的懂。但他的语言是可以逐步解释成人能懂得语言的，因为他的语言是由以下两种形式的规则由人的语言逐 步抽象上去的：   
α->β1β2...βn 
(θδ1δ2...δn)->θδnθδn-1...θδ1θ      在这两种形式中，从左到右均表示解释；从右到左表示抽象。试写一个魔王解释系统，把他的话解释成人能听懂得话。 [基本要求]     用下述两条具体规则和上述规则形式（2）实现。设大写字母表示魔王语言的词汇；小写字     母表示人的语言词汇；希腊字母（a,b1,s,y1等）表示可以用大写或小写字母代换的变量。    
魔王语言可含人的词汇。      

B->tAdA  
A->sae
**输入格式:**
输入一串带有大小写子字母的字符串其中小写字母用圆括号括起来。例如：B（einxgz）B# 。

**输出格式:**
根据魔王语言翻译逻辑，输出答案。例如：tsaedsaeezegexeneietsaedsae。

**输入样例:**
```
B(einxgz)B#
结尾无空行
```
**输出样例:**
```
tsaedsaeezegexeneietsaedsae
结尾无空行
```

### 思路
先拆小括号，由于本题数据没有嵌套括号所以比较好处理，开一个栈即可，然后把拆完小括号的字符转存到list里，逐一输出，遇到A转换为sae，遇到B转换为tsaedsae

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> mo;
    char rep;
    list<char> l;
    // string s;
    // getline(cin,s);
    char ch, tmp;
    while (scanf("%c", &ch) != EOF)
    {
        if (isalpha(ch) && mo.empty())
        {
            l.push_back(ch);
        }
        else if (ch == '(')
        {
            mo.push(ch);
            scanf("%c", &rep);
        }
        else if (isalpha(ch) && !mo.empty())
        {
            mo.push(ch);
        }
        else if (ch == ')')
        {
            while (mo.top() != '(')
            {
                l.push_back(rep);
                tmp = mo.top();
                l.push_back(tmp);
                mo.pop();
            }
            mo.pop();
            l.push_back(rep);
        }
    }
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        if (*it == 'A')
        {
            printf("sae");
        }
        else if (*it == 'B')
        {
            printf("tsaedsae");
        }
        else
        {
            cout << *it;
        }
    }
    return 0;
}
```
## 7-8 括号配对
### 题面

设表达式中允许包含3种括号：圆括号、方括号和大括号。即小括号、中括号和大括号。 编写一个算法来判断表达式中的括号是否正确配对，要求利用栈的结构实现。

**输入格式:**
输入一行带圆括号、方括号和大括号的字符串。

**输出格式:**
若匹配，输出yes。若不匹配，输出no。。

**输入样例:**
```
([1+2])
结尾无空行
```
**输出样例:**
```
yes
结尾无空行
```
### 思路

只读入三种括号存入栈看是否匹配即可，其他字符可以忽略

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> s;
    char ch;
    while (scanf("%c", &ch) != EOF)
    {
        if (ch == '[' || ch == '(' || ch == '{')
        {
            s.push(ch);
        }
        else if (ch == ']')
        {
            if (s.top() == '[')
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
        else if (ch == ')')
        {
            if (s.top() == '(')
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
        else if (ch == '}')
        {
            if (s.top() == '{')
            {
                s.pop();
            }
            else
            {
                break;
            }
        }
    }
    if (s.empty())
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
    return 0;
}
```
## 7-10 列车车厢重排
### 题面

火车站的列车调度铁轨的结构如下所示： (Exit) 9 8 7 6 5 4 3 2 1 <==== ………………………………… <==== 8 4 2 5 3 9 1 6 7 (Entrance) 两端分别是一条入口（Entrance）轨道和一条出口（Exit）轨道，它们之间可能有N条平行的轨道。每趟列车从入口可以选择任意一条轨道进入排队，以方便最后有序从出口离开。在前例中有9趟列车，在入口处按照{8，4，2，5，3，9，1，6，7}的顺序排队等待进入。如果要求它们必须按序号递减的顺序从出口离开，则至少需要多少条平行铁轨用于调度？调度入队后，各个队列里车厢情况如何？

**输入格式:**
 输入第一行给出一个整数N (2 ≤ N ≤99 )，下一行给出从1到N的整数序号的一个重排列。数字间以空格分隔。

**输出格式:**
第一行输出1号车厢所在的队列中的元素（车厢编号间以空格分隔），注意，调度时，车厢只进入队列等待，并不出队。 在第二行中输出可以将输入的列车按序号递减的顺序重排所需要最少的辅助铁轨（队列）条数。

**输入样例:**
```
9
8 4 2 5 3 9 1 6 7
结尾无空行
```
**输出样例:**
```
8 4 2 1
4
结尾无空行
```
### 思路

用队列模拟，稍微有些繁琐，判断队列数组是否为空，如果为空就在数组中新开一个队列，存入元素，并用另一个数组存储每个队列的元素的最小值，如果下一辆车编号小于每队队尾则把该车加入队列，如果编号大于队尾则新开一个队列

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int cnt = 1, n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    queue<int> q[n + 1];
    int num[n + 1];
    int sign = 0;
    for (int i = 1; i <= n; ++i)
    {

        if (q[cnt].empty())
        {
            q[cnt].push(a[i]);
            num[cnt] = a[cnt];
            a[i] == 1 ? sign = 1 : 1;
        }
        else
        {
            int flag = 1;
            for (int j = 1; j <= cnt; ++j)
            {
                if (a[i] < num[j])
                {
                    num[j] = a[i];
                    q[j].push(a[i]);
                    flag = 0;
                    a[i] == 1 ? sign = j : 1;
                    break;
                }
            }
            if (flag)
            {
                cnt++;
                num[cnt] = a[i];
                q[cnt].push(a[i]);
                a[i] == 1 ? sign = cnt : 1;
            }
        }
    }
    int t;
    // cout << sign << endl;
    int fla=0;
    while (!q[sign].empty())
    {
        
        t = q[sign].front();
        q[sign].pop();
        if(!fla)
        {
            cout<<t;
            fla++;
        }
        else
        {
            cout<<" "<<t;
        }
    }
    cout << endl
         << cnt << endl;
    return 0;
}

```