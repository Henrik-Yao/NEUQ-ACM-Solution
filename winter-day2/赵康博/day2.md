### 7 - 1

---

先按照线序线序序列建立二叉树，在建立中记录层数，判断节点是否为叶子，如果是的话，以层数为下标，把叶子的值加入，最后比较

---

```
void build(int n,Tree &a)
{
    int f;
    cin>>f;
    if(f!=0){
        a = (Tree) malloc(sizeof (tree));
        a->data = f;
    }
    else {
        a = nullptr;
        return;
    }
    build(n+1,a->lChild);
    build(n+1,a->rChild);
    if(a->rChild== nullptr&&a->lChild== nullptr)
    {
        s[n]+=a->data;
        v[n] = 1;
    }
}
```

### 7 - 2

---

先判断是不是合法，把字符串输入，后续的序列最后一个是根节点，在中序中找到这个字符，字符前的是左子树，字符后的右子树，判断左子树和右子树含有的字符是否一样，不一样返回false，一样则继续判断，左子树的后续和中序是否合法，运用递归。

```
bool judge(string a,string b)
{
    if(a.length()==0&&b.length()==0)return true;
    else if(a.length()!=b.length())return false;
    char t = a[a.length()-1];
    int i;
    for(i = 0; i < b.length(); i++)
    {
        if(t==b[i])break;
    }
    string a1 = a.substr(0,i);
    string b1 = b.substr(0,i);
    string a2 = a.substr(i,a.length()- 1 - i);
    string b2 = b.substr(i+1);
    for(int j = 0; j < a1.length(); j++)
        if(b1.find(a1[j])==-1)return false;
    for(int j = 0; j < a2.length(); j++)
        if(b2.find(a2[j])==-1)return false;
    return judge(a1,b1)&& judge(a2,b2);
}
```

建立的过程与判断的过程相似，先通过后续序列找到根节点，在中序的序列中找到匹配的字符，运用递归继续建立，左子树和右子树。

```
Tree rebuild(string a,string b)
{
    if(a.length()==0)return nullptr;
    Tree p = (Tree) malloc(sizeof (tree));
    p->data = a[a.length()-1];
    int i;
    for(i = 0; i < b.length(); i++)
    {
        if(p->data==b[i])break;
    }
    string a1 = a.substr(0,i);
    string b1 = b.substr(0,i);
    string a2 = a.substr(i,a.length()- 1 - i);
    string b2 = b.substr(i+1);
    p->lChild = rebuild(a1,b1);
    p->rChild = rebuild(a2,b2);
    return  p;
}
```

---

### 7 - 4

---

用数组记录犯罪的团伙，输入的两个罪犯，如果有一个人有团伙则把另一个人也记录团伙，若两人都没有则增加一个新的团伙，并且记录，最后统计没有加入团伙的加上现有的数量即为总数量。

---

### 7 - 6

---

和第二题原理相同，先通过先序序列确定根，然后利用递归确定左右 子树。

```
Tree buildTree(int l1,int l2,int r1,int r2)
{
    if(l1>l2||r1>r2)return nullptr;
    Tree p = (Tree) malloc(sizeof(tree));
    int a = f[l1];
    int t;
    for(int i = r1; i <= r2; i++)if(a==s[i])t = i;
    p->data = a;
    int l = t - r1;
    p->lChild = buildTree(l1+1,l1 + l,t - l,t - 1);
    p->rChild = buildTree(l1+l+1,l2,t+1,r2);
    return p;
}
```

---

### 7 - 7

---

建树的方法和第六题一样，层次遍历，把根节点存入队列，每次去出队指针，左右子树不为空则入队，直到队列为空。

```
void Visit(Tree p)
{
    queue<Tree> xun;
    xun.push(p);
    while (!xun.empty())
    {
        Tree q = xun.front();
        cout<<q->data<<" ";
        xun.pop();
        if(q->lChild!= nullptr)xun.push(q->lChild);
        if(q->rChild!= nullptr)xun.push(q->rChild);
    }
}
```

---

### 7 - 9

---

和前面做法一样。