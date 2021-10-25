## Week 2  递归、分治与归并

### 7-1 汉诺塔问题

给定一个由n个圆盘组成的塔，这些圆盘按照大小递减的方式套在第一根桩柱上。现要将整个塔移动到另一根桩柱上，每次只能移动一个圆盘，且较大的圆盘在移动过程中不能放置在较小的圆盘上面。

### 输入格式:

输入由四行： 第一行是圆盘数量n(1<=n<=10); 第二行到第四行分别是三根桩柱的名字(字符串)，n个盘子套在第一根桩柱上。

### 输出格式:

输出移动步骤，每行输出一步。

### 输入样例:

在这里给出一组输入。例如：

```in
2
a
b
c
结尾无空行
```

### 输出样例:

在这里给出相应的输出。例如：

```out
a->b
a->c
b->c
结尾无空行
```

### 代码

```C++
#include <bits/stdc++.h>
using namespace std;

void tower(int n,string x,string y,string z)
{
    if(n==1)
        cout<<x<<"->"<<z<<endl; //当只有一个盘子时，直接将盘子从x移到z
    else
    {
        tower(n-1,x,z,y); //先将n-1个盘子从x借助z移到y上
        cout<<x<<"->"<<z<<endl; //再将最下面的第n个盘子从x移到z
        tower(n-1,y,x,z); //最后将n-1个盘子从y借助x移到z
    }
}

int main()
{
    int n;
    cin>>n;
    string a,b,c;
    cin>>a>>b>>c;

    tower(n,a,b,c); //表示n个盘子从a借助b移到c上需要经过的步骤

    return 0;
}

```

------

### 7-2 分而治之

分而治之，各个击破是兵家常用的策略之一。在战争中，我们希望首先攻下敌方的部分城市，使其剩余的城市变成孤立无援，然后再分头各个击破。为此参谋部提供了若干打击方案。本题就请你编写程序，判断每个方案的可行性。

### 输入格式：

输入在第一行给出两个正整数 N 和 M（均不超过10 000），分别为敌方城市个数（于是默认城市从 1 到 N 编号）和连接两城市的通路条数。随后 M 行，每行给出一条通路所连接的两个城市的编号，其间以一个空格分隔。在城市信息之后给出参谋部的系列方案，即一个正整数 K （≤ 100）和随后的 K 行方案，每行按以下格式给出：

```
Np v[1] v[2] ... v[Np]
```

其中 `Np` 是该方案中计划攻下的城市数量，后面的系列 `v[i]` 是计划攻下的城市编号。

### 输出格式：

对每一套方案，如果可行就输出`YES`，否则输出`NO`。

### 输入样例：

```in
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 10
2 4
5
4 10 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2
结尾无空行
```

### 输出样例：

```out
NO
YES
YES
NO
NO
结尾无空行
```

### 代码：

```C++
#include <bits/stdc++.h>
using namespace std;

vector <int> a[10005]; //建立一个vector的数组用于存某个城市与之有连接的城市序号
int b[10005]; //建立一个int型数组用于记录每个城市是否被攻下

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++) //存储某个城市与之有连接的城市序号
    {
        int t1,t2;
        cin>>t1>>t2;
        a[t1].push_back(t2);
    }

    int k;
    cin>>k;

    while(k--)
    {
        int np;
        cin>>np;

        memset(b,0,sizeof(b)); //将b[10005]数组全部置零

        while(np--) //记录每个被攻下的城市，b[i]为0表示i城市未被攻下，b[i]为1表示i城市被攻下
        {
            int t;
            cin>>t;
            b[t] = 1;
        }

        int flag=1; //先默认方案可行，flag=1

        for(int i=1;i<=n;i++) //遍历每个城市，以及每个城市与之有连接的城市的状态
        {
            for(int j=0;j<a[i].size();j++)
            {
                if(b[i]!=1 && b[a[i][j]]!=1) //若存在某个城市未被攻下，且与之有连通的城市也有未被攻下的，则此方案不可行，flag=0,跳出两层循环
                {
                    flag = 0;
                    break;
                }
            }
            if(flag==0)
                break;
        }

        if(flag==1) cout<<"YES"<<endl; //以flag的值判断方案是否可行
        else cout<<"NO"<<endl;
    }
    
    return 0;
}

```

----------------

### 7-3 归并排序

知识点：归并排序

给定你一个长度为 n 的整数数列。

请你使用归并排序对这个数列按照从小到大进行排序。

并将排好序的数列按顺序输出。

### 输入格式:

输入共两行，第一行包含整数 n(1≤n≤100000)。

第二行包含 n 个整数（所有整数均在 1∼10^9 范围内），表示整个数列。

### 输出格式:

输出共一行，包含 n 个整数，表示排好序的数列。

### 输入样例:

```in
5
3 1 2 4 5
结尾无空行
```

### 输出样例:

```out
1 2 3 4 5 
结尾无空行
```

### 代码1：

sort函数，过了

```C++
#include <bits/stdc++.h>
using namespace std;

int n,a[100005];

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n); //直接用sort函数排序

    for(int i=0;i<n;i++)
        cout<<a[i]<<' ';
}
```

### 代码2：

归并排序，但运行超时了

```c++
#include <iostream>
using namespace std;

int n;
int a[100005],temp[100005];

void merge_sort(int l,int r)
{
    if(l>=r)     //当分割到区间长度为1时不需要排序
        return;

    int mid=(l+r)/2;
    merge_sort(1,mid);   
    merge_sort(mid+1,r);
    //对左区间和右区间进行排序，即后面的问题建立在左右区间均为有序的条件下
    
    int p=l,q=mid+1,now=1; //指针p指向左区间第一个元素，指针q指向右区间第一个元素
    while(p<=mid && q<=r) //当两个指针均未超出区间范围时，取每个指针指向的最小元素赋给temp数组，同时该指针增1
    {
        if(a[p]<a[q])
             temp[now++]=a[p++];

        else
            temp[now++]=a[q++];

    }

         while(q<=r) //当左区间全部落入temp中但右区间中还有剩余元素时，按序直接落入temp
    {
        temp[now++]=a[q++];
    }

        while(p<=mid)//当右区间全部落入temp中但左区间中还有剩余元素时，按序直接落入temp
    {
        temp[now++]=a[p++];
    }


    for(int i=l,j=1;i<=r;i++,j++) //将temp存的值全部赋给数组a中[l,r]的区间
    {
        a[i]=temp[j];
    }
}

int main()
{

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    merge_sort(1,n); 

    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<' ';
    }
}

```

