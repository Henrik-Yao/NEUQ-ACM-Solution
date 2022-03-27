# 7-1 字符串模式匹配（KMP）

给定一个字符串 text 和一个模式串 pattern，求 pattern 在text 中的出现次数。text 和 pattern 中的字符均为英语大写字母或小写字母。text中不同位置出现的pattern 可重叠。

### 输入格式:

输入共两行，分别是字符串text 和模式串pattern。

### 输出格式:

输出一个整数，表示 pattern 在 text 中的出现次数。

### 输入样例1:

```in
zyzyzyz
zyz结尾无空行
```

### 输出样例1:

```out
3



结尾无空行
```

### 输入样例2:

```in
AABAACAADAABAABA
AABA结尾无空行
```

### 输出样例2:

```out
3



结尾无空行
```

### 分析：

当两个字符串不适配的时候，回溯回退的位置始终是模式串的不适配字符的上一位字符前后缀相同的位置。

```c++
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int nxt[N];
int cnt = 0;

void text_table(string p, int m) {
	nxt[0] = 0;
	int x = 1, now = 0;
	while (x < m) {
		if (p[now] == p[x]) {
			now++;
			nxt[x] = now;
			x++;
		} else if (now)
			now = nxt[now - 1];
		else
			nxt[x++] = 0;
	}
}

void search( string t, string p, int n, int m) {
	int i = 0, j = 0;
	while (i < n) {
		if (t[i] == p[j]) {
			i++;
			j++;
		} else if (j) {
			j = nxt[j - 1];
		} else
			i++;
		if (j == m) {
			cnt++;
			j = nxt[j - 1];
		}
	}

}

int main () {
	string text, pattern;
	cin >> text >> pattern;
	int n = text.length();
	int m = pattern.length();
	text_table(pattern, m);
	search(text, pattern, n, m);
	cout << cnt << endl;
	return 0;
}
```

# 7-2 妈妈再也不用担心我被拖库啦！

众所周知，互联网时代以来各大公司被“脱裤”的历史是一部五彩缤纷（误）的血泪史，给各大厂商造成了极大的经济损失。更为重要的是，由于有些用户在多个网站使用相同的用户名、密码，一旦一家网站被拖库，用户往往会遭受全方位的损失。为避免此情况，良心企业一般只在数据库中存储用户密码的**哈希值**——也就是根据特定规则产生的散列值，无法由此倒推出原密码。但这种方法也有一个缺点，即输入不同的密码有极小概率会得到一样的哈希值（我们称之为**碰撞**），从而被系统认定密码正确！现在你所在的公司采取如下方法产生密码字符串（长度至少为8，只包含大小写字母和数字）的哈希值：

1. 不区分字母的大小写，沿用16进制A代表10，B代表11……的规律，将原字符串视为一串36进制的数字
2. 将字符串平均划为4块，若无法平均划分，保证在前的分块不短于在后的分块，且长度差不超过1。如：长度26的字符串各分块长度为7、7、6、6，长度13的字符串各分块长度为4、3、3、3
3. 将每块的数字加和，取其个位数，四块取出的四个36进制数字顺次连接，得到一个四位36进制数字，即为该密码字符串的哈希值。

然而由于这种方式过于睿智，使得碰撞的几率奇高，你的任务就是为公司防范风险，在碰撞发生的时候给予示警！

### 输入格式:

第一行一个整数*N*（*N*<1000），为操作的个数。 以下N行，每行一个字符、两个字符串（*l**e**n**g**t**h*<100），中间均以空格分隔。字符代表操作类型，两个字符串代表用户名和密码。

当字符为L时，代表以该用户名密码尝试登录；

当字符为R时，代表尝试注册这组用户名、密码，若注册成功则记录在案。

### 输出格式:

N行，对于每一个L（登录操作），若密码正确，则输出一行“Success！”；

若密码错误或用户不存在，则输出一行“Failed！”；

若密码错误但会通过哈希检测而被放行，则输出一行“Attention！”。

对于每一个R（注册操作），若已存在该用户名，则输出一行“Repeated！”；

否则注册成功，输出一行“Signed！”。

以上输出均不包括引号。

### 输入样例:

```in
5
R IronMan 1234qwerasdf
R IronMan whejrdfs345
L IronMan 1234qwerasdf
L IronMan whejrdfs345
L IronMan 0km6trlhdcwc结尾无空行
```

### 输出样例:

```out
Signed!
Repeated!
Success!
Failed!
Attention!结尾无空行
```

### 样例解释：

IronMan的密码为1234qwerasdf，会按照题设方法划分为【123】、【4qw】、【era】、【sdf】并求出哈希值6qfk，而0km6trlhdcwc按此法求出的哈希值也恰为6qfk，因此产生了哈希碰撞。

### 分析：

熟悉map的操作，映射关系。

是否注册：record.count()==1;

哈希值相同：hash1=hash2(pwd1);hash1==hash2(pwd2)

```c++
#include <bits/stdc++.h>
using namespace std;
map<string, string>record;
map<string, vector<int>>hash1;

vector<int>hash2(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] - 'A' + 'a';
	}
	int x;
	vector<int>number;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			x = s[i] - '0';
		} else {
			x = s[i] - 'a' + 10;
		}
		number.push_back(x);//尾部添加元素。
	}
	vector<int>ans;//将字符串平均划为4块，保证在前的分块不短于在后的分块,长度不超过1。
	int ave = s.size() / 4, cnt = ave * 4, pos = 0;
	for (int k = 0; k < 4; k++) {
		int length = ave;
		if (cnt < s.size()) {
			cnt++;
			length++;
		}
		int n = 0;
		for (int j = pos; j <= length + pos - 1; j++) {
			n += number[j];
		}
		pos += length;
		ans.push_back(n % 36);
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		char action;
		string ID, pwd;
		cin >> action >> ID >> pwd;
		if (action == 'R') { //如果是注册操作
			if (record.count(ID)) //注册过
				puts("Repeated!");
			else { //没注册过
				record[ID] = pwd;
				hash1[ID] = hash2(pwd);
				puts("Signed!");
			}
		} else { //如果是登录操作
			if (!record.count(ID)) { //不存在该用户名
				puts("Failed!");
				continue;
			}
			if (record[ID] == pwd) { //密码正确
				puts("Success!");
				continue;
			}
			if (hash1[ID] == hash2(pwd)) //密码错误但哈希值相同
				puts("Attention!");
			else
				puts("Failed!");
		}
	}
	return 0;
}
```



# 7-3 子字符串个数匹配

分别输入两个字符串A和B，A由多个小字符串组成（中间由非字母隔开），B是由字母组成的字符串。求出A中包含B的小字符串的个数（详细看样例），并且输出它。（不区分大小写）

### 输入格式:

先输入字符串A，由回车结束。然后输入字符串B。

### 输出格式:

输出A中包含B字符串的个数、

### 输入样例:

在这里给出一组输入。例如：

```in
aaBbc4./ewfeAbc  wefW%!%&aAbc++0 4Abccabc
aBc结尾无空行
```

### 输出样例:

在这里给出相应的输出。例如：

```out
3



结尾无空行
```

解释:

A可以看成:aabbc ewfeabc wefw aabc abccabc小字符串组成的字符串。

包含B的有：ewfeabc aabc abccabc (3个)

### 分析：

先预处理，全部转换为小写字母，然后取出每一个字符串，分别对照。

```c++
#include <bits/stdc++.h>
using namespace std;
string t[10000];
int cnt = 0, cnt2 = 0;

void find(string t, string p) {
	int n = t.length();
	int m = p.length();
	int i = 0, j = 0;
	while (i < n - m + 1) {
		if (t.substr(i, m) == p) {
			cnt2++;
			break;
		}
		i++;
	}
}

int main() {
	string text, pattern;
	getline(cin, text);
	getline(cin, pattern);
	int n = text.length();
	int m = pattern.length();
	for (int i = 0; i < n; i++) {
		if (text[i] >= 'A' && text[i] <= 'Z')
			text[i] = text[i] + 32;
	}

	for (int i = 0; i < m; i++) {
		if (pattern[i] >= 'A' && pattern[i] <= 'Z')
			pattern[i] = pattern[i] + 32;
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		while (text[i + k] >= 'a' && text[i + k] <= 'z') {
			k++;
		}
		if (k > 0) {
			t[cnt++] = text.substr(i, k);
			i = i + k - 1;
			k = 0;

		}
	}
	for (int i = 0; i < cnt; i++) {
		find(t[i], pattern);
	}
	cout << cnt2 << endl;
	return 0;
}
```

