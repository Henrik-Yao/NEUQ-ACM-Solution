### 7 - 1

---

线段树，把每一个区间分为两段，每一个节点存储这一区间的和以及区间的范围，求和是，只要不断的二分，把在区间范围内的节点的和加起来，修改时，把这个节点以上的节点的和都加上，利用二分，找到具体的点。

---

```
long long h(int u,int l,int r)
{
    if(s[u].l>=l&&s[u].r<=r)return s[u].sum;
    else
    {
        int mid = (s[u].r+s[u].l)/2;
        long long sum = 0;
        if(l<=mid)sum+=h(2*u,l,r);
        if(r>mid)sum+=h(2*u+1,l,r);
        return sum;
    }
}
void quir(int u,int x,int t)
{
    if(s[u].r==s[u].l)s[u].sum+=t;
    else
    {
        int mid = (s[u].l+s[u].r)/2;
        if(x<=mid)quir(2*u,x,t);
        else quir(2*u+1,x,t);
        s[u].sum = s[2*u].sum + s[2*u+1].sum;
    }
}
```

### 7 - 2

---

先储存光标的状态，建立双向链表，以及头和尾部，光标的默认指向为end处，插入的过程为如果是光标插入则插入在光标指针的前面，替换则直接替换。

```
void insert(char t){
    if(a.soulation==0)
    {
        List *p = (List*) malloc(sizeof (List));
        p->next = a.w;
        p->front = a.w->front;
        a.w->front->next = p;
        a.w->front = p;
        p->data = t;
        sum++;
    } else
    {
        a.w->data = t;
        a.w = a.w->next;
    }
}
```

删除操作直接把前面a.w->front->front->next连接到光标指针位置即可，把指针的front连接到更前面一个。在光标的位置替换时，主意光标在head->next或者rear时不能向左，向右在动。

```
 else if(i=='[')a.w = head->next;
         else if(i==']')a.w = rear;
         else if(i=='{'&&a.w!=head->next)a.w = a.w->front;
         else if(i=='}'&&a.w!=rear)a.w = a.w->next;
```



---

### 7 - 3

---

用循环链表模拟循环的过程，用数组也行，注意在报道一个人后把这个人删除，题中的从下个人就是按照上一次循环循序的下一个人，不是更换后的循序。

---

### 7 - 4

---

把数排好顺序后建立链表，建立链表的过程中，遇到奇数加入奇数的链表中，遇到偶数，加入到偶数链表的链表中，最后统一的输出。

---

### 7 - 5

---

都是小括号没有区分，可以首先记录左括号和右括号的个数，若遇到左括号则左括号的个数加一，遇到右括号如果左括号为0，右括号数组加一，不为0则，左括号数减一。最后把左右的加起来就是需要补充的数量，在左边补充t2个左括号，右边补充t1个右括号最后可以得到匹配的结果。

---

```
 t1 = t2 = 0;
        for(int i = 0; i < t.size(); i++)
        {
            if(t[i]=='(')t1++;
            else {
                if(t1==0)t2++;
                else t1--;
            }
        }
```

---

### 7 - 6

---

先建立堆栈，把字符存入数组中，从top遍历堆栈，若与数组反向遍历结果一样则说明是对称的。否则直接输出no返回。

---

### 7 - 7

---

B代表“tsaedsae”，A代表sae，小括号内的小写字母是，先读取第一个字符，把剩下的倒过来，并且把字符之间都插入第一个字符，遍历完整个字符串。

---

### 7 - 8

---

建立栈，遇到左括号就入栈，遇到右括号就与栈顶的括号相比较，相同就删去栈顶的元素，不同输出no，最后，判断栈说否为空，不为空说明有多余的左括号，输出no，为空则输出yes。

---

### 7 - 9

---

先用map把名字对应的朋友圈表主，用vector容器储存数组朋友圈的名字。建立结构体数组，储存每一个人的顺序，到达时间以及，运行的时间。

```
int m,n;
    cin>>m>>n;
    for(int i = 0; i < n; i++)
    {
        int n1;
        string name;
        cin>>n1;
        for(int j = 0; j < n1; j++)
        {
            cin>>name;
            FriendH[name] = i;
            circle[i].push_back(name);
        }
    }
    for(int i = 0; i < m; i++)
    {
        cin>>c[i].name>>c[i].arrive>>c[i].time;
        if(c[i].time>60)c[i].time = 60;
        XvGet[c[i].name] = i;
    }
```

遍历结构体数组。窗口的运行时间开始应该是，第一个用户的到达时间，等待的时间计为0，用数组标记是否被遍历，若没有被遍历，用朋友圈的map查找，看书否有朋友，如果没有朋友，分为，若运行窗口的时间大于客户的到达时间，则等待时间加上运行窗口的时间减去到达时间，小于到达时间则说明没有等待，直接把运行窗口的时间等于到达的时间。

```

        if(v[i])continue;
        if(FriendH.find(c[i].name)==FriendH.end())
        {
            if(windowTime>c[i].arrive)
            {
                sum+=windowTime - c[i].arrive;
                windowTime+=c[i].time;
            }
            else
            {
                windowTime = c[i].arrive + c[i].time;
            }
            v[i] = 1;
            xun.push_back(c[i].name);
        }
```

若有朋友，如果是第一个且到达时间比窗口时间大，直接窗口加上任务时间，若比窗口时间小，等待时间加上窗口时间减去到达时间，窗口时间加上任务时间。其他，把窗口时间，先按到达的顺序把朋友圈的顺序排好，遍历每一个朋友圈里的人，如果，没有被遍历，比较到达的时间与窗口的时间，若大于窗口时间说明没有机会去插队，break，到达的时间小于窗口的时间，则等待的时间为窗口的时间减去到达时间，窗口时间等新为窗口时间加上办事的时间。

```
int ID = FriendH[c[i].name];
            sort(circle[ID].begin(),circle[ID].end(),cmp);
            for(int j = 0; j < circle[ID].size(); j++)
            {
                int x = XvGet[circle[ID][j]];
                if(c[x].arrive>windowTime&&j!=0)break;
                if(v[x])continue;
                if(c[x].arrive<=windowTime)
                {
                    sum+=windowTime - c[x].arrive;
                    windowTime+=c[x].time;
                }
                else windowTime = c[x].arrive+c[x].time;
                v[x] = 1;
                xun.push_back(c[x].name);
```

没标记一个任务，储存在vector中，最后按照储存的顺序输出，把等待时间和除个数，保留一位小数即可。

---

### 7 - 10

---

要把乱序的车厢按照顺序排列， 即在栈的里面也是按照顺序排列的，对与每一个车厢，先遍历现有栈的头，如果有比他大的找出差距最小的一个，储存在里面，没有大的则，新建一个堆栈，并储存在里面，特别注意如果是一号车厢，则需要标记最终的入栈位置，最后把此栈输出，并统计一共建立几个栈，并输出。

---

```
for(int i = 0; i < n; i++)
   {
       if(i==0)
       {
           f[t].push(s[i]);
           if(s[i]==1)tx = t;
       }
       else
       {
           int k = -1;
           int min = 1000;
           for(int j = 1; j <= t; j++)
           {
               if(f[j].top()>s[i]&&f[j].top()-s[i]<min)
               {
                   k = j;
                   min = f[j].top() - s[i];
               }
           }
           if(k==-1)
           {
               t++;
               f[t].push(s[i]);
               if(s[i]==1)tx = t;
           } else
           {
               f[k].push(s[i]);
               if(s[i]==1)tx = k;
           }
       }
   }
```

