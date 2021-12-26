## 寒假集训—day1（线性表，栈，队列，字符串）

### **7-1 动态区间求和**

涉及到了树状数组的知识,其中的lowbit需要学习理解

```c++
#define lowbit(i) ((i)&(-i))
/*lowbit运算 lowbit(x)=x&(-x)
lowbit(x)可以理解为能整除x的最大2的幂次

树状数组
存放的是i号位之前（含i号位，下同）lowbit(i)个整数之和
C[i]的覆盖长度是lowbit(i)[也可理解为管辖范围]
将C[i]画成二维图容易理解

树状数组的下标必须从1开始
C[x]=A[x-lowbit(x)+1]+···+A[x]*/
```



### **7-2 小明打字**

小明打字整挺麻烦

涉及了链表知识，也用了vector

对应符号写一个函数，里面表示操作

```c++
#include <bits/stdc++.h>
using namespace std;
class iinput
{
    private:
    vector<char>chain;
    bool is;
    int index;
    public:
    iinput()
    {
        is=false;
        index=0;
    }
    void mhome(){index=0;}
    void mend(){index=chain.size();}
    void mleft(){if(index-1>=0)index--;}
    void mright(){if(index+1<=chain.size())index++;}
    void changeis(){is=!is;}
    void backspace(){if(chain.size()>0){chain.erase(chain.begin()+index-1);index--;}}
    void in(char c)
    {
        if(index==chain.size()-1)chain.push_back(c);
        else if(is)chain[index]=c;
        else chain.insert(chain.begin()+index,c);
        index++;
    }
    string ttstring()
    {
        string s;
        for(const char& c:chain) s.push_back(c);
        return s;
    }
    void operator>>(const char& c)
    {
        if(c=='[')mhome();
        else if(c==']')mend();
        else if(c=='{')mleft();
        else if(c=='}')mright();
        else if(c=='-')changeis();
        else if(c=='=')backspace();
        else in(c);
    }
};
int main()
{
    string s;
    getline(cin,s);
    iinput kk;
    for(const char& c:s)kk>>c;
    cout<<kk.ttstring()<<endl;
    return 0;
}
```



### **7-3 特殊约瑟夫问题**

用普通方法就可以做，但是貌似用链表做更易理解

```c++
#include <bits/stdc++.h>
using namespace std;
int n,m,k;
//链表
struct biao
{
    int data;
    struct biao* next;
    struct biao* last;
};
int main()
{
    cin>>n>>m>>k;
    struct biao* p,*q,*g;
    p=(struct biao*)malloc(sizeof(struct biao));
    g=q=p;
    p->data=1;
    p->next=p;
    for(int i=2;i<=n;i++)
    {
        q=(q->next=(struct biao*)malloc(sizeof(struct biao)));
        q->last=g;
        q->data=i;
        q->next=p;
        g=g->next;
    }
    p->last=g;
    q=p;
    while(q!=q->next)
    {
        if(m==1)
        {
            cout<<q->data;
            q->next->last=q->last;
            q->last->next=q->next;
            q=q->last;
        }
        else 
        {
            for(int i=2;i<m;i++)
            q=q->last;
            cout<<q->last->data<<" ";
            q->last=q->last->last;
            q->last->next=q;
            q=q->last;
        }
        if(k==1)
        {
            cout<<q->data;
            q->next->last=q->last;
            q->last->next=q->next;
            q=q->next;
        }
        else 
        {
            for(int i=2;i<k;i++)
            q=q->next;
            cout<<q->next->data<<" ";
            q->next=q->next->next;
            q->next->last=q;
            q=q->next;
        }
    }
    if(n%2==1)
    cout<<p->data;
    return 0;
}
```



### **7-4 程序设计综合实践 1.4**

也是用的链表，就是要链表分成多个来做

先对数据排序，然后就是根据奇数偶数写链表

### **7-6 字符串对称**

真没什么好说的，咋做都行

```c++
#include <bits/stdc++.h>
using namespace std;
void is(char a,char b)
{
    if(a!=b)cout<<"no";
}
int main()
{
    string x;
    cin>>x;
    int l=x.length();
    for(int i=0;i<l/2;i++)
    {
        if(x[i]!=x[l-i-1])
        {
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
    return 0;
}
```



### **7-8 括号配对**

使用了栈的知识做，弹栈入栈之类的

```c++
#include<bits/stdc++.h>
using namespace std;
stack <char> Q;
char s[11000];
int main()
{
    int i;
    Q.push('#');
    cin>>s;
    int len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]!='['&&s[i]!='('&&s[i]!=']'&&s[i]!=')'&&s[i]!='{'&&s[i]!='}')
            continue;
        if(s[i]=='[' || s[i]=='('||s[i]=='{')
            Q.push(s[i]);
        else if((s[i]==']' && Q.top()=='[') || (s[i]==')' && Q.top()=='(')||(s[i]=='}' && Q.top()=='{'))
            Q.pop();
        else
            Q.push(s[i]);
    }
    if(Q.top()=='#')
        printf("yes\n");
    else
        printf("no\n");
    while(Q.top()!='#')
        Q.pop();
    return 0;
}
```

