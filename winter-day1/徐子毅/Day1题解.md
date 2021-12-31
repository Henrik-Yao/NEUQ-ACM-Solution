***

# 7-1 动态区间求和

>请编写程序对数组*a*1,*a*2,...,*a**n*进行如下操作 ：
>
>1 *i* *x*：给定*i*,*x*，将*a**i* 加上*x* ；
>
>2 *l* *r*：给定*l*,*r*，求*a**l*+*a**l*+1+...+*a**r*的值。
>
>### 输入格式:
>
>第一行包含2个正整数*n*和*q*，表示数组长度和查询个数。保证1≤*n*,*q*≤106。 第二行*n*个>整数*a*1,*a*2,...,*a**n*，表示初始数组。保证∣*a**i*∣≤106。 接下来*q*行，每行为一个操作。 保证 1≤*l*≤*r*≤*n*,∣*x*∣≤106。
>
>### 输出格式:
>
>对于每个 2 *l* *r* 操作输出一行，每行有一个整数，表示所求的结果。
>
>### 输入样例:
>
>```in
>3 2
>1 2 3
>1 2 0
>2 1 3
>```
>
>### 输出样例:
>
>```out
>6
>```

树形数组的简单应用。

lowbit的含义：是一个数的二进制右往左的第一位1与后面所有的0构成的新二进制数的值。

如12=(00001100)<sub>2</sub> 所以其lowbit值为(100)<sub>2</sub>=4。

利用树形数组，可以快速Update数据和Say数据。数形数组里存的数字是该数字前lowbit数的总和。

```C++
#include <iostream>
using namespace std;
long long t[1000005];
long long N;
long long lowbit(long long n){
	return (n)&(-n);
}
void updata_data(long long s1,long long s2){
	for(long long i=s1;i<=N;i+=lowbit(i)) t[i]+=s2;
}
long long sum_data(long long s){
	long long sum=0;
	for(long long i=s;i>0;i-=lowbit(i)) sum+=t[i];
	return sum;
}
int main(){
	long long q,num;
	cin >> N >> q;
	for(long long i=1;i<=N;i++){
		cin >> num;
		updata_data(i,num);
	}
	long long op;
	for(long long T=1;T<=q;T++){
		cin >> op;
		if(op==2){
			long long s1,s2;
			cin >> s1 >> s2;
			cout << sum_data(s2)-sum_data(s1-1	) << endl;
		}else if (op==1){
			long long s1,s2;
			cin >> s1 >> s2;
			updata_data(s1,s2);
		}
	}
}
```

***

# 7-2 **小明打字**

>小明正使用Microsoft Word打一篇文档，文档只包含a-z的小写字母和空格，在打字过程中可能会一次或多次按下Home键、End键、←方向键、→方向键、Insert键、Backspace键。请编写程序，给定小明在键盘上按键的序列，输出小明屏幕上最终显示的文本。 提示：Home键会将当前光标移至文本开始位置，End键当前光标移至文本尾，←键和→键会使当前光标左移或右移一个位置（如果光标在文档头则无法左移，光标在文档尾则无法右移），Insert键会在插入和替换文本间切换（默认是插入状态），Backspace键会删除当前光标前的一个字符。
>
>### 输入格式:
>
>输入为不超过50000个字符，表示小明的按键序列。包含a-z的小写字母、空格以及字符[、]、{、}、-、=。其中字符“[”表示Home键，“]”表示End键，“{”表示←键，“}”表示→键，“-”表示Insert键，“=”表示Backspace键。
>
>### 输出格式:
>
>输出为在小明屏幕上最终显示的文本。最后一个字母后没有回车或换行。
>
>### 输入样例1:
>
>```in
>jilin[i lofe{{-v-} ] universiti=y
>```
>
>### 输出样例1:
>
>```out
>i love jilin university
>```
>
>### 输入样例2:
>
>```in
>abcd[c-de
>```
>
>### 输出样例2:
>
>```out
>cdecd
>```
>
>### 输入样例3:
>
>```in
>[[]][][]happy=birthday
>```
>
>### 输出样例3:
>
>```out
>happbirthday
>```
>
>### 输入样例4:
>
>```in
>efg[bbb}}=}}}}=[{{{{a
>```
>
>### 输出样例4:
>
>```out
>abbbe
>```

双向链表，方便左右移动。

Home键直接定位到head。

End键遍历到末尾，也就是next为NULL的位置。

左右直接跳到上一或者下一的节点。

需要注意的是插入节点时不要出野指针。

```C++
#include <iostream>
#include <cstring>
using namespace std;
struct Word{
	char data;
	Word* next=NULL;
	Word* prior=NULL;
};
int main(){
	Word * head=new Word;
	Word *p=new Word;
	p=head;
	head->prior=NULL;
	char ch;
	bool insert=false;
    string str;
    getline(cin,str);
	for(int i=0;i<str.size();i++){
        ch=str[i];
		if(ch=='['){
			p=head;
		}else if(ch==']'){
			while(p->next!=NULL) p=p->next;
		}else if(ch=='{'){
			if(p->prior!=NULL) p=p->prior;
		}else if(ch=='}'){
			if(p->next!=NULL) p=p->next;
		}else if(ch=='='){
			Word *need_delete=p;
			p=p->prior;
			if(need_delete->next!=NULL) need_delete->next->prior=p;
			else p->next=NULL;
			p->next=need_delete->next;
			delete need_delete;
		}else if(ch=='-'){
			if(insert==true) insert=false;
			else insert=true;
		}else{
			if(insert&&p->next!=NULL){
				p=p->next;
				p->data=ch;
			}else if(!insert){
				Word *newin=new Word;
				newin->data=ch;
				newin->prior=p;
				newin->next=p->next;
				if(p->next!=NULL){
					Word *nextdata=p->next;
					nextdata->prior=newin;
				}
				p->next=newin;
				p=p->next;
			}
		}
	}
	p=head->next;
	for(;p!=NULL;p=p->next) 
		cout << p->data;
	return 0;
}
```

***

# **7-3 特殊约瑟夫问题**

>编号为1…N的N个小朋友玩游戏，他们按编号顺时针围成一圈，从第一个人开始按逆时针次序报数，报到第M个人出列；然后再从下个人开始按顺时针次序报数，报到第K个人出列；再从下一个人开始按逆时针次序报数，报到第M个人出列；再从下个人开始按顺时针次序报数，报到第K个人出列……以此类推不断循环，直至最后一人出列。请编写程序按顺序输出出列人的编号。
>
>![pic.jpg](https://images.ptausercontent.com/bba20cff-26eb-4fc1-bc02-5e09871642ad.jpg)
>
>### 输入格式:
>
>输入为3个正整数，分别表示N、M、K，均不超过1000。
>
>### 输出格式:
>
>输出为一行整数，为出列人的编号。每个整数后一个空格。
>
>### 输入样例:
>
>```in
>6 3 5
>```
>
>### 输出样例:
>
>```out
>5 3 1 2 4 6 
>```

~~猴子选大王（~~

~~朴素算法可~~

我当场循环双向链表，很快啊。

```C++
#include <iostream>
using namespace std;
struct kids{
	int num;
	kids*next=NULL;
	kids*prior=NULL;
};
int main(){
	int N,M,K;
	cin >> N >> M >> K;
	kids * head=new kids;
	kids * p = new kids;
	p=head;
	for(int i=1;i<=N;i++){
		kids* newkids=new kids;
		newkids->num=i;
		newkids->prior=p;
		p->next=newkids;
		p=p->next;
	}
    //让链表循环
	p->next=head->next;
	head->next->prior=p;
	int playing=N;
	bool right_circle=true;
	p=p->next;
	while(playing>0){
		if(right_circle){
			for(int T=1;T<M;T++) 
			p=p->prior;
			kids * need_delete=p;
			p=p->prior;
			p->next=need_delete->next;
			need_delete->next->prior=p;
			playing--;
			cout << need_delete->num << " ";
			right_circle=false;
		}else{
			for(int T=1;T<K;T++) p=p->next;
			kids * need_delete=p;
			p=p->next;
			p->prior=need_delete->prior;
			need_delete->prior->next=p;
			playing--;
			cout << need_delete->num << " ";
			right_circle=true;
		}
	}
	return 0;
}
```

***

# **7-4 程序设计综合实践 1.4**

>1.4 编写程序，输入若干正整数，按从小到大次序建立1个带头结点单链表，设计一个实现单链表分离算法的Split函数，将原单链表中值为偶数的结点分离出来形成一个新单链表，新单链表中头结点重新申请，其余结点来自原链表，分离后，原链表中只剩非偶数值所在结点，最后显示2个单链表，在程序退出前销毁单链表。要求Split算法时间复杂性达到O（n）,程序不可存在内存泄漏。
>
>### 输入格式:
>
>若干正整数。
>
>### 输出格式:
>
>每个单链表输出占一行，元素间用分隔符->分隔；初始单链表、剩余元素单链表、偶数元素单链表，共3行。
>
>### 输入样例:
>
>```in
>100 2 3  50 2 1 5 8
>```
>
>### 输出样例:
>
>```out
>1->2->2->3->5->8->50->100
>1->3->5
>2->2->8->50->100
>```

~~这题不清楚我为什么一直报格式错误？？？~~

~~所以我直接暴力求解了，链表再见www~~

这是格式错误的代码：

```C++
#include <iostream>
using namespace std;
struct Nums{
	int num;
	Nums *next=NULL;
};
Nums *head_origin=new Nums;
Nums *head_odd=new Nums;
Nums *head_even=new Nums;
Nums *p=new Nums;
void Split(){
	p=head_origin->next;
	Nums *p_o=new Nums;
	Nums *p_e=new Nums;
	p_o=head_odd;
	p_e=head_even;
	while(p!=NULL){
		Nums *newin=new Nums;
		newin->num=p->num;
		if(newin->num%2==0){
			p_e->next=newin;
			p_e=p_e->next;
		}else{
			p_o->next=newin;
			p_o=p_o->next;
		}
		p=p->next;
	}
}
int main(){
	int n;
	while(cin>>n){
		p=head_origin;
		Nums * newin=new Nums;
		newin->num=n;
		while(p->next!=NULL&&p->next->num<n) p=p->next;
		if(p->next==NULL) {p->next=newin;}
		else {
			newin->next=p->next;
			p->next=newin;
		}
	}
	p=head_origin->next;
	while(p!=NULL) {if(p->next==NULL) cout << p->num << endl; else cout << p->num << "->";p=p->next;}
	Split();
	p=head_odd->next;
	while(p!=NULL) {if(p->next==NULL) cout << p->num << endl; else cout << p->num << "->";p=p->next;}
	p=head_even->next;
	while(p!=NULL) {if(p->next==NULL) cout << p->num << endl; else cout << p->num << "->";p=p->next;}
    delete head_origin;
    delete head_odd;
    delete head_even;
}
```

这是~~暴力破解~~朴素算法的代码：

```C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> origin;
vector<int> odds;
vector<int> even;
int main(){
	int n;
	while(cin>>n){
		origin.push_back(n);
	}
	sort(origin.begin(),origin.end());
	bool first=true;
	for(int i=0;i<origin.size();i++){
		if(origin[i]%2==0) even.push_back(origin[i]);
		else odds.push_back(origin[i]);
		if(first) {cout << origin[i];first=false;}
		else cout << "->" << origin[i];
	}
	cout << endl;
	first=true;
	for(int i=0;i<odds.size();i++){
		if(first) {cout << odds[i];first=false;}
		else cout << "->" << odds[i];
	}
	cout << endl;
	first=true;
	for(int i=0;i<even.size();i++){
		if(first) {cout << even[i];first=false;}
		else cout << "->" << even[i];
	}
}
```

***

# 7-5 括号匹配

> 请编写程序判断一个包含“（”和“）”的括号序列是否匹配。如匹配则输出Match；如不匹配，计算出使该序列变为匹配序列所需添加的最少括号数目（只允许在该序列开始和结尾处添加括号），并输出经添加最少括号后得到的合法匹配序列。
>
> ### 输入格式:
>
> 输入为若干行，每行一个字符串，包含不超过105个括号。输入行数不超过10行。
>
> ### 输出格式:
>
> 对于输入的每个括号序列输出1行或2行信息。若输入的括号序列匹配，则输出Match。若不匹配，则输出分为2行，第1行为一个整数，表示将该序列变为匹配序列所需添加的最少括号数目，第2行为一个字符串，表示经添加最少括号后得到的合法匹配序列。
>
> ### 输入样例:
>
> ```in
> (())()
> )(
> ()))((
> ```
>
> ### 输出样例:
>
> ```out
> Match
> 2
> ()()
> 4
> ((()))(())
> ```

匹配括号，上栈。

新 '(' 栈进，得 ')' 栈出。

无 '(' 加 '('，多 '(' 加 ')' 。

```C++
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<char> st;
int main(){
	string str;
	while(cin>>str){
		int lnum=0;
		int rnum=0;
		for(int i=0;i<str.size();i++){
			if(str[i]=='(') st.push(str[i]);
			if(str[i]==')'){
				if(st.empty()) lnum++;
				else st.pop();
			}
		}
		while(!st.empty()){rnum++;st.pop();}
		if(st.empty()&&lnum==0&&rnum==0) cout << "Match" << endl;
		else{
			cout << rnum+lnum << endl;
			for(int i=1;i<=lnum;i++) cout << '(';
			cout << str;
			for(int i=1;i<=rnum;i++) cout << ')';
			cout << endl;
		}
	}
	return 0;
}
```

~~这不是暴力吗？~~

***

# **7-6 字符串对称**

> 编写一个算法利用顺序栈判断一个字符串是否是对称串。所谓对称串是指从左向右读和从右向左读的序列相同。
>
> ### 输入格式:
>
> 输入一个无空格的字符串。
>
> ### 输出格式:
>
> 如果该字符是对称的，输出yes，否则输出no。
>
> ### 输入样例:
>
> 在这里给出一组输入。例如：
>
> ```in
> abba
> ```
>
> ### 输出样例:
>
> 在这里给出相应的输出。例如：
>
> ```out
> yes
> ```
>
> ### 输入样例:
>
> 在这里给出一组输入。例如：
>
> ```in
> abcd
> ```
>
> ### 输出样例:
>
> 在这里给出相应的输出。例如：
>
> ```out
> no
> ```

同上，前半部分进栈，后半部分出栈。

区分长度的奇偶。

```C++
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<char> st;
int main(){
	string str;
	cin >> str;
	int i;
	for(i=0;i<str.size()/2;i++){
		st.push(str[i]);
	}
	if(str.size()%2!=0) i++;//奇数跳一次
	for(;i<str.size();i++){
		if(str[i]==st.top()){st.pop();}
		else{cout << "no" << endl;return 0;}
	}
	cout << "yes" << endl;
	return 0;
}
```

***

# **7-7 魔王语言解释**

> 有一个魔王总是使用自己的一种非常精练而抽象的语言讲话，没人能听的懂。但他的语言是可以逐步解释成人能懂得语言的，因为他的语言是由以下两种形式的规则由人的语言逐 步抽象上去的：   
>
> 1. α->β1β2...βn 
> 2. (θδ1δ2...δn)->θδnθδn-1...θδ1θ   在这两种形式中，从左到右均表示解释；从右到左表示抽象。试写一个魔王解释系统，把他的话解释成人能听懂得话。 [基本要求]   用下述两条具体规则和上述规则形式（2）实现。设大写字母表示魔王语言的词汇；小写字   母表示人的语言词汇；希腊字母（a,b1,s,y1等）表示可以用大写或小写字母代换的变量。   
>
> 魔王语言可含人的词汇。    
>
> 1. B->tAdA  
> 2. A->sae
>
> ### 输入格式:
>
> 输入一串带有大小写子字母的字符串其中小写字母用圆括号括起来。例如：B（einxgz）B# 。
>
> ### 输出格式:
>
> 根据魔王语言翻译逻辑，输出答案。例如：tsaedsaeezegexeneietsaedsae。
>
> ### 输入样例:
>
> 在这里给出一组输入。例如：
>
> ```in
> B(einxgz)B#
> ```
>
> ### 输出样例:
>
> 在这里给出相应的输出。例如：
>
> ```out
> tsaedsaeezegexeneietsaedsae
> ```

~~果然是魔王，我看了半天才能看懂一点题目什么意思~~。

字符串替换题，注意到括号里面是要把字母逆序出来，所以可以加栈。

```C++
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
stack<char> wt;
int main(){
	string str;
	cin >> str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='A') cout << "sae";
		else if(str[i]=='B') cout << "tsaedsae";
		else if(str[i]=='('){
			char ors=str[i+1];
            cout << ors;
			int j;
			for(j=i+2;j<str.size();j++) if(str[j]>='a'&&str[j]<='z'){
				wt.push(str[j]);
			}
			while(!wt.empty()){
				cout << wt.top() << ors;
				wt.pop();
			}
			while(str[i]!=')') i++;
		}else if(str[i]>='a'&&str[i]<='z') cout << str[i];
	}
	cout << endl;
	return 0;
}
```

***

# **7-8 括号配对**

> 表达式中允许包含3种括号：圆括号、方括号和大括号。即小括号、中括号和大括号。 编写一个算法来判断表达式中的括号是否正确配对，要求利用栈的结构实现。
>
> ### 输入格式:
>
> 输入一行带圆括号、方括号和大括号的字符串。
>
> ### 输出格式:
>
> 若匹配，输出yes。若不匹配，输出no。。
>
> ### 输入样例:
>
> 在这里给出一组输入。例如：
>
> ```in
> ([1+2])
> 
> 
> 
> 结尾无空行
> ```
>
> ### 输出样例:
>
> 在这里给出相应的输出。例如：
>
> ```out
> yes
> 
> 
> 
> 结尾无空行
> ```
>
> ### 输入样例:
>
> 在这里给出一组输入。例如：
>
> ```in
> ([
> 
> 
> 
> 结尾无空行
> ```
>
> ### 输出样例:
>
> 在这里给出相应的输出。例如：
>
> ```out
> no
> 
> 
> 
> 结尾无空行
> ```

同7-6啊这不是，

栈空就是左括号对齐，检测过程中栈空就是右括号不对齐。

```C++
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<char> small;
stack<char> medium;
stack<char> big;
using namespace std;
int main(){
	string str;
	cin >>str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='(') small.push('(');
		if(str[i]=='[') medium.push('[');
		if(str[i]=='{') big.push('{');
		if(str[i]==')') if(small.empty()){cout << "no" << endl;return 0;} else small.pop();
		if(str[i]==']') if(medium.empty()){cout << "no" << endl;return 0;} else medium.pop();
		if(str[i]=='}') if(big.empty()){cout << "no" << endl;return 0;} else big.pop();
	}
	if(!small.empty()||!medium.empty()||!big.empty()) {cout << "no" << endl;return 0;}
	cout << "yes" << endl;
	return 0;
}
```

***

# **7-9 银行排队问题之单窗口“夹塞”版**

> 排队“夹塞”是引起大家强烈不满的行为，但是这种现象时常存在。在银行的单窗口排队问题中，假设银行只有1个窗口提供服务，所有顾客按到达时间排成一条长龙。当窗口空闲时，下一位顾客即去该窗口处理事务。此时如果已知第*i*位顾客与排在后面的第*j*位顾客是好朋友，并且愿意替朋友办理事务的话，那么第*i*位顾客的事务处理时间就是自己的事务加朋友的事务所耗时间的总和。在这种情况下，顾客的等待时间就可能被影响。假设所有人到达银行时，若没有空窗口，都会请求排在最前面的朋友帮忙（包括正在窗口接受服务的朋友）；当有不止一位朋友请求某位顾客帮忙时，该顾客会根据自己朋友请求的顺序来依次处理事务。试编写程序模拟这种现象，并计算顾客的平均等待时间。
>
> ### 输入格式:
>
> 输入的第一行是两个整数：1≤*N*≤10000，为顾客总数；0≤*M*≤100，为彼此不相交的朋友圈子个数。若*M*非0，则此后*M*行，每行先给出正整数2≤*L*≤100，代表该圈子里朋友的总数，随后给出该朋友圈里的*L*位朋友的名字。名字由3个大写英文字母组成，名字间用1个空格分隔。最后*N*行给出*N*位顾客的姓名、到达时间*T*和事务处理时间*P*（以分钟为单位），之间用1个空格分隔。简单起见，这里假设顾客信息是按照到达时间先后顺序给出的（有并列时间的按照给出顺序排队），并且假设每个事务最多占用窗口服务60分钟（如果超过则按60分钟计算）。
>
> ### 输出格式:
>
> 按顾客接受服务的顺序输出顾客名字，每个名字占1行。最后一行输出所有顾客的平均等待时间，保留到小数点后1位。
>
> ### 输入样例:
>
> ```in
> 6 2
> 3 ANN BOB JOE
> 2 JIM ZOE
> JIM 0 20
> BOB 0 15
> ANN 0 30
> AMY 0 2
> ZOE 1 61
> JOE 3 10
> ```
>
> ### 输出样例:
>
> ```out
> JIM
> ZOE
> BOB
> ANN
> JOE
> AMY
> 75.2
> ```

本题含有多种情况，

+ 有人加塞。
+ 无人加塞，但是时间超过60秒。
+ 刚好朋友处理完自己的事物，不用等待刚好加塞。
+ 到达时朋友run走了。
+ 窗口有空闲。
+ 只有俩人，只有一人。

```C++
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
struct Human{
	string name;
	int T;
	int P;
	int WaitingTime;
	bool solved=false;
};
map<string,int> Friends;
map<string,int>::iterator Iter;
queue<Human> Peoples;
int main(){
	int N,M;
	cin>>N>>M;
	int num;
	for(int i=1;i<=M;i++){
		cin >> num;
		string name;
		for(int T=1;T<=num;T++) {cin >> name;Friends[name]=i;}
	}
	Human a[N];
	for(int G=0;G<N;G++){
		cin>>a[G].name>>a[G].T>>a[G].P;
		if(a[G].P>60) a[G].P=60;
	}
	int timeconsume=0;
	for(int i=0;i<N;i++){
		if(a[i].solved==false){
			if(a[i].T>timeconsume) timeconsume=a[i].T;
			a[i].WaitingTime=timeconsume-a[i].T;
			timeconsume+=a[i].P;
			Iter=Friends.find(a[i].name);
			if(Iter==Friends.end()){
				a[i].solved=true;
				Peoples.push(a[i]);
			}else{
				a[i].solved=true;
				Peoples.push(a[i]);
				for(int j=i+1;j<N;j++){
					if(Friends[a[j].name]==Iter->second&&a[j].solved==false&&a[j].T<=timeconsume){
						a[j].WaitingTime=timeconsume-a[j].T;
						a[j].solved=true;
						Peoples.push(a[j]);
						timeconsume+=a[j].P;
					}
				}
			}
		}
	}
	int totalwaitingtime=0;
	while(!Peoples.empty()){
		totalwaitingtime+=Peoples.front().WaitingTime;
		cout << Peoples.front().name << endl;
		Peoples.pop();
	}
	printf("%.1f",(double)totalwaitingtime/(double)N);
}
```

***

# **7-10 列车车厢重排**

> 火车站的列车调度铁轨的结构如下所示： (Exit) 9 8 7 6 5 4 3 2 1 <==== ………………………………… <==== 8 4 2 5 3 9 1 6 7 (Entrance) 两端分别是一条入口（Entrance）轨道和一条出口（Exit）轨道，它们之间可能有N条平行的轨道。每趟列车从入口可以选择任意一条轨道进入排队，以方便最后有序从出口离开。在前例中有9趟列车，在入口处按照{8，4，2，5，3，9，1，6，7}的顺序排队等待进入。如果要求它们必须按序号递减的顺序从出口离开，则至少需要多少条平行铁轨用于调度？调度入队后，各个队列里车厢情况如何？
>
> **输入格式：** 输入第一行给出一个整数N (2 ≤ N ≤99 )，下一行给出从1到N的整数序号的一个重排列。数字间以空格分隔。
>
> **输出格式：** 第一行输出1号车厢所在的队列中的元素（车厢编号间以空格分隔），注意，调度时，车厢只进入队列等待，并不出队。 在第二行中输出可以将输入的列车按序号递减的顺序重排所需要最少的辅助铁轨（队列）条数。
>
> ### 输入样例:
>
> ```in
> 9
> 8 4 2 5 3 9 1 6 7
> ```
>
> ### 输出样例:
>
> ```out
> 8 4 2 1
> 4
> ```

每次保证要开走的话，那么每一个队列的前一个车厢必须比后一个车厢大。

第一次是 8 

​	新建一个轨道

​	此时轨道有 1:	8

第二次是 4

​	4<8

​	加到轨道1处

​	此时轨道有 1:	4 8

第三次是 2

​	2<4

​	加到轨道1处

​	此时轨道有 1:	2 4 8

第四次是 5

​	5>2

​	新建一个轨道

​	此时轨道有 1:	2 4 8

​						2:	5

................

这样下去就能找到最少的轨道数目了

需要标记有 1 的轨道的标号。

``` C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> origin;
vector<int> odds;
vector<int> even;
int main(){
	int n;
	while(cin>>n){
		origin.push_back(n);
	}
	sort(origin.begin(),origin.end());
	bool first=true;
	for(int i=0;i<origin.size();i++){
		if(origin[i]%2==0) even.push_back(origin[i]);
		else odds.push_back(origin[i]);
		if(first) {cout << origin[i];first=false;}
		else cout << "->" << origin[i];
	}
	cout << endl;
	first=true;
	for(int i=0;i<odds.size();i++){
		if(first) {cout << odds[i];first=false;}
		else cout << "->" << odds[i];
	}
	cout << endl;
	first=true;
	for(int i=0;i<even.size();i++){
		if(first) {cout << even[i];first=false;}
		else cout << "->" << even[i];
	}
}
```

