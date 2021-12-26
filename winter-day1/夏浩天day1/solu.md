## 7-1 动态区间求和

请编写程序对数组*a*1,*a*2,...,*a**n*进行如下操作 ：

1 *i* *x*：给定*i*,*x*，将*a**i* 加上*x* ；

2 *l* *r*：给定*l*,*r*，求*a**l*+*a**l*+1+...+*a**r*的值。



## 7-2 小明打字

小明正使用Microsoft Word打一篇文档，文档只包含a-z的小写字母和空格，在打字过程中可能会一次或多次按下Home键、End键、←方向键、→方向键、Insert键、Backspace键。请编写程序，给定小明在键盘上按键的序列，输出小明屏幕上最终显示的文本。 提示：Home键会将当前光标移至文本开始位置，End键当前光标移至文本尾，←键和→键会使当前光标左移或右移一个位置（如果光标在文档头则无法左移，光标在文档尾则无法右移），Insert键会在插入和替换文本间切换（默认是插入状态），Backspace键会删除当前光标前的一个字符。



## 7-3 特殊约瑟夫问题*

编号为1…N的N个小朋友玩游戏，他们按编号顺时针围成一圈，从第一个人开始按逆时针次序报数，报到第M个人出列；然后再从下个人开始按顺时针次序报数，报到第K个人出列；再从下一个人开始按逆时针次序报数，报到第M个人出列；再从下个人开始按顺时针次序报数，报到第K个人出列……以此类推不断循环，直至最后一人出列。请编写程序按顺序输出出列人的编号。

**......**

python显然不是个好选择，看有没有时间研究一下然后改成c++版本吧

~~~python

list=[]
s=n=input()
n,m,k=s.split()
n=int(n)
m=int(m)-1
k=int(k)-1
# 这行往上的代码等价于c++的 int n,m,k;cin>>n>>m>>k;
# ~~看着都觉得麻烦，而且用时也长~~
i=1
xb=0
while i<=n:
    list.append(i)
    i+=1

while len(list)!=0: # 列表不为空
    xb=xb-m
    while xb<0:
        xb+=len(list)
    print(list.pop(xb),end=' ')
    if len(list)==0:
        break
    xb=xb+k-1
    while xb>=len(list):
        xb-=len(list)
    print(list.pop(xb),end=' ')
print('')
~~~

注：运行耗时19ms



## 7-4 程序设计综合实践 1.4*

1.4 编写程序，输入若干正整数，按从小到大次序建立1个带头结点单链表，设计一个实现单链表分离算法的Split函数，将原单链表中值为偶数的结点分离出来形成一个新单链表，新单链表中头结点重新申请，其余结点来自原链表，分离后，原链表中只剩非偶数值所在结点，最后显示2个单链表，在程序退出前销毁单链表。要求Split算法时间复杂性达到O（n）,程序不可存在内存泄漏。

~~~#include<iostream>
#include<stack>
#include<string.h>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;

struct node
{
	int data;
	struct node *next;
};
 
int main()
{
	struct node *head,*end,*p;
	int t,a;
	head=(struct node*)malloc(sizeof(struct node));
	end=head;
	while(scanf("%d",&a)!=EOF)
	{
	    p=(struct node*)malloc(sizeof(struct node));
	    p->data=a;
		end->next=p;
		end=p;
	}
	end->next=NULL;
	struct node *p1,*p2,*p3;
	for(p1=head->next;p1!=NULL;p1=p1->next)
	{
		for(p2=p1->next;p2!=NULL;p2=p2->next)
		{
			if(p1->data>p2->data)
			{
				t=p1->data;
				p1->data=p2->data;
				p2->data=t;
			}
		}
	}
	struct node *o,*j,*oshu,*jishu;
	oshu=(struct node*)malloc(sizeof(struct node));
	jishu=(struct node*)malloc(sizeof(struct node));
	o=oshu;
	j=jishu;
	head=head->next;
	while(head!=NULL)
    {
        printf("%d",head->data);
		if(head->next!=NULL)printf("->");
        if(head->data%2!=0)//将奇数存入一个新链表
        {
            jishu->next=head;
            jishu=head;
        }
        else//将偶数存入一个新链表
        {
            oshu->next=head;
            oshu=head;
        }
        head=head->next;
    }
	printf("\n");
    oshu->next=NULL;
    jishu->next=NULL;
    j=j->next;
    while(j!=NULL)//输出奇数
	{
		printf("%d",j->data);
		if(j->next!=NULL)printf("->");
		j=j->next;
	}
	printf("\n");
	o=o->next;
	while(o!=NULL)//输出偶数
	{
		printf("%d",o->data);
		if(o->next!=NULL)printf("->");
		o=o->next;
	}
	cout << endl;;
}
~~~



## 7-5 括号匹配*

请编写程序判断一个包含“（”和“）”的括号序列是否匹配。如匹配则输出Match；如不匹配，计算出使该序列变为匹配序列所需添加的最少括号数目（只允许在该序列开始和结尾处添加括号），并输出经添加最少括号后得到的合法匹配序列。

**~~有什么专门要说的么？~~**

**对字符串进行遍历，q为‘（’个数，p为‘）’个数，q>0遇‘）’-1，否则p+1**

~~~#include<iostream>
#include<stack>
#include<string.h>
#include<fstream>
#include<string>
using namespace std;
int q, p;//q(   p)
int main()
{
	
	string lsz; 
	while (cin >> lsz)
	{
		q = 0; p = 0;
		for (int i = 0; i < lsz.size(); i++)
		{
			if (lsz[i] == ')')
			{
				if (!q) p++;
				else q--;
			}
			else
				q++;
		}
		if (!p && !q) cout << "Match";
		else
		{
			cout << p + q << endl;
			while (p > 0) 
			{
				cout << '('; p--;
			}
            cout << lsz;
			while (q > 0) 
			{ 
				cout << ')'; 
				q--; 
			}
		}
		cout << endl;
	}
}
~~~



## 7-6 字符串对称*

编写一个算法利用顺序栈判断一个字符串是否是对称串。所谓对称串是指从左向右读和从右向左读的序列相同。

~~貌似没用栈......:(；ﾞﾟ'ωﾟ'):~~

~~~#include<iostream>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string lsz;cin>>lsz;
    for(int i=0;i<lsz.size()/2;i++)
    {
        if(lsz[i]!=lsz[lsz.size()-i-1])
        {cout<<"no"<<endl;return 0;}
    }
    cout<<"yes"<<endl;
}
~~~

## 7-7 魔王语言解释*

有一个魔王总是使用自己的一种非常精练而抽象的语言讲话，没人能听的懂。但他的语言是可以逐步解释成人能懂得语言的，因为他的语言是由以下两种形式的规则由人的语言逐 步抽象上去的：   

1. α->β1β2...βn 

2. (θδ1δ2...δn)->θδnθδn-1...θδ1θ   在这两种形式中，从左到右均表示解释；从右到左表示抽象。试写一个魔王解释系统，把他的话解释成人能听懂得话。 [基本要求]   用下述两条具体规则和上述规则形式（2）实现。设大写字母表示魔王语言的词汇；小写字   母表示人的语言词汇；希腊字母（a,b1,s,y1等）表示可以用大写或小写字母代换的变量。   

   ~~~
   #include <iostream>
   #include <cstring>
   #include <cstdlib>
   #include <algorithm>
   #include <queue>
   #include <stack>
   using namespace std;
   
   stack <char> s;
   queue <char> q;
   int main() 
   {
       char data;
       char s1[105];
       cin >> s1;
       for (int i = 0; i < strlen(s1); i++) 
           q.push(s1[i]);
       while (!q.empty()) 
       {
           if (q.front() == 'A')
               cout << "sae";
           else if (q.front() == 'B')
               cout << "tsaedsae";
           else if (q.front() == '(')
           {
               q.pop();//移除‘（’
               data = q.front();
               q.pop();
               while (q.front() != ')')
               {
                   s.push(q.front());
                   q.pop();
               }
               while (!s.empty())
               {
                   if (s.top() == 'A')
                       cout << data << "sae";
                   else if (s.top() == 'B')
                       cout << data << "tsaedsae";
                   else
                       cout << data << s.top();
                   s.pop();
               }
               cout << data;
           }
           else if (q.front() == ')')
               q.pop();
           else if (q.front() == '#')
               q.pop();
           else 
               cout << q.front();
           if(!q.empty())
               q.pop();
       }
       cout << endl;
       return 0;
   }
   ~~~



## 7-8 括号配对*

设表达式中允许包含3种括号：圆括号、方括号和大括号。即小括号、中括号和大括号。 编写一个算法来判断表达式中的括号是否正确配对，要求利用栈的结构实现。

**相对简单的一道栈题**

~~~#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
stack <char> Q;
char s[10001];
int main()
{
    Q.push('#');
    cin >> s;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] != '[' && s[i] != '(' && s[i] != ']' && s[i] != ')' && s[i] != '{' && s[i] != '}')
            continue;
        if (s[i] == '[' || s[i] == '(' || s[i] == '{')
            Q.push(s[i]);
        else if ((s[i] == ']' && Q.top() == '[') || (s[i] == ')' && Q.top() == '(') || (s[i] == '}' && Q.top() == '{'))
            Q.pop();
        else
            Q.push(s[i]);
    }
    if (Q.top() == '#')
        cout<<"yes"<<endl;
    else
        cout<<"no"<<endl;
    return 0;
}
~~~





## 7-9 银行排队问题之单窗口“夹塞”版

排队“夹塞”是引起大家强烈不满的行为，但是这种现象时常存在。在银行的单窗口排队问题中，假设银行只有1个窗口提供服务，所有顾客按到达时间排成一条长龙。当窗口空闲时，下一位顾客即去该窗口处理事务。此时如果已知第*i*位顾客与排在后面的第*j*位顾客是好朋友，并且愿意替朋友办理事务的话，那么第*i*位顾客的事务处理时间就是自己的事务加朋友的事务所耗时间的总和。在这种情况下，顾客的等待时间就可能被影响。假设所有人到达银行时，若没有空窗口，都会请求排在最前面的朋友帮忙（包括正在窗口接受服务的朋友）；当有不止一位朋友请求某位顾客帮忙时，该顾客会根据自己朋友请求的顺序来依次处理事务。试编写程序模拟这种现象，并计算顾客的平均等待时间。

凑了半天还是不明白平均等待时间是怎么算的

半成品：

~~~#include<iostream>
#include<string.h>
#include<string>
#include<list>
#include<queue>
#include<vector>
#include<stack>
#include<map>
using namespace std;
map<string, int> mapp;//string name,int 第几号圈
map<string, int> dui;//第几队
list<string> quan[101];//第n号圈子里有哪些人
int quan_index = 1;
bool qua[101];//圈子前面有没有人
queue<string> en[101];//最终名单
int en_index = 0;//队伍数量（服务人数）
double tim = 0;//前面所有耗时
double time1[101];//每支队伍耗时
double toti = 0;//所有等待耗时
int main()
{
	int n, m; cin >> n >> m;
	while (m--)
	{
		int g; cin >> g;
		while (g--)
		{
			string name; cin >> name;
			mapp[name] = quan_index;
			quan[quan_index].push_back(name);
		}
		quan_index++;
	}
	while (n--)
	{
		string name; int t, p;
		cin >> name >> t >> p;

		if (qua[mapp[name]]) //前面有人
		{
			if (t <= tim+time1[dui[name]])
			{
				en[dui[name]].push(name);
				if (p > 60)p = 60;
				time1[dui[name]] += p;
				toti += p;
			}
			else//前面的办完事走了
			{
				qua[mapp[name]] = false;
				tim += time1[dui[name]];
				time1[dui[name]] = 0;
			}
		}

		if (!qua[mapp[name]])//圈子前面没人
		{
			qua[mapp[name]] = true;
			en[en_index].push(name);
			if (p > 60)p = 60;
			toti += p;
			time1[en_index] += p;
			for(auto f=quan[mapp[name]].begin();f != quan[mapp[name]].end();f++)
				dui[*f] = en_index;//将一个圈子里全归到一队
			toti -= t;
			en_index++;//队伍数量增加了！
		}

	}
	for (int i = 0; i < en_index; i++)
	{
		while (!en[i].empty())
		{
			cout << en[i].front() << endl;
			en[i].pop();
		}
	}
	printf("%.1lf", toti / (en_index-1));
}
~~~



## 7-10 **列车车厢重排***

火车站的列车调度铁轨的结构如下所示： (Exit) 9 8 7 6 5 4 3 2 1 <==== ………………………………… <==== 8 4 2 5 3 9 1 6 7 (Entrance) 两端分别是一条入口（Entrance）轨道和一条出口（Exit）轨道，它们之间可能有N条平行的轨道。每趟列车从入口可以选择任意一条轨道进入排队，以方便最后有序从出口离开。在前例中有9趟列车，在入口处按照{8，4，2，5，3，9，1，6，7}的顺序排队等待进入。如果要求它们必须按序号递减的顺序从出口离开，则至少需要多少条平行铁轨用于调度？调度入队后，各个队列里车厢情况如何？

**分析：**

8 4 2 1

5 3

9 6

7

**将每次输入的值与所有队列的最后一位比较，选择差值最小且小于该位的队列插入，若无则新建队列**

**注意第一次插入必须先加入不然在提队列最后一位时会报错**

**当然可以优化一下代码，不过并不会带来复杂度的降低，只是美观，所以...**

优化代码：cg=0，再改改即可将第一次插入写入循环（让第一次比较循环不了）

~~~#include<iostream>
#include<stack>
#include<string.h>
#include<fstream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<list>
#include<queue>
using namespace std;
queue<int> car[100];
int cg = 1;//car启用数量
int main()
{
	int n; cin >> n;
	n--; int lsz; cin >> lsz;
	car[1].push(lsz);
	while (n--)
	{
		int lsz; cin >> lsz;
		int xb = cg+1, mi = 99999;
		for (int i = 1; i < cg + 1; i++)
		{
			int ca = car[i].back();//ca为队尾值
			if (ca - lsz < mi && ca-lsz>0)
			{
				mi = ca - lsz; xb = i;
			}
		}
		car[xb].push(lsz);//lsz进最接近的点或cg+1
		if (xb == cg + 1)cg++;
	}
	while (!car[1].empty())
	{
        if(car[1].size()>1)
        {
            cout << car[1].front()<<" ";
		    car[1].pop();
        }
        else 
        {
            cout << car[1].front();
		    car[1].pop();
        }
	}
	cout << endl;
	cout << cg;
    cout<<endl;
}
