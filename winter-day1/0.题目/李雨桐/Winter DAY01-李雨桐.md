## Winter DAY01-李雨桐

## 7-1 动态区间求和

请编写程序对数组*a*1,*a*2,...,*a**n*进行如下操作 ：

1 *i* *x*：给定*i*,*x*，将*a**i* 加上*x* ；

2 *l* *r*：给定*l*,*r*，求*a**l*+*a**l*+1+...+*a**r*的值。

### 输入格式:

第一行包含2个正整数*n*和*q*，表示数组长度和查询个数。保证1≤*n*,*q*≤106。 第二行*n*个整数*a*1,*a*2,...,*a**n*，表示初始数组。保证∣*a**i*∣≤106。 接下来*q*行，每行为一个操作。 保证 1≤*l*≤*r*≤*n*,∣*x*∣≤106。

### 输出格式:

对于每个 2 *l* *r* 操作输出一行，每行有一个整数，表示所求的结果。

### 输入样例:

```in
3 2
1 2 3
1 2 0
2 1 3
```

### 输出样例:

```out
6
```

--------------------------------

## 7-2 小明打字

小明正使用Microsoft Word打一篇文档，文档只包含a-z的小写字母和空格，在打字过程中可能会一次或多次按下Home键、End键、←方向键、→方向键、Insert键、Backspace键。请编写程序，给定小明在键盘上按键的序列，输出小明屏幕上最终显示的文本。 提示：Home键会将当前光标移至文本开始位置，End键当前光标移至文本尾，←键和→键会使当前光标左移或右移一个位置（如果光标在文档头则无法左移，光标在文档尾则无法右移），Insert键会在插入和替换文本间切换（默认是插入状态），Backspace键会删除当前光标前的一个字符。

### 输入格式:

输入为不超过50000个字符，表示小明的按键序列。包含a-z的小写字母、空格以及字符[、]、{、}、-、=。其中字符“[”表示Home键，“]”表示End键，“{”表示←键，“}”表示→键，“-”表示Insert键，“=”表示Backspace键。

### 输出格式:

输出为在小明屏幕上最终显示的文本。最后一个字母后没有回车或换行。

### 输入样例1:

```in
jilin[i lofe{{-v-} ] universiti=y
```

### 输出样例1:

```out
i love jilin university
```

### 输入样例2:

```in
abcd[c-de
```

### 输出样例2:

```out
cdecd
```

### 输入样例3:

```in
[[]][][]happy=birthday
```

### 输出样例3:

```out
happbirthday
```

### 输入样例4:

```in
efg[bbb}}=}}}}=[{{{{a
```

### 输出样例4:

```out
abbbe
```

### 代码：

```c++
#include <bits/stdc++.h>
using namespace std;

typedef struct LNode
{
    char c;
    LNode* next;
    LNode* prev;
} * List;

int main()
{
    char c;
    List s,e,temp;
    List L= new LNode();
    s = e = temp = L;
    bool isInsert = true;
    List ins;
    while(scanf("%c",&c) &&c!='\n')
        {
        if (c=='[')
            temp = s;
        else if (c==']')
            temp=e;
        else if (c=='{')
            {
            if (temp->prev)
            temp=temp->prev;
            }
        else if (c=='}')
            {
            if (temp->next)
            temp=temp->next;
            }
        else if (c=='-')
            isInsert = !isInsert;
        else if (c=='=')
            {
            if (temp->prev)
            {
                List t = temp;
                temp->prev->next = temp->next;

                if (temp->next)
                {
                    temp->next->prev = temp->prev;
                    temp = temp->prev;
                }
                else
                {
                    temp = temp->prev;
                    temp->next=NULL;
                }
                delete t;
                if (temp->next==NULL)
                    e=temp;
            }
        }
        else
        {
            ins=new LNode();
            ins->c=c;
            ins->next=temp->next;
            ins->prev=temp;
            temp->next=ins;
            temp = ins;
            if (temp->next==NULL)
                e=temp;
            if (!isInsert&&temp->next)
            {
                List t=temp->next;
                if (t->next)
                {
                    temp->next=t->next;
                    t->next->prev=temp;
                    delete t;
                }
                else
                {
                    delete t;
                    e=temp;
                    temp->next=NULL;
                }
            }
        }

    }
    temp=s->next;
    while(temp>0)
    {
        printf("%c", temp->c);
        temp = temp->next;
    }
    return 0;
}


```

--------------------------------------

## 7-3 特殊约瑟夫问题

编号为1…N的N个小朋友玩游戏，他们按编号顺时针围成一圈，从第一个人开始按逆时针次序报数，报到第M个人出列；然后再从下个人开始按顺时针次序报数，报到第K个人出列；再从下一个人开始按逆时针次序报数，报到第M个人出列；再从下个人开始按顺时针次序报数，报到第K个人出列……以此类推不断循环，直至最后一人出列。请编写程序按顺序输出出列人的编号。

![pic.jpg](https://images.ptausercontent.com/bba20cff-26eb-4fc1-bc02-5e09871642ad.jpg)

### 输入格式:

输入为3个正整数，分别表示N、M、K，均不超过1000。

### 输出格式:

输出为一行整数，为出列人的编号。每个整数后一个空格。

### 输入样例:

```in
6 3 5
```

### 输出样例:

```out
5 3 1 2 4 6 
```

### 代码：

```c++
#include <bits/stdc++.h>
using namespace std;
struct linknode
{
	int data;
	struct linknode* next;
	struct linknode* prev;
};
int main()
{
	int n,m,k;
    cin>>n>>m>>k;

	struct linknode* p,*q,*g;
	p = (struct linknode*)malloc(sizeof(struct linknode));
	g=q=p;
	p->data = 1;
	p->next = p;
	for (int i=2;i<=n;i++)
	{
		q = (q->next = (struct linknode*)malloc(sizeof(struct linknode)));
        q->data=i;
		q->prev=g;
		q->next=p;
		g=g->next;
	}
	p->prev=g;
	q=p;

	while (q!=q->next)
	{
		if (m==1)
		{
			cout<<q->data<<' ';
			q->next->prev = q->prev;
			q->prev->next = q->next;
			q = q->prev;
		}
		else
		{
			for (int i = 2; i < m; i++)
				q = q->prev;
			cout<<q->prev->data<<' ';
			q->prev = q->prev->prev;
			q->prev->next = q;
			q = q->prev;
		}
		if (k==1)
		{
			cout<<q->data<<' ';
			q->next->prev = q->prev;
			q->prev->next = q->next;
			q = q->next;
		}
		else
		{
			for (int i=2; i<k;i++)
				q = q->next;
			cout<<q->next->data<<' ';
			q->next = q->next->next                                                                                                    ;
			q->next->prev = q;
			q = q->next;
		}
	}

	if (n%2==1)
		cout<<p->data<<' ';

	return 0;
}

```

---------------------------------

### 7-5 括号匹配

请编写程序判断一个包含“（”和“）”的括号序列是否匹配。如匹配则输出Match；如不匹配，计算出使该序列变为匹配序列所需添加的最少括号数目（只允许在该序列开始和结尾处添加括号），并输出经添加最少括号后得到的合法匹配序列。

### 输入格式:

输入为若干行，每行一个字符串，包含不超过105个括号。输入行数不超过10行。

### 输出格式:

对于输入的每个括号序列输出1行或2行信息。若输入的括号序列匹配，则输出Match。若不匹配，则输出分为2行，第1行为一个整数，表示将该序列变为匹配序列所需添加的最少括号数目，第2行为一个字符串，表示经添加最少括号后得到的合法匹配序列。

### 输入样例:

```in
(())()
)(
()))((
```

### 输出样例:

```out
Match
2
()()
4
((()))(())
```

### 代码：

```c++
#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	while(cin>>s)
	{
		int num1=0,num2=0;
		int lens=s.length();

		for (int i=0;i<lens;i++)
		{
			if (s[i] == '(')
				num1++;
			if (s[i] == ')')
			{
				if (num1>0)
                    num1--;
				else num2++;
			}
		}

		if ( num1==0 && num2==0 )
            cout << "Match" ;
		else
		{
			cout<<num1+num2<<endl;
			for (int i=0;i<num2;i++)
                cout << "(";
            cout << s;
			for (int i=0;i<num1;i++)
                cout << ")";
		}
		cout << endl;
	}
}

```

-------------------------

### 7-6 字符串对称

编写一个算法利用顺序栈判断一个字符串是否是对称串。所谓对称串是指从左向右读和从右向左读的序列相同。

### 输入格式:

输入一个无空格的字符串。

### 输出格式:

如果该字符是对称的，输出yes，否则输出no。

### 输入样例:

在这里给出一组输入。例如：

```in
abba
结尾无空行
```

### 输出样例:

在这里给出相应的输出。例如：

```out
yes
结尾无空行
```

### 输入样例:

在这里给出一组输入。例如：

```in
abcd
结尾无空行
```

### 输出样例:

在这里给出相应的输出。例如：

```out
no
结尾无空行
```

### 代码：

```c++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    bool flag=true;

    cin>>s;
    int lens=s.size();


    for (int i=0;i<lens/2;i++)
    {
        if(s[i]!=s[lens-1-i])
        {
            flag=false;
            break;
        }
    }
    if(flag==false)
        cout<<"no"<<endl;
    else
        cout<<"yes"<<endl;

    return 0;
}

```

-------------------------

### 7-7 魔王语言解释

有一个魔王总是使用自己的一种非常精练而抽象的语言讲话，没人能听的懂。但他的语言是可以逐步解释成人能懂得语言的，因为他的语言是由以下两种形式的规则由人的语言逐 步抽象上去的：   

1. α->β1β2...βn 
2. (θδ1δ2...δn)->θδnθδn-1...θδ1θ   在这两种形式中，从左到右均表示解释；从右到左表示抽象。试写一个魔王解释系统，把他的话解释成人能听懂得话。 [基本要求]   用下述两条具体规则和上述规则形式（2）实现。设大写字母表示魔王语言的词汇；小写字   母表示人的语言词汇；希腊字母（a,b1,s,y1等）表示可以用大写或小写字母代换的变量。   

魔王语言可含人的词汇。    

1. B->tAdA  
2. A->sae

### 输入格式:

输入一串带有大小写子字母的字符串其中小写字母用圆括号括起来。例如：B（einxgz）B# 。

### 输出格式:

根据魔王语言翻译逻辑，输出答案。例如：tsaedsaeezegexeneietsaedsae。

### 输入样例:

在这里给出一组输入。例如：

```in
B(einxgz)B#
结尾无空行
```

### 输出样例:

在这里给出相应的输出。例如：

```out
tsaedsaeezegexeneietsaedsae
结尾无空行
```

### 代码：

```c++
#include <bits/stdc++.h>
using namespace std;

stack <char> zhan;

int main()
{
	string s;
	cin>>s;
	int lens = s.length();
	for (int i=0;i<lens-1;i++)
	{
		if (s[i] == 'A')
            cout << "sae";

		else if (s[i] == 'B')
            cout << "tsaedsae";

		else if (s[i] == '(')
		{
			i++;
			int p=i+1;
			while (s[p]!=')')
			{
				zhan.push(s[p]);
				p++;
			}
			while (zhan.size()>0)
			{
				cout<<s[i]<<zhan.top();
				zhan.pop();
			}
			cout<<s[i];
			i=p;
		}
		else
            cout<<s[i];
	}

	return 0;
}

```

-------------------------------

### 7-10 列车车厢重排

火车站的列车调度铁轨的结构如下所示： (Exit) 9 8 7 6 5 4 3 2 1 <==== ………………………………… <==== 8 4 2 5 3 9 1 6 7 (Entrance) 两端分别是一条入口（Entrance）轨道和一条出口（Exit）轨道，它们之间可能有N条平行的轨道。每趟列车从入口可以选择任意一条轨道进入排队，以方便最后有序从出口离开。在前例中有9趟列车，在入口处按照{8，4，2，5，3，9，1，6，7}的顺序排队等待进入。如果要求它们必须按序号递减的顺序从出口离开，则至少需要多少条平行铁轨用于调度？调度入队后，各个队列里车厢情况如何？

**输入格式：** 输入第一行给出一个整数N (2 ≤ N ≤99 )，下一行给出从1到N的整数序号的一个重排列。数字间以空格分隔。

**输出格式：** 第一行输出1号车厢所在的队列中的元素（车厢编号间以空格分隔），注意，调度时，车厢只进入队列等待，并不出队。 在第二行中输出可以将输入的列车按序号递减的顺序重排所需要最少的辅助铁轨（队列）条数。

### 输入样例:

```in
9
8 4 2 5 3 9 1 6 7
结尾无空行
```

### 输出样例:

```out
8 4 2 1
4
结尾无空行
```

### 代码：

```c++
#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q[105];
    int res=0;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        {
        int x;
        cin >> x;
        int flag=0;
        for(int j=0;j<res;j++)
        {
            if(q[j].back()>x)
            {
                q[j].push(x);
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            q[res].push(x);
            res++;
        }
    }
    for(int i=0;i<res;i++)
    {
        if(q[i].back()==1)
        {
            while(!q[i].empty())
            {
                cout << q[i].front();
                q[i].pop();
                if(!q[i].empty())
                 cout<<' ';
                else cout<<endl;
            }
            break;
        }
    }
    cout<<res<<endl;

    return 0;
}

```

---------------------------------------------------

