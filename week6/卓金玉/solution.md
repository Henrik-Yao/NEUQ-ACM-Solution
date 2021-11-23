# WEEK6 周报
## 7-1 字符串模式匹配（KMP）
### 题面
给定一个字符串 text 和一个模式串 pattern，求 pattern 在text 中的出现次数。text 和 pattern 中的字符均为英语大写字母或小写字母。text中不同位置出现的pattern 可重叠。

**输入格式:**
输入共两行，分别是字符串text 和模式串pattern。

**输出格式:**
输出一个整数，表示 pattern 在 text 中的出现次数。

**输入样例:**
在这里给出一组输入。例如：
```
zyzyzyz
zyz
结尾无空行
```
**输出样例:**

```
3
结尾无空行
```
### 思路
定义int型kmp函数，直接返回找到的模式串个数

### 代码
```c++

#include <bits/stdc++.h>
using namespace std;
string s, p;
int Next[1000005];
void getNext()
{
    Next[0] = -1;
    int i = 0, len = -1;
    while (i < p.size())
    {
        if (len == -1 || p[i] == p[len])
        {
            i++, len++;
            Next[i] = len;
        }
        else
        {
            len = Next[len];
        }
    }
}

int kmp()
{
    int i = 0, len = 0;
    int cnt = 0;
    getNext();//计算模式串的next数组
    while (i < s.size())
    {
        if (len == -1 || p[len] == s[i])
            i++, len++;
        else
            len = Next[len];
        if (len == p.size())
        {
            cnt++;
            len = Next[len];
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);//快速输入输出
    getline(cin, s);
    getline(cin, p);
    int sum = kmp();
    cout << sum << endl;

    return 0;
}
```

## 7-2 妈妈再也不用担心我被拖库啦！
### 题面
众所周知，互联网时代以来各大公司被“脱裤”的历史是一部五彩缤纷（误）的血泪史，给各大厂商造成了极大的经济损失。更为重要的是，由于有些用户在多个网站使用相同的用户名、密码，一旦一家网站被拖库，用户往往会遭受全方位的损失。为避免此情况，良心企业一般只在数据库中存储用户密码的哈希值——也就是根据特定规则产生的散列值，无法由此倒推出原密码。但这种方法也有一个缺点，即输入不同的密码有极小概率会得到一样的哈希值（我们称之为碰撞），从而被系统认定密码正确！现在你所在的公司采取如下方法产生密码字符串（长度至少为8，只包含大小写字母和数字）的哈希值：

不区分字母的大小写，沿用16进制A代表10，B代表11……的规律，将原字符串视为一串36进制的数字
将字符串平均划为4块，若无法平均划分，保证在前的分块不短于在后的分块，且长度差不超过1。如：长度26的字符串各分块长度为7、7、6、6，长度13的字符串各分块长度为4、3、3、3
将每块的数字加和，取其个位数，四块取出的四个36进制数字顺次连接，得到一个四位36进制数字，即为该密码字符串的哈希值。
然而由于这种方式过于睿智，使得碰撞的几率奇高，你的任务就是为公司防范风险，在碰撞发生的时候给予示警！
**输入格式:**
第一行一个整数N（N<1000），为操作的个数。 以下N行，每行一个字符、两个字符串（length<100），中间均以空格分隔。字符代表操作类型，两个字符串代表用户名和密码。

当字符为L时，代表以该用户名密码尝试登录；

当字符为R时，代表尝试注册这组用户名、密码，若注册成功则记录在案。

**输出格式:**
N行，对于每一个L（登录操作），若密码正确，则输出一行“Success！”；

若密码错误或用户不存在，则输出一行“Failed！”；

若密码错误但会通过哈希检测而被放行，则输出一行“Attention！”。

对于每一个R（注册操作），若已存在该用户名，则输出一行“Repeated！”；

否则注册成功，输出一行“Signed！”。

以上输出均不包括引号。

**输入样例:**
```
5
R IronMan 1234qwerasdf
R IronMan whejrdfs345
L IronMan 1234qwerasdf
L IronMan whejrdfs345
L IronMan 0km6trlhdcwc
结尾无空行
```
**输出样例:**
```
Signed!
Repeated!
Success!
Failed!
Attention!
结尾无空行
```

### 思路
用户数据存在map里，键是账号，值是密码和该密码按题意求出的哈希值，具体见注释

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
map<string, pair<string, string>> depo;
char part(string s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); ++i)
        (s[i] >= '0' && s[i] <= '9') ? sum += s[i] - '0' : sum += tolower(s[i]) - 'a' + 10;
    sum %= 36; //取36进制的个位
    return sum < 10 ? sum + '0' : sum - 10 + 'a';
}
string Hash(string s)
{
    string hash = "0000"; //设初值，不然会无端碰撞
    int l = s.length();
    int len[4] = {0}; //长度数组
    for (int i = 0; i < l % 4; ++i)
    {
        len[i]++;
    }
    int t = 0;
    for (int i = 0; i < 4; ++i)
    {
        len[i] += l / 4;
        string s1 = s.substr(t, len[i]);
        t += len[i];
        char h = part(s1);
        hash[i] = h;
    }
    return hash;
}
int main(void)
{
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char ch;
        string account, password, hash;
        cin >> ch >> account >> password;
        hash = Hash(password);
        if (ch == 'R')
        {
            if (depo.find(account) != depo.end()) //用户已存在
                cout << "Repeated!" << endl;
            else //向库中存数据
            {
                depo[account].first = password;
                depo[account].second = hash;
                cout << "Signed!" << endl;
            }
        }
        else if (depo.find(account)->second.first == password) //账号密码匹配
            cout << "Success!" << endl;
        else if (depo.find(account)->second.second == hash) //账号密码不匹配但撞哈希值
            cout << "Attention!" << endl;
        else
            cout << "Failed!" << endl;
    }
    return 0;
}
```

## 7-3 子字符串个数匹配
### 题面
分别输入两个字符串A和B，A由多个小字符串组成（中间由非字母隔开），B是由字母组成的字符串。求出A中包含B的小字符串的个数（详细看样例），并且输出它。（不区分大小写）

**输入格式:**
先输入字符串A，由回车结束。然后输入字符串B。

**输出格式:**
输出A中包含B字符串的个数、

**输入样例:**
```
aaBbc4./ewfeAbc  wefW%!%&aAbc++0 4Abccabc
aBc
结尾无空行
```
**输出样例:**
```
3
结尾无空行
```

### 思路
用了扎瓦，把模式串ps变小写，正则表达式匹配字母，matcher得到分开后的子串，然后在子串里用contain找有没有模式串ps

### 代码
```java
import java.util.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String regex = "[a-zA-Z]+";
		String s = in.nextLine();
		String ps=in.nextLine();
		ps=ps.toLowerCase();
		int cnt=0;
		Pattern pattern;
		Matcher matcher;
		pattern=Pattern.compile(regex);
		matcher=pattern.matcher(s);
		
		while(matcher.find())
		{
	         String str = matcher.group().toLowerCase(); 
	         if(str.contains(ps))
	         {
	        	 cnt++;
	         }
	    }
		System.out.print(cnt);
	}

}
```

