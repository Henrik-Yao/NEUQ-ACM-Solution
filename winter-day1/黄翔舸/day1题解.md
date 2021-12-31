                                                                                                          **day1题解**

1	

思路：考察树状数组，要用到lowbit的层替换。

求父亲节点的位置：**

设父节点序号为F，它的左孩子节点为L

有结论F=L+lowbit(F) , 相当于加了一个最小的1，即跳转到同层本来应该存在的（但是被删掉的）下一个位置，（同层的加法就是加最低位1的位权，参考上面层数和最低位的1的位置关系）。

树状数组的好处就是可以只用单串数据来表示树状数据。如上述结论只需要父节点和一个子节点就可以表示另一个子节点。从而提高效率

lowbit函数运算上就是两个方式

原型：int lowbit(int x)                
{
    return x&(-x);
}

单点更新：void update(int i, int x){ //i点增量为x
	while(i <= n){
		c[i] += x;
		i += Lowbit(i);
	}
}

求区间和int sum(int x){//区间求和 [1,x]
	int sum=0;
	while(x>0){
		sum+=c[x];//从后面的节点往前加
		x-=Lowbit(x);//同层中向前移动一格，如果遇到L=1的节点会减成0
	}
	return sum;
}
int Getsum(int x1,int x2){ //求任意区间和
	return sum(x2) - sum(x1-1);
}

数组初始化：使用memset（string.h)头文件，但是pta上直接输入数组名好像过不去。而memset原函数的首个是指针变量

所以设一个指向数组的指针变量就行了。	

ll* p;
p = &a[0];

memset(p, 0, sizeof(a));

另：要用ll类型，不然会爆。

输入树状数组：

for (ll i = 1;i <= n; i++)
	{
		ll temp;
		cin >> temp;
		jia(i, temp);//单点更新函数，树状数组中每一次对数组元素的输入都会影响其子数据
	}

2小明码字

思路：构建链表结构体，并设置带空头结点的链表，每次都插入到设置的暂时存储tmp的后面

本质上是一个输入插入的功能转换，可以使用bool去每次反转，来使功能发生改变。如下注释

#include <algorithm>  //7-1 小明码字 (10分)
#include <cstring>
#include <iostream>
using namespace std;

typedef struct lb {//构建链表结构体
    char ch;
   lb* next;
   lb* prev;
} *jd;//节点数据

int main() {
    char ch;
   jd start, end, tmp;  //带空头节点链表, 每次插入tmp后面
    jd L = new lb();
    start = L;
    end = L;
    tmp = L;

    bool isInsert = true;//初始现在是insert（输入）状态，false就是替换状态

   jd ins;
    while ((ch=getchar())!= '\n') {
        if (ch == '[') {
            tmp = start;
        }
        else if (ch == ']') {
            tmp = end;
        }
        else if (ch == '{') {
            if (tmp->prev) tmp = tmp->prev;
        }
        else if (ch == '}') {
            if (tmp->next) tmp = tmp->next;
        }
        else if (ch == '-') {
            isInsert = !isInsert;
        }
        else if (ch == '=') {  //删除tmp
            if (tmp->prev) {
               jd t = tmp;
                tmp->prev->next = tmp->next;
                if (tmp->next) {
                    tmp->next->prev = tmp->prev;
                    tmp = tmp->prev;
                }
                else {
                    tmp = tmp->prev;
                    tmp->next = NULL;
                }
                delete t;
                if (tmp->next == NULL) end = tmp;  //如果是删除最后的, 更新end
            }
        }
        else {  // tmp后面添加
            ins = new lb();
            ins->ch = ch;
            ins->next = tmp->next;
            ins->prev = tmp;
            tmp->next = ins;
            tmp = ins;
            if (tmp->next == NULL) end = tmp;  //如果插入在最后, 更新end
            if (!isInsert && tmp->next) {  //如果是替换, 且tmp下一个存在, 再删除tmp下一个
               jd t = tmp->next;
                if (t->next) {
                    tmp->next = t->next;
                    t->next->prev = tmp;
                    delete t;
                }
                else {	//删除元素在末尾
                    delete t;
                    end = tmp;  //更新end
                    tmp->next = NULL;
                }
            }
        }
        
    }
    
    tmp = start->next;
    while (tmp) {
       cout<< tmp->ch;
        tmp = tmp->next;
    }
    cout << endl;
    
    return 0;
}

3约瑟夫环

思路：对于这个题，首先想到的是低级但清楚的数组查询，即设置一个存储数据的数组和一个bool数组，bool数组用来判断该人是否已经输掉游戏，若是输掉了游戏，那么在进行查数时就不能将他算进去，但是由于时间复杂度过高，所以超时了。正解是利用链表指向节点，对于每一次小朋友的出局都会删除该节点，从而省去判断的时间（对于顺逆的转换，用一个flag标记判断一下即可。）

#include<iostream>
using namespace std;

struct linknode {
	int data;
	struct linknode* next;
	struct linknode* prior;
};

int main()
{
	int n, ni, shun, i;
	cin >> n >> ni >> shun;
	struct linknode* p, * q, * g;
	p = (struct linknode*)malloc(sizeof(struct linknode));
	g = q = p;
	p->data = 1; p->next = p;
	for (i = 2; i <= n; i++)
	{
		q = (q->next = (struct linknode*)malloc(sizeof(struct linknode)));
		q->prior = g;
		q->data = i;
		q->next = p;
		g = g->next;
	}
	
	p->prior = g;
	
	q = p;
	
	while (q != q->next)
	{
		
		if (ni == 1)
		{
			cout << q->data<<" ";
			q->next->prior = q->prior;
			q->prior->next = q->next;
			q = q->prior;
		}
		else
		{
			for (i = 2; i < ni; i++)
				q = q->prior;
			cout << q->prior->data <<" ";
			q->prior = q->prior->prior;
			q->prior->next = q;
			q = q->prior;
		}
		
		if (shun == 1)
		{
			cout << q->data << " ";
			q->next->prior = q->prior;
			q->prior->next = q->next;
			q = q->next;
		}
		else
		{
			for (i = 2; i < shun; i++)
				q = q->next;
			cout << q->next->data <<" ";
			q->next = q->next->next;
			q->next->prior = q;
			q = q->next;
		}
	}
	if (n % 2 == 1)
	{
		cout << p->data;
	}
	cout << endl;
	return 0;
}

6回文字符串

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string c1;
	cin >> c1;
	long long int uq=0;
	int flag = 0;
	for (long long int yq = c1.length() - 1; yq >= 0; yq--)
	{
		if (c1[yq] == c1[uq])
		{
			
		}
		else
		{
			flag++;
			break;
		}
		uq++;
	}
	if (flag)
	{
		cout << "no" << endl;
	}
	else
	{
		cout << "yes" << endl;
	}
	return 0;
}

7魔王语言

思路：题中已经给出了密码的对应序列，和之前week的一个题很像，也是括号中的展开，用单个字符读取展开即可（设置一个temp字符串，来记录括号中的字符，便于展开）

/*α->β1β2...βn 
(θδ1δ2...δn)->θδnθδn-1...θδ1θ      */
#include<iostream>
#include<cstring>
using namespace std;
char temp[1001];
int main()
{
	string c;
	cin >> c;
	int u = c.length();
	for (int i = 0; i < u; i++)
	{
		if (c[i] == 'B')
		{
			cout << "tsaedsae";
		}
		else if (c[i] == 'A')
		{
			cout << "sae";
		}
		else if (c[i] == '(')
		{
			char te = c[i + 1];
			cout << te;
			int y = 0;
			for (int j = i+2; j < u; j++)
			{
				if (c[j] != ')')
				{
					temp[y] = c[j];
					y++;
				}
				
				else { break; }
				
			}
		
			for (int j = y-1; j >=0; j--)
			{
				cout << temp[j] << te;
			}
			i = i + y + 1;
		}
	}
	cout<<endl;
	return 0;
}

8括号匹配

思路：回文字符串升级版，值得注意的是，括号好像不能直接判断相等，可以用哈西的思想，用数据代替字符串，进行判断。

/*7-8 括号配对
设表达式中允许包含3种括号：圆括号、方括号和大括号。即小括号、中括号和大括号。
编写一个算法来判断表达式中的括号是否正确配对，要求利用栈的结构实现。*/
#include<iostream>
#include<cstring>
using namespace std;
int cun[10001];
int main()
{
	string  c2;
	
	long long int uq = 0;
	cin >> c2;
	long long int cd = c2.length();
	for (int i = 0; i < cd; i++)
	{


		if (c2[i] == '(' || c2[i] == ')' )
		{
			cun[uq] = 1;
			uq++;
	
		}
		else if (c2[i] == '[' || c2[i] == ']')
		{
			cun[uq] = 2;
			uq++;
		}
		else if (c2[i] == '{' || c2[i] == '}')
		{
			cun[uq] = 3;
			uq++;
		}
	
	}
	int flag = 0;
	long long int y = 0;
	for (long long int e = uq - 1; e >= 0; e--)
	{
		if (cun[e] == cun[y])
		{
	
		}
		else
		{
			flag++;
			break;
		}
		y++;
	
	}
	if (flag)
	{
		cout << "no" << endl;
	}
	else
	{
		cout << "yes" << endl;
	}
	return 0;
}





