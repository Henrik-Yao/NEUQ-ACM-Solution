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

