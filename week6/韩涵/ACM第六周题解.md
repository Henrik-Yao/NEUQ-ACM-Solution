# ACM第六周题解
<center>韩涵</center>

## KMP算法

KMP算法（快速模式匹配算法）是一种改进的字符串匹配算法。KMP算法的核心是利用匹配失败后的信息，尽量减少模式串与主串的匹配次数以达到快速匹配的目的。具体实现就是通过一个next()函数实现，函数本身包含了模式串的局部匹配信息。KMP算法的时间复杂度O(m+n)  。

KMP算法通过创建next数组对模式串的字符特征进行存储。模式串中各字符对应 next 值的计算方式是，取该字符前面的字符串（不包含自己），其前缀字符串和后缀字符串相同字符的最大个数再 +1 就是该字符对应的 next 值。

#### 使用KMP算法实现 **strstr()** 函数:

```c++
#include<iostream>
#include<string.h>
using namespace std;

string text, patten;
int textLen, pattenLen;
int KMPnext[1000001];

void buildNext() {//创建next数组
    int i = 2, j = 1;
    KMPnext[1] = 0;
    KMPnext[2] = 1;
    while (i < pattenLen) {
        if (j == 0 || patten[i - 1] == patten[j - 1]) {
            i++; j++;
            KMPnext[i] = j;
        }
        else j = KMPnext[j];
    }
}

int main() {
    cin >> text >> patten;
    textLen = text.length();
    pattenLen = patten.length();
    buildNext();
    int i = 1, n = 1;
    int ans = -1;
    while (i <= textLen) {//进行匹配
        if (n == 0 || text[i - 1] == patten[n - 1]) {
            i++; n++;
            if (n == pattenLen + 1) {
                ans = i - pattenLen;
                break;
            }
        }
        else n = KMPnext[n];
    }
    cout << ans;
}
```

复旦大学朱洪教授对KMP串匹配算法进行了改进,他主要是修改了next函数，在求 next[j]时，不但要求P[i]=P[j-( next[j]-i)]成立，而且要求P[next[j]]!=p[j]。我们把修改后的next函数计作 Newnext。则计算函数 Newnext值的算法如下 [5]  。*(但是我没看懂)*

#### 7-1 字符串模式匹配（KMP）

###### 题目详情：

给定一个字符串 text 和一个模式串 pattern，求 pattern 在text 中的出现次数。text 和  pattern 中的字符均为英语大写字母或小写字母。text中不同位置出现的pattern 可重叠。

###### 输入格式:

输入共两行，分别是字符串text 和模式串pattern。

###### 输出格式:

输出一个整数，表示 pattern 在 text 中的出现次数。

###### 解题思路：

题目上写着呢。但是成功检测到一个之后，需要将主串和模式串回退一位，防止漏查。之后模式串需要模拟最后一个匹配失败时的情况。

###### c++代码：

```c++
#include<iostream>
#include<string.h>
using namespace std;

string text, patten;
int textLen, pattenLen;
int KMPnext[1000001];

void buildNext() {
    int i = 2, j = 1;
    KMPnext[1] = 0;
    KMPnext[2] = 1;
    while (i < pattenLen) {
        if (j == 0 || patten[i - 1] == patten[j - 1]) {
            i++; j++;
            KMPnext[i] = j;
        }
        else j = KMPnext[j];
    }
}

int main() {
    cin >> text >> patten;
    textLen = text.length();
    pattenLen = patten.length();
    buildNext();//创建next数组
    int i = 1, n = 1,ans = 0;
    while(i <= textLen) {
        if (n == 0 || text[i - 1] == patten[n - 1]) {
            i++; n++;
            if (n == pattenLen + 1) {//匹配成功
                i--;
                ans++; 
                n = KMPnext[n - 1];
            }
        }
        else n = KMPnext[n];
    }
    cout << ans;
}
```

#### 7-3 子字符串个数匹配

###### 题目详情：

分别输入两个字符串A和B，A由多个小字符串组成（中间由非字母隔开），B是由字母组成的字符串。求出A中包含B的小字符串的个数（详细看样例），并且输出它。（不区分大小写）

###### 输入格式:

先输入字符串A，由回车结束。然后输入字符串B。

###### 输出格式:

输出A中包含B字符串的个数

###### 解题思路：

可以选择直接用next函数，然后分割字符串逐个匹配。也可以KMP，将分隔符之间的串用flag进行标记，分割字符重置flag标记即可。模式串大小写需要在创建next数组之前完成转化。使用getline（cin，s）进行string类型的输入，即可存入空格和TAB。

###### c++代码：

```c++
#include<iostream>
#include<string>
using namespace std;

string text, patten;
int textLen, pattenLen;
string temp;
int KMPnext[100000001];

void buildNext() {
    int i = 2, j = 1;
    KMPnext[1] = 0;
    KMPnext[2] = 1;
    if (patten[0] >= 'A' && patten[0] <= 'Z') patten[0] += 32;
    if (patten[1] >= 'A' && patten[1] <= 'Z') patten[1] += 32;
    while (i < pattenLen) {
    //写入next数组之前转化大小写
        if (patten[i] >= 'A' && patten[i] <= 'Z') patten[i] += 32;
        if (j == 0 || patten[i - 1] == patten[j - 1]) {
            i++; j++;
            KMPnext[i] = j;
        }
        else j = KMPnext[j];
    }
}

int main() {
    getline(cin, text);//可以接收空格
    getline(cin, patten);
    textLen = text.length();
    pattenLen = patten.length();
    buildNext();
    int i = 1, n = 1, ans = 0;
    bool flag = true;//flag标记分隔符之间的字符串
    while (i <= textLen) {
        if (text[i - 1] >= 'A' && text[i - 1] <= 'Z') text[i - 1] += 32;
        if (text[i - 1] < 'a' || text[i - 1] > 'z') {
            n = 1;
            i++;
            flag = true;
            continue;
        }
        if (n == 0 || text[i - 1] == patten[n - 1]) {
            i++; n++;
            if (n == pattenLen + 1) {
                i--;
                if (flag) {
                    ans++;
                    flag = false;
                }
                n = KMPnext[n - 1];
            }
        }
        else n = KMPnext[n];
    }
    cout << ans;
}
```

## 散列函数

散列函数（又称哈希函数）是一种从任何一种数据中创建小的数字“指纹”的方法。散列函数把消息或数据压缩成摘要，使得数据量变小，将数据的格式固定下来。该函数将数据打乱混合，重新创建一个叫做散列值的指纹。散列值通常用一个短的随机字母和数字组成的字符串来代表。好的散列函数在输入域中很少出现散列冲突。在散列表和数据处理中，不抑制冲突来区别数据，会使得数据库记录更难找到。



个人认为，使用ASCLL码作为字符的数字指纹非常方便，散列冲突也比较少见。

#### 7-2 妈妈再也不用担心我被拖库啦！ 

**题目详情：**

众所周知，互联网时代以来各大公司被“脱裤”的历史是一部五彩缤纷（误）的血泪史，给各大厂商造成了极大的经济损失。更为重要的是，由于有些用户在多个网站使用相同的用户名、密码，一旦一家网站被拖库，用户往往会遭受全方位的损失。为避免此情况，良心企业一般只在数据库中存储用户密码的**哈希值**——也就是根据特定规则产生的散列值，无法由此倒推出原密码。但这种方法也有一个缺点，即输入不同的密码有极小概率会得到一样的哈希值（我们称之为**碰撞**），从而被系统认定密码正确！现在你所在的公司采取如下方法产生密码字符串（长度至少为8，只包含大小写字母和数字）的哈希值：

1. 不区分字母的大小写，沿用16进制A代表10，B代表11……的规律，将原字符串视为一串36进制的数字
2. 将字符串平均划为4块，若无法平均划分，保证在前的分块不短于在后的分块，且长度差不超过1。如：长度26的字符串各分块长度为7、7、6、6，长度13的字符串各分块长度为4、3、3、3
3. 将每块的数字加和，取其个位数，四块取出的四个36进制数字顺次连接，得到一个四位36进制数字，即为该密码字符串的哈希值。

然而由于这种方式过于睿智，使得碰撞的几率奇高，你的任务就是为公司防范风险，在碰撞发生的时候给予示警！

###### 输入格式:

第一行一个整数N（N<1000），为操作的个数。 以下N行，每行一个字符、两个字符串（length<100），中间均以空格分隔。字符代表操作类型，两个字符串代表用户名和密码。

当字符为L时，代表以该用户名密码尝试登录；

当字符为R时，代表尝试注册这组用户名、密码，若注册成功则记录在案。

###### 输出格式:

N行，对于每一个L（登录操作），若密码正确，则输出一行“Success！”；

若密码错误或用户不存在，则输出一行“Failed！”；

若密码错误但会通过哈希检测而被放行，则输出一行“Attention！”。

对于每一个R（注册操作），若已存在该用户名，则输出一行“Repeated！”；

否则注册成功，输出一行“Signed！”。

以上输出均不包括引号。

###### 解题思路：

这里每个字符的哈希值已经固定，进行转换即可。题目数据量较大，且结构复杂思路简单。需要注意字符串的结尾需要‘\0’,否则字符串的判断会出现问题。

###### c++代码：

```c++
#include<iostream>
#include<string.h>
using namespace std;

typedef struct users {//存储用户数据
    string user;
    string password;
    char haxi[5] = { 0 };
};

users U[1001];
int useing = 0;

//暂存输入数据
string name, key;
char pat;
int len;
char ha[5] = { 0 };
int temp[4];

void unify() {//统一大小写
    for (int i = 0; i < len; i++)
        if (key[i] >= 'a' && key[i] <= 'z') key[i] -= 32;
}

void calulateArea() {//计算每一块的起始位置和个数
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

void haxiNum(int piece) {//计算piece块的哈希值
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

bool doR() {//进行R操作
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
    U[useing].haxi[4] = '\0';//字符串结尾加\0
    useing++;
    return true;
}

int doL() {//进行L操作
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
    ha[4] = '\0';//字符串结尾加\0
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
```