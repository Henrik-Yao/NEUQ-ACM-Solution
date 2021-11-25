# 7-1 词典

你刚从滑铁卢搬到了一个大城市，这里的人们讲一种难以理解的外语方言。幸运的是，你有一本字典来帮助你理解它们。

### 输入格式:

输入第一行是正整数N和M,后面是N行字典条目（最多10000条），然后是M行要翻译的外语单词（最多10000个）。每一个字典条目都包含一个英语单词，后面跟着一个空格和一个外语单词。 输入中的每个单词都由最多10个小写字母组成。

### 输出格式:

输出翻译后的英文单词，每行一个单词。非词典中的外来词汇输出“eh”。

### 输入样例:

```in
5 3
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay
atcay
ittenkay
oopslay
```

### 输出样例:

```out
cat
eh
loops
```

### 分析：

典型map；

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<string, string>ys;
	for (int i = 1; i <= n; i++) {
		string p, q;
		cin >> p >> q;
		ys[q] = p;
	}
	for (int i = 1; i <= m; i++) {
		string x;
		cin >> x;
		if (ys.count(x))
			cout << ys[x] << endl;
		else
			cout << "eh" << endl;
	}
	return 0;
}
```



# 7-2 神秘密码

传说二战时X国收到了上帝的一串密码，只有解开密码，才能阻止战争的继续进行，世界才会恢复和平。解开密码的第一道工序就是解压缩密码，上帝对于连续的若干个相同的子串"X"会压缩为"[DX]"的形式(D是一个整数且1<=D<=99),比如说字符串"CBCBCBCB"就压缩为"[4CB]"或者"[2[2CB]]",类似于后面这种压缩之后再压缩的称为二重压缩。如果是"[2[2[2CB]]]"则是三重的。现在我们给你上帝发送的密码，请你对其进行解压缩。

### 输入格式:

一个字符串

### 输出格式:

一个字符串

### 输入样例:

```in
AC[3FUN]



结尾无空行
```

### 输出样例:

在这里给出相应的输出。例如：

```out
ACFUNFUNFUN



结尾无空行
```

分析：碰到[作为一个整体

```c++
#include <bits/stdc++.h>
using namespace std;

string read() {
	int n;
	string s, p;
	char ch;
	while (cin >> ch) {
		if (ch == '[') {
			cin >> n;
			p = read();
			for (int i = 0; i < n; i++)
				s += p;
		} else if (ch == ']')
			return s;
		else
			s += ch;
	}
}

int main() {
	cout << read();
	return 0;
}

```

# 7-3 删除公共字符

输入两个字符串，从第一个字符串中删除第二个字符串中的所有字符。例如，输入“They are students.”和“aeiou”，则删除之后的第一个字符串变成“Thy r stdnts”。

### 输入格式:

输入包含多组测试，每个测试输入包含两个字符串。

### 输出格式:

输出删除后的字符串。

### 输入样例:

```in
They are students.
aeiou结尾无空行
```

### 输出样例:

```out
Thy r stdnts.



结尾无空行
```

### 分析：

用map统计一下，是否存在过。

```c++
#include <bits/stdc++.h>
using namespace std;
map<char, int >a[1000];

int main() {
	int cnt = 0;
	string text, pattern;
	while (getline(cin, text) && getline(cin, pattern)) {
		for (int i = 0; i < pattern.length(); i++)
			a[cnt][pattern[i]] = 1;
		for (int i = 0; i < text.length(); i++) {
			if (a[cnt][text[i]] != 1)
				cout << text[i];
		}
		cnt++;
		cout << endl;
	}
	return 0;
}
```

# 7-4 最长有序子序列

对于给定一个数字序列 (*a*1，*a*2，…，*a**n*) ，如果满足*a*1<*a*2<…<*a**n*，则称该序列是有序的。若在序列(*a*1，*a*2，…，*a**n*) 中删除若干元素得到的子序列是有序的，则称该子序列为一个有序子序列。有序子序列中长度最大的即为最长有序子序列。

例如，(1，3，5)、(3，5，8)、(1，3，5，9)等都是序列 (1，7，3，5，9，4，8) 的有序子序列；而(1，3，5，9)、(1，3，5，8)、(1，3，4，8)都是序列 (1，7，3，5，9，4，8)的一个最长有序子序列，长度为4。

请编写程序，求出给定数字序列中的最长有序子序列的长度。

### 输入格式:

首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据第一行输入一个整数 n（1≤n≤1000），第二行输入n个整数，数据范围都在[0，10000]，数据之间以一个空格分隔。

### 输出格式:

对于每组测试，输出n个整数所构成序列的最长有序子序列的长度。每两组测试的输出之间留一个空行。

### 输入样例:

```in
1
7
1 7 3 5 9 4 8
```

### 输出样例:

```out
4
```

### 出处:

ZOJ 2136

### 分析：

若b[i] b[j]一样大，在a[i]<a[j]时是上升序列。

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, a[1000], b[1000];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = 1;
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i] > a[j] && b[j] > b[i] - 1) {
					b[i] = b[j] + 1;
				}
			}
		}
		int m = b[0];
		for (int i = 1; i < n; i++) {
			if (b[i] > m)
				m = b[i];
		}
		cout<<m<<endl;
		if (t)
			cout << endl;
	}
}
```



# 7-5 0-1背包问题

给定n种物品（每种仅一个）和一个容量为c的背包，要求选择物品装入背包，使得装入背包中物品的总价值最大。

### 输入格式:

测试数据有多组，处理到文件尾。每组测试数据输入3行，第1行为两个整数n（1≤n≤400）和c (1≤c≤1500)，分别表示物品数量与背包容量，第二行为n个物品的重量*w**i*（1≤i≤n），第三行为这n个物品的价值*v**i*（1≤i≤n）。物品重量、价值都为整数。

### 输出格式:

对于每组测试，在一行上输出一个整数，表示装入背包的最大总价值（结果保证在int范围内）。

### 输入样例:

```in
4 9
2 3 4 5
3 4 5 7
```

### 输出样例:

```out
12
```

### 出处:

HLOJ 1006、

### 分析：

01背包问题。

```c++
#include <bits/stdc++.h>
using namespace std;
int dp[401][20000];

int main() {
	int n, c, v[1500], w[1500];//n物品数量，c背包容量
	while (cin >> n >> c) {

		for (int i = 0; i < n; i++) {
			cin >> w[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= c; j++) {
				if (w[i] > j)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
			}
		}
		cout << dp[n][c] << endl;
	}
	return 0;
}
```

