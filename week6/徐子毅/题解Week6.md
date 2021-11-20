***

# 7-1

> 给定一个字符串 text 和一个模式串 pattern，求 pattern 在text 中的出现次数。text 和 pattern 中的字符均为英语大写字母或小写字母。text中不同位置出现的pattern 可重叠。

KMP（都写在标题里了）

下面两个视频帮助了我很多。

[Video1-bilibili](https://www.bilibili.com/video/BV1Px411z7Yo?from=search&seid=4518136118839100745&spm_id_from=333.337.0.0)

[Video2-bilibili](https://www.bilibili.com/video/BV1hW411a7ys?from=search&seid=4518136118839100745&spm_id_from=333.337.0.0)

```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string pattern,text;
int findcatch=0;
int backvalue[100005];
void getbackvaluetable(string pattern){
	int ins = 0;
	for (int i = 1; i < pattern.size(); i++){
		if (pattern[i] == pattern[ins]){
			ins++;
			backvalue[i] = ins;
		}
		else{
			if (ins > 1)
				ins = backvalue[ins - 1];
			backvalue[i] = ins;
		}
	}
}
void movetable(int n){
	for(int i=n;i>0;i--){
		backvalue[i]=backvalue[i-1];
	}
	backvalue[0]=-1;
}
void kmpsearch(string pattern,string text){
	getbackvaluetable(pattern);
	movetable(pattern.size());
	int i=0,j=0;
	while(i<text.size()){
		if(j==pattern.size()-1&&text[i]==pattern[j]){
			findcatch++;
			j=backvalue[j];
		}
		if(text[i]==pattern[j]){
			i++;j++;
		}
		else{
			j=backvalue[j];
			if(j==-1){
				i++;j++;
			}
		}
	}
}
int main(){
	cin >> text;
	cin >> pattern;
	kmpsearch(pattern,text);
	cout << findcatch << endl;
	return 0;
}

```

***

# 7-2

>众所周知，互联网时代以来各大公司被“脱裤”的历史是一部五彩缤纷（误）的血泪史，给各大厂商造成了极大的经济损失。更为重要的是，由于有些用户在多个网站使用相同的用户名、密码，一旦一家网站被拖库，用户往往会遭受全方位的损失。为避免此情况，良心企业一般只在数据库中存储用户密码的**哈希值**——也就是根据特定规则产生的散列值，无法由此倒推出原密码。但这种方法也有一个缺点，即输入不同的密码有极小概率会得到一样的哈希值（我们称之为**碰撞**），从而被系统认定密码正确！现在你所在的公司采取如下方法产生密码字符串（长度至少为8，只包含大小写字母和数字）的哈希值：
>1. 不区分字母的大小写，沿用16进制A代表10，B代表11……的规律，将原字符串视为一串36进制的数字
>2. 将字符串平均划为4块，若无法平均划分，保证在前的分块不短于在后的分块，且长度差不超过1。如：长度26的字符串各分块长度为7、7、6、6，长度13的字符串各分块长度为4、3、3、3
>3. 将每块的数字加和，取其个位数，四块取出的四个36进制数字顺次连接，得到一个四位36进制数字，即为该密码字符串的哈希值。
然而由于这种方式过于睿智，使得碰撞的几率奇高，你的任务就是为公司防范风险，在碰撞发生的时候给予示警！

这道题按照题目要求一步一步来即可。

+ 首先要将密码打碎成三部分
``` C++
void breakstring(int n){//分成4部分的各部分长度
	s1=s2=s3=s4=n/4;
	n=n-s1*4;
	if(n>0) {s1++;n--;}
	if(n>0) {s2++;n--;}
	if(n>0) {s3++;n--;}
	return;
}
```

+ 再把一个字符转化为36进制（我这种方法过于麻烦）
```C++
int turn10(char n){
	if(n>='0'&&n<='9') return (int)(n-'0');
	else if(n>='a'&&n<='z') return (int)(n-'a')+10;
	else if(n>='A'&&n<='Z') return (int)(n-'A')+10;
}
char turn36(int n){
	if(n>=0&&n<=9) return (char)(n+'0');
	else if(n>=10&&n<=35) return (char)(n-10+'a');
	else return turn36(n-36);
}
```

+ 通过上面两个（三个）函数计算一串字符的哈希。

```C++
string Hashing(string str){
	string num="0000";
	int bnum=0;
	if(str.size()<=4) return str;
	breakstring(str.size());
	int i=0;
	for(i=0;i<s1;i++){
		bnum+=turn10(str[i]);
	}
	num[0]=turn36(bnum);
	bnum=0;
	for(;i<s1+s2;i++){
		bnum+=turn10(str[i]);
	}
	num[1]=turn36(bnum);
	bnum=0;
	for(;i<s1+s2+s3;i++){
		bnum+=turn10(str[i]);
	}
	num[2]=turn36(bnum);
	bnum=0;
	for(;i<str.size();i++){
		bnum+=turn10(str[i]);
	}
	num[3]=turn36(bnum);
	return num;
}
```

+ 最后再做主程序即可。
+ 下面是我极为复杂的代码。
```C++
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int s1,s2,s3,s4;
struct users{
	string name;
	string passwd;
	string hash;
};
vector<users> usersdata;
void breakstring(int n){
	s1=s2=s3=s4=n/4;
	n=n-s1*4;
	if(n>0) {s1++;n--;}
	if(n>0) {s2++;n--;}
	if(n>0) {s3++;n--;}
	return;
}
int turn10(char n){
	if(n>='0'&&n<='9') return (int)(n-'0');
	else if(n>='a'&&n<='z') return (int)(n-'a')+10;
	else if(n>='A'&&n<='Z') return (int)(n-'A')+10;
}
char turn36(int n){
	if(n>=0&&n<=9) return (char)(n+'0');
	else if(n>=10&&n<=35) return (char)(n-10+'a');
	else return turn36(n-36);
}
string Hashing(string str){
	string num="0000";
	int bnum=0;
	if(str.size()<=4) return str;
	breakstring(str.size());
	int i=0;
	for(i=0;i<s1;i++){
		bnum+=turn10(str[i]);
	}
	num[0]=turn36(bnum);
	bnum=0;
	for(;i<s1+s2;i++){
		bnum+=turn10(str[i]);
	}
	num[1]=turn36(bnum);
	bnum=0;
	for(;i<s1+s2+s3;i++){
		bnum+=turn10(str[i]);
	}
	num[2]=turn36(bnum);
	bnum=0;
	for(;i<str.size();i++){
		bnum+=turn10(str[i]);
	}
	num[3]=turn36(bnum);
	return num;
}
int main(){
/* 	
	string str;
	cin >> str;
	cout << Hashing(str) << endl;
	 */
	int abc;
	cin >> abc;
	char operation;
	string name,password;
	bool repeated;
	for(int i=1;i<=abc;i++){
		cin >> operation;
		repeated=false;
		if(operation=='R'){
			cin >> name >> password;
			for(int i=0;i<usersdata.size();i++){
				if(name==usersdata[i].name){
					cout << "Repeated!" << endl;
					repeated=true;
					break;
				}
			}
			if(!repeated){
				users newuser;
				newuser.name=name;
				newuser.passwd=password;
				newuser.hash=Hashing(password);
				usersdata.push_back(newuser);
				cout << "Signed!" << endl;
			}
		}
	    if(operation=='L'){
			cin >> name >> password;
			users compareduser;
			for(int i=0;i<usersdata.size();i++){
				if(name==usersdata[i].name){
					compareduser=usersdata[i];
					break;
				}
			}
			if(password==compareduser.passwd){
				cout << "Success!" << endl;
			}
			else{
				if(Hashing(password)==compareduser.hash) cout << "Attention!" << endl;
				else cout << "Failed!" << endl;
			}
		}
	}
	return 0;
}
```

***

# 7-3

> 分别输入两个字符串A和B，A由多个小字符串组成（中间由非字母隔开），B是由字母组成的字符串。求出A中包含B的小字符串的个数（详细看样例），并且输出它。（不区分大小写）

这也是一个KPM，直接照抄7-1，唯一的改动就是要把一串字符串给打碎分出来。

```C++
while(true){
	ch=getchar();
	if(ch=='\n') {if(!stra.empty())stras.push_back(stra);break;}
	else if(ch>='a'&&ch<='z'){
		stra+=ch;
	}else if(ch>='A'&&ch<='Z'){
		stra+=ch+32;
	}else{
		if(!stra.empty())stras.push_back(stra);
		stra.clear();
	}
}
```

```C++
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<string>stras;
int backvalue[100005];
void backvaluetable(string pattern){
	int ins = 0;
	for (int i = 1; i < pattern.size(); i++){
		if (pattern[i] == pattern[ins]){
			ins++;
			backvalue[i] = ins;
		}
		else{
			if (ins > 1)
				ins = backvalue[ins - 1];
			backvalue[i] = ins;
		}
	}
	for(int i=pattern.size();i>0;i--){
		backvalue[i]=backvalue[i-1];
	}
	backvalue[0]=-1;
}
int kmpsearch(string pattern,string text){
	int i=0,j=0;
	while(i<text.size()){
		if(j==pattern.size()-1&&text[i]==pattern[j]){
			return 1;
		}
		if(text[i]==pattern[j]){
			i++;j++;
		}
		else{
			j=backvalue[j];
			if(j==-1){
				i++;j++;
			}
		}
	}
	return 0;
}
int main(){
	char ch;
	string stra;
	string strb;
	while(true){
		ch=getchar();
		if(ch=='\n') {if(!stra.empty())stras.push_back(stra);break;}
		else if(ch>='a'&&ch<='z'){
			stra+=ch;
		}else if(ch>='A'&&ch<='Z'){
			stra+=ch+32;
		}else{
			if(!stra.empty())stras.push_back(stra);
			stra.clear();
		}
	}
	cin>>strb;
	backvaluetable(strb);
	for(int i=0;i<strb.size();i++){
		if(strb[i]>='A'&&strb[i]<='Z') strb[i]+=32;
	}
	int sum=0;
	for(int i=0;i<stras.size();i++){
		sum+=kmpsearch(strb,stras[i]);
	}
	cout << sum << endl;
	return 0;
}
```

