## Week6 字符串KMP与DP

### 7-1 字符串模式匹配（KMP）

给定一个字符串 text 和一个模式串 pattern，求 pattern 在text 中的出现次数。text 和 pattern 中的字符均为英语大写字母或小写字母。text中不同位置出现的pattern 可重叠。

### 输入格式:

输入共两行，分别是字符串text 和模式串pattern。

### 输出格式:

输出一个整数，表示 pattern 在 text 中的出现次数。

### 输入样例1:

```
zyzyzyz
zyz
结尾无空行
```

### 输出样例1:

```
3
结尾无空行
```

### 输入样例2:

```
AABAACAADAABAABA
AABA
结尾无空行
```

### 输出样例2:

```
3
结尾无空行
```

### 数据范围与提示:

1≤text, pattern 的长度 ≤106， text、pattern 仅包含大小写字母。

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;

int Next[1000005];
int ans=0;
string t,p;

void getnext() //建立next数组
{
	Next[0]=-1;
	int k=-1,j=0;
    int len = p.size();

	while(j<len)
	{
		if(k==-1||p[k]==p[j])
		{
			j++; k++;
			Next[j]=k;
		}
		else
			k=Next[k];
	}
	return;
}
void kmp(string x,string y) //使用KMP算法遍历
{
	int i=0,j=0;

	int len1 = x.size();
	int len2 = y.size();

	while(i < len1)
	{
		if(j==-1||x[i]==y[j])
		{
			j++; i++;
		}
		else
			j=Next[j];

		if(j >= len2)
		{
			ans++;
			j=Next[j];
		}
	}
	return;
}

int main()
{
	cin>>t>>p;

	getnext();
	kmp(t,p);

	cout<<ans;
}

```

----------------------------

### 7-2 妈妈再也不用担心我被拖库啦！

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

```
5
R IronMan 1234qwerasdf
R IronMan whejrdfs345
L IronMan 1234qwerasdf
L IronMan whejrdfs345
L IronMan 0km6trlhdcwc
结尾无空行
```

### 输出样例:

```
Signed!
Repeated!
Success!
Failed!
Attention!
结尾无空行
```

### 样例解释：

IronMan的密码为1234qwerasdf，会按照题设方法划分为【123】、【4qw】、【era】、【sdf】并求出哈希值6qfk，而0km6trlhdcwc按此法求出的哈希值也恰为6qfk，因此产生了哈希碰撞。

------------------------

### 7-3 子字符串个数匹配

分别输入两个字符串A和B，A由多个小字符串组成（中间由非字母隔开），B是由字母组成的字符串。求出A中包含B的小字符串的个数（详细看样例），并且输出它。（不区分大小写）

### 输入格式:

先输入字符串A，由回车结束。然后输入字符串B。

### 输出格式:

输出A中包含B字符串的个数、

### 输入样例:

在这里给出一组输入。例如：

```
aaBbc4./ewfeAbc  wefW%!%&aAbc++0 4Abccabc
aBc
结尾无空行
```

### 输出样例:

在这里给出相应的输出。例如：

```
3
结尾无空行
```

### 解释:

A可以看成:aabbc ewfeabc wefw aabc abccabc小字符串组成的字符串。

包含B的有：ewfeabc aabc abccabc (3个)

### 代码：

```c++
#include<bits/stdc++.h>
using namespace std;

int Next[1000005];
int ans=0;
string a,b,p,temp[1005];

void getnext();
int kmp(string x,string y);

int main()
{

	int j=0,k=0;
	int flag=0;

	getline(cin,a); //注意含有空格的输入用getline

	int lena = a.size();
	for(int i=0;i<=lena;i++)
	{
		if(a[i]>='a' && a[i]<='z')
		{
			b += a[i];
			flag=1;
		}
		else if(a[i]>='A' && a[i]<='Z')
		{
			b += a[i]+('a'-'A');
			flag=1;
		}
		else
		{
			if(flag==0)
			{
				b=""; continue;
			}
			else
			{
				temp[j]=b; j++; b="";
				flag=0;
			}
		}
	}

	cin>>p;
	for(int i=0;i<p.size();i++)
	{
		if(p[i]>='A' && p[i]<='Z')
		{
			p[i] += ('a'-'A');
		}
	}

	getnext();

	for(int i=0;i<j;i++)
		ans += kmp(temp[i],p);

	cout<<ans;
}

void getnext()
{
	Next[0]=-1;
	int len=p.size();
	int k=-1,j=0;
	while(j<len)
	{
		if(k==-1||p[k]==p[j])
		{
			j++; k++;
			Next[j]=k;
		}
		else
			k=Next[k];
	}
	return;
}

int kmp(string x,string y)
{
	int i=0,j=0;
	int len1=x.size();
	int len2=y.size();

	while(i<len1)
	{
		if(j==-1||x[i]==y[j])
		{
			j++; i++;
		}
		else
			j=Next[j];

		if(j>=len2)
			return 1;
	}
	return 0;
}


```





