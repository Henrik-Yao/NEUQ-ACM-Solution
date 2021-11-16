# WEEK5 周报
## 7-1 愿天下有情人都是失散多年的兄妹
### 题面
呵呵。大家都知道五服以内不得通婚，即两个人最近的共同祖先如果在五代以内（即本人、父母、祖父母、曾祖父母、高祖父母）则不可通婚。本题就请你帮助一对有情人判断一下，他们究竟是否可以成婚？

**输入格式:**
输入第一行给出一个正整数N（2 ≤ N ≤10 
4
 ），随后N行，每行按以下格式给出一个人的信息：

本人ID 性别 父亲ID 母亲ID
其中ID是5位数字，每人不同；性别M代表男性、F代表女性。如果某人的父亲或母亲已经不可考，则相应的ID位置上标记为-1。

接下来给出一个正整数K，随后K行，每行给出一对有情人的ID，其间以空格分隔。

注意：题目保证两个人是同辈，每人只有一个性别，并且血缘关系网中没有乱伦或隔辈成婚的情况。

**输出格式:**
对每一对有情人，判断他们的关系是否可以通婚：如果两人是同性，输出Never Mind；如果是异性并且关系出了五服，输出Yes；如果异性关系未出五服，输出No。

**输入样例:**
在这里给出一组输入。例如：
```
24
00001 M 01111 -1
00002 F 02222 03333
00003 M 02222 03333
00004 F 04444 03333
00005 M 04444 05555
00006 F 04444 05555
00007 F 06666 07777
00008 M 06666 07777
00009 M 00001 00002
00010 M 00003 00006
00011 F 00005 00007
00012 F 00008 08888
00013 F 00009 00011
00014 M 00010 09999
00015 M 00010 09999
00016 M 10000 00012
00017 F -1 00012
00018 F 11000 00013
00019 F 11100 00018
00020 F 00015 11110
00021 M 11100 00020
00022 M 00016 -1
00023 M 10012 00017
00024 M 00022 10013
9
00021 00024
00019 00024
00011 00012
00022 00018
00001 00004
00013 00016
00017 00015
00019 00021
00010 00011
结尾无空行
```
**输出样例:**

```
Never Mind
Yes
Never Mind
No
Yes
No
Yes
No
No
结尾无空行
```
### 思路
巨麻烦，先判断同性，然后递龟判断祖辈是否有通婚，depth判断是否出五服，注意父母id如果不是-1要为父母初始化性别

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
#define N 100005
struct Lover
{
    int fatherID = -1;
    int motherID = -1;
    char gender='M';
} Lovers[N];
bool Inquire(int inquireida, int inquireidb, int depth)
{
    depth++;
    if (inquireida == -1 || inquireidb == -1)
    {
        return 1;
    }
    else if (((Lovers[inquireida].fatherID == Lovers[inquireidb].fatherID) && Lovers[inquireida].fatherID != -1) || ((Lovers[inquireida].motherID == Lovers[inquireidb].motherID) && Lovers[inquireidb].motherID != -1))
    { /*
        cout << "---throw----" << endl;
        cout << "a: " << inquireida << "  "
             << "b: " << inquireidb << "  "
             << "depth: " << depth << endl;
        cout << "afather: " << Lovers[inquireida].fatherID << "  "
             << "bfather: " << Lovers[inquireidb].fatherID << "  "
             << "amother: " << Lovers[inquireida].motherID << "  "
             << "bmother: " << Lovers[inquireidb].motherID << "  " << endl;
        cout << "- - - -testend- - - -" << endl;*/
        return 0;
    }
    else if (depth >= 5)
    {
        return 1;
    }
    else
        return Inquire(Lovers[inquireida].fatherID, Lovers[inquireidb].fatherID, depth) && Inquire(Lovers[inquireida].motherID, Lovers[inquireidb].motherID, depth) && Inquire(Lovers[inquireida].fatherID, Lovers[inquireidb].motherID, depth) && Inquire(Lovers[inquireida].motherID, Lovers[inquireidb].fatherID, depth);
    
}
int main()
{
    int allovers, inquirenum, cinid, inquireida, inquireidb;
    scanf("%d", &allovers);
    for (int i = 0; i < allovers; ++i)
    {
        cin >> cinid >> Lovers[cinid].gender >> Lovers[cinid].fatherID >> Lovers[cinid].motherID;
        /*        cout << "----test " << i + 1 << " ----" << endl;
        cout << cinid << "  " << Lovers[cinid].gender << "  " << Lovers[cinid].fatherID << "  " << Lovers[cinid].motherID << endl
             << "----test " << i + 1 << " end----" << endl;

             输入正常
             
             */
        if (Lovers[cinid].fatherID != -1)
        {
            Lovers[Lovers[cinid].fatherID].gender = 'M';
        }
        if (Lovers[cinid].motherID != -1)
        {
            Lovers[Lovers[cinid].motherID].gender = 'F';
        }
    }
    scanf("%d", &inquirenum);
    while (inquirenum--)
    {
        scanf("%d %d", &inquireida, &inquireidb);

        if (Lovers[inquireida].gender == Lovers[inquireidb].gender)
        {
            printf("Never Mind\n");
        }
        else
        {
            if (!Inquire(inquireida, inquireidb, 1))
            {
                printf("No\n");
            }
            else
            {
                printf("Yes\n");
            }
        }
    }

    return 0;
}
```

## 7-2 哥德巴赫最新猜想
### 题面
X遇到一个关于素数的问题需要你这位大牛帮他解决。素数（prime number）又称质数。一个大于1的自然数，除了1和它本身外，不能整除以其他自然数，换句话说就是该数除了1和它本身以外不再有其他的因数，否则称为合数。哥德巴赫是德国数学家。出生于格奥尼格斯别尔格（现名加里宁城）。曾在英国牛津大学学习。原学法学，由于在欧洲各国访问期间结识了贝努利家族，所以对数学研究产生了兴趣。曾担任中学教师。1725年，到了俄国，同年被选为彼得堡科学院院士。1725年~1740年担任彼得堡科学院会议秘书。1742年，移居莫斯科，并在俄国外交部任职。1742年，哥德巴赫在教学中发现，每个不小于6的偶数都是两个素数之和。如6＝3＋3，14＝3＋11等等。公元1742年6月7日哥德巴赫写信给当时的大数学家欧拉，欧拉在6月30日给他的回信中说，他相信这个猜想是正确的，但他不能证明。叙述如此简单的问题，连欧拉这样首屈一指的数学家都不能证明，这个猜想便引起了许多数学家的注意。我们不需要你去证明哥德巴赫猜想。我们假设哥德巴赫猜想是正确的，一个不小于6的偶数，都是两个素数之和。例如14＝3＋11，也可以表示为14=7+7。现在的问题是给定一个正整数N，求N是最少几个素数的和。。
**输入格式:**
首先输入一个正整数N，代表测试数据的组数，接下来输入N个正整数，分别代表要处理的数，每组一个正整数满足在：6 ~ 1000000000 范围。。

**输出格式:**
输出将会有N行，每行对应一个数的歌德巴赫最新猜想这个数时候需要的最少素数个数。。

**输入样例:**
```
2
9
11
结尾无空行
```
**输出样例:**
```
2
1
结尾无空行
```

### 思路
数据很大，用筛法会segmentation fault，于是暴力筛
根据题意，偶数结果为2，素数结果为1，接着讨论奇合数，如果奇合数-2是素数，结果就是是两个素数，如果奇合数-2之后还是合数则结果为3。

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool isPrime(LL x)
{
    for (int i = 2; i <= sqrt(x); ++i)
    {
        if (!(x % i))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    LL num;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lld", &num);
        //        cout<<"++++"<<isPrime(num)<<endl;
        if (!(num % 2))
        {
            printf("2\n");
        }
        else if (isPrime(num))
        {
            printf("1\n");
        }
        else if (isPrime(num - 2))
        {
            printf("2\n");
        }
        else
        {
            printf("3\n");
        }
    }
    return 0;
}
```

## 7-3 图的深度优先遍历
### 题面
编写程序对给定的有向图（不一定连通）进行深度优先遍历，图中包含n个顶点，编号为0至n-1。本题限定在深度优先遍历过程中，如果同时出现多个待访问的顶点，则优先选择编号最小的一个进行访问，以顶点0为遍历起点。

**输入格式:**
输入第一行为两个整数n和e，分别表示图的顶点数和边数，其中n不超过20000，e不超过50。接下来e行表示每条边的信息，每行为两个整数a、b，表示该边的端点编号，但各边并非按端点编号顺序排列。

**输出格式:**
输出为一行整数，每个整数后一个空格，即该有向图的深度优先遍历结点序列。

**输入样例:**
```
3 3
0 1
1 2
0 2
结尾无空行
```
**输出样例:**
```
0 1 2 
结尾无空行
```

### 思路
用邻接链表储存图，数据输入vector，然后对每条链表里的结点排序，vis标记访问过的结点，dfs遍历，访问过的结点直接打印出来

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
vector<int> vec[20005];
bool vis[20005];
void dfs(int k)
{

    printf("%d ", k);
    vis[k] = 1;
    for (int i = 0; i < vec[k].size(); ++i)
    {
        if (!vis[vec[k][i]])
        {
            dfs(vec[k][i]);
        }
    }
}

int main()
{
    int v, e, va, vb;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &va, &vb);
        vec[va].push_back(vb);
    }
    for (int i = 0; i < v; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    return 0;
}
```
## 7-4 山
### 题面
Drizzle 前往山地统计大山的数目，现在收到这片区域的地图，地图中用0（平地）和1（山峰）绘制而成，请你帮忙计算其中的大山数目
山总是被平地四面包围着，每一座山只能在水平或垂直方向上连接相邻的山峰而形成。一座山峰四面被平地包围，这个山峰也算一个大山
另外，你可以假设地图的四面都被平地包围着。

**输入格式:**
第一行输入M,N分别表示地图的行列，接下来M行每行输入N个数字表示地图


**输出格式:**
输出一个整数表示大山的数目

**输入样例:**
```
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
结尾无空行
```
**输出样例:**
```
3
结尾无空行
```
### 思路
从G\[0][0]开始找山(1)，遇到山之后上下左右遍历找连续的山，每访问过一个就把山置为平地(0)，cnt计数输出

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
#define N 2005
bool G[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
void dfs(int x, int y)
{
    G[x][y] = 0;
    for (int i = 0; i < 4; ++i)
    {
        int tx = x + dx[i], ty = y + dy[i];
        if ((0 <= tx && tx < n) && (0 <= ty && ty < m) && G[tx][ty])
        {
            dfs(tx, ty);
        }
    }
}
int search()
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (G[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    scanf("%d %d", &n, &m);
    memset(G, 0, sizeof(G));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &G[i][j]);
        }
    }
    printf("%d\n", search());

    return 0;
}
```
## 7-5 跳跃
### 题面
Drizzle 被困到一条充满数字的方块路中，假设这条路由一个非负的整数数组m组成，Drizzle 最开始的位置在下标 start 处，当他位于下标i位置时可以向前或者向后跳跃m[i]步数，已知元素值为0处的位置是出口，且只能通过出口出去，不可能数组越界，请你通过编程计算出Drizzle能否逃出这里。

**输入格式:**
输入：第一行输入数组m的长度n 第二行输入数组元素，空格分割开 第三行输入起始下标start
**输出格式:**

**输入样例:**
```
7
4 2 3 0 3 1 2
5
结尾无空行
```
**输出样例:**
```
True
结尾无空行
```
### 思路
dfs遍历，定义bool型函数，返回是否可行

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
#define N 50005
int a[N];
int n;
bool dfs(int k)
{
    if (k < 0 || k >= n || a[k] == -1)
    {
        return 0;
    }
    int t = a[k];
    a[k] = -1;
    return (t == 0 || dfs(k + t) || dfs(k - t));
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int beginnum;
    scanf("%d", &beginnum);
    if (dfs(beginnum))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return 0;
}
```
