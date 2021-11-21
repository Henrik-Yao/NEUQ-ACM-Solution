# WEEK3 周报
## 7-1 生化危机
### 题面

人类正在经历一场生化危机，许多城市已经被病毒侵袭，这些城市中的人们为了避免感染病毒，计划开车逃往其他没有被病毒入侵的城市（安全城市）。有些城市之间有公路直达，有些没有。虽然他们知道哪些城市是安全的，但是不知道有没有一条安全路径能够到达安全城市（只有该路径上经过的所有城市都是安全的，该路径才是安全路径）。请你编写一个程序帮助他们判断。

**输入格式:**
输入第一行为三个正整数，分别表示所有城市个数m（m<=100）、安全城市个数n（m<=50）、公路个数k（k<=100）。随后一行给出n个安全城市的编号。随后k行，每一行给出两个整数，表示连接一条公路的两个城市编号。最后一行输入两个整数，分别表示当前所在城市s、目标城市d。每行整数之间都用空格分隔。

**输出格式:**
若目标城市已被病毒入侵（非安全城市），输出"The city i is not safe!"；若目标城市为安全城市且从当前所在城市能够经过一条安全路径到达目标城市，输出"The city can arrive safely！"；若目标城市为安全城市但是从当前所在城市没有一条安全路径到达目标城市，输出"The city can not arrive safely！"，i为目标城市编号。

**输入样例:**
```
5 2 5
3 4
0 1
0 2
0 4
1 2
2 4
0 4
结尾无空行
```
**输出样例:**
```
The city 4 can arrive safely!
结尾无空行
```
### 思路
用邻接数组储存数据，查询是否有通路

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
struct Mp
{
    int cnct[101][101];
    int v, w;
};
int main()
{
    int n;
    Mp m;
    scanf("%d %d %d", &m.v, &n, &m.w);
    int safeCity[101];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &safeCity[i]);
    }
    for (int i = 0; i < m.v; i++)
    {
        for (int j = 0; j < m.v; j++)
        {
            m.cnct[i][j] = 0;
        }
    }
    for (int i = 0; i < m.w; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        m.cnct[x][y] = 1;
        m.cnct[y][x] = 1;
    }
    int now, target, flag = 0;
    scanf("%d %d", &now, &target);
    for (int i = 0; i < n; i++)
    {
        if (target == safeCity[i])
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        if (m.cnct[now][target])
        {
            printf("The city %d can arrive safely!", target);
        }
        else
        {
            printf("The city %d can not arrive safely!", target);
        }
    }
    else
    {
        if (m.cnct[now][target])
        {
            printf("The city %d is not safe!", target);
        }
        else
        {
            printf("The city %d is not safe!", target);
        }
    }
    return 0;
}
```

## 7-2 那就别担心了
### 题面

博主将这种逻辑推演称为“逻辑自洽”，即从某个命题出发的所有推理路径都会将结论引导到同一个最终命题（开玩笑的，千万别以为这是真正的逻辑自洽的定义……）。现给定一个更为复杂的逻辑推理图，本题就请你检查从一个给定命题到另一个命题的推理是否是“逻辑自洽”的，以及存在多少种不同的推理路径。例如上图，从“你遇到难题了吗？”到“那就别担心了”就是一种“逻辑自洽”的推理，一共有 3 条不同的推理路径。

**输入格式:**
输入首先在一行中给出两个正整数 N（1<N≤500）和 M，分别为命题个数和推理个数。这里我们假设命题从 1 到 N 编号。

接下来 M 行，每行给出一对命题之间的推理关系，即两个命题的编号 S1 S2，表示可以从 S1 推出 S2。题目保证任意两命题之间只存在最多一种推理关系，且任一命题不能循环自证（即从该命题出发推出该命题自己）。

最后一行给出待检验的两个命题的编号 A B。

**输出格式:**
在一行中首先输出从 A 到 B 有多少种不同的推理路径，然后输出 Yes 如果推理是“逻辑自洽”的，或 No 如果不是。

题目保证输出数据不超过 10 
9
 。

**输入样例:**
```
7 8
7 6
7 4
6 5
4 1
5 2
5 3
2 1
3 1
7 1
结尾无空行
```
**输出样例:**
```
3 Yes
结尾无空行
```

### 思路
e中储存第i个命题可以推出的命题编号，a,b表示起始路径和终点路径，sa[i]储存从第i个命题到第b个命题有多少种不同的推理路径，sa[b]的初始值为1。cnct表示推理是否逻辑自洽。通过记忆化dfs从a点开始更新sa的值

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int n, m, v, w, a, b, cnct, sa[501];
vector<int> e[501];
int dfs(int ii)
{
    if (sa[ii] != 0)
    {
        return sa[ii];
    }
    for (int j : e[ii])
    {
        if (sa[j] == 0)
        {
            dfs(j);
        }
        sa[ii] += sa[j];
    }
    if (sa[ii] == 0)
    {
        cnct = 1;
    }
    return sa[ii];
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d %d", &v, &w);
        e[v].push_back(w);
    }
    scanf("%d %d", &a, &b);
    sa[b] = 1;
    dfs(a);
    printf("%d ", sa[a]);
    if (cnct)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }
    return 0;
}
```

## 7-3 扫雷游戏
### 题面

扫雷是一款经典游戏，也是Windows操作系统最早引入的一款游戏，其最为经典的版本是Windows XP操作系统自带的扫雷游戏，曾风靡一个时代，是一代人的永恒记忆。
简单来说，其游戏界面由n行m列方格组成，其中k个方格后面隐藏着地雷。当用户点击一个方格时：
（1）如果该方格后面隐藏着地雷，则游戏结束，用户失败。
（2）如果该方格不是地雷，则该方格被打开：
若该方格与地雷相邻（即该方格上、下、左、右、左上、左下、右上、右下相邻的8个方格内有地雷），则该方格处显示一个数字，表示其周围8个方格中的地雷数。
若该方格未与地雷相邻（即该方格周围8个格子内没有地雷），则该方格的未被打开的邻居（即与该方格上、下、左、右、左上、左下、右上、右下相邻的方格）、邻居的邻居、邻居的邻居的邻居……都会被逐级打开，直到某方格与地雷相邻。这期间每个方格的处理方式同（2）。
（3）当所有没隐藏地雷的方格均被打开（即所有没打开的方格后都有地雷），则游戏结束，用户获胜。

请编写程序从初始界面开始，对于一系列用户的点击，求出点击之后的游戏界面。未打开的方格用-1表示，即游戏初始时为n行m列-1。已打开且未与雷相邻的方格用0表示，已打开且与雷相邻的方格用数字a (1≤ a ≤ 8)表示，即与之相邻的地雷数。

**输入格式:**
输入第一行是4个正整数n、m、k和l，其中n、m、k的含义如前所述。接下来k行，每行2个整数i和j，表示每个雷的坐标，即雷在第i行第j列的方格里。接下来l行，每行2个整数i和j，表示用户点击信息，即用户点击了第i行第j列的方格。m,n不超过20，k不超过50，l不超过200，0≤i<n，0≤j<m.

**输出格式:**
对于用户的每个点击：（1）如果用户点击的方格是已被打开的方格，则点击无效，忽略该点击。（2）如果点击的方格是地雷，则输出“You lose”，程序退出；（3）如果点击的方格不是地雷，则输出点击后的游戏界面，即n行m列整数，每个整数后一个空格，此时若用户获胜，则再输出“You win”。注：对用户每个有效点击所输出的信息用一个空行间隔。

**输入样例:**
```
5 5 1 1
0 0
4 4

结尾无空行
```
**输出样例:**
```
-1 1 0 0 0 
1 1 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
0 0 0 0 0 
You win
结尾无空行
```

### 思路
一个模拟，用dfs

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int fld[21][21], mine[21][21], vis[21][21], cfld[21][21];
int n, m, k, l, num;
int dx[8] = {1, -1, -1, -1, 0, 0, 1, 1};
int dy[8] = {1, -1, 0, 1, -1, 1, -1, 0};
int judge(int x, int y);
int cfcg(int x, int y);
void f(int x, int y);
int main()
{
    int a, b;
    scanf("%d %d %d %d", &n, &m, &k, &l);
    memset(fld, -1, sizeof(fld));
    for (int i = 0; i < k; ++i)
    {
        scanf("%d %d", &a, &b);
        mine[a][b] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cfld[i][j] = cfcg(i, j);
        }
    }
    for (int i = 0; i < l; ++i)
    {
        int xi, yi;
        cin >> xi >> yi;
        if (mine[xi][yi] == 1)
        {
            printf("You lose");
            break;
        }
        if (fld[xi][yi] != -1)
            continue;
        if (fld[xi][yi] == -1)
        {
            f(xi, yi);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    printf("%d ", fld[i][j]);
                }
                printf("\n");
            }
        }
        if (n * m - k == num)
        {
            printf("You win");
        }
        printf("\n");
    }
    return 0;
}
void f(int x, int y)
{
    vis[x][y] = 1;
    if (!judge(x, y))
    {
        fld[x][y] = cfld[x][y];
        for (int i = 0; i < 8; ++i)
        {
            int xi = x + dx[i];
            int yi = y + dy[i];
            if (xi < 0 || xi >= n || yi < 0 || yi >= m || vis[xi][yi])
                continue;
            f(xi, yi);
        }
    }
    else
    {
        fld[x][y] = cfld[x][y];
    }
    num++;
}
int cfcg(int x, int y)
{
    int re = 0;
    for (int i = 0; i < 8; i++)
    {
        int xi, yi;
        xi = x + dx[i];
        yi = y + dy[i];
        if (xi < 0 || xi >= n || yi < 0 || yi >= m)
            continue;
        if (mine[xi][yi] == 1)
            re++;
    }
    return re;
}
int judge(int x, int y)
{
    int re = 0;
    for (int i = 0; i < 8; i++)
    {
        int xi, yi;
        xi = x + dx[i];
        yi = y + dy[i];
        if (xi < 0 || xi >= n || yi < 0 || yi >= m)
            continue;
        if (mine[xi][yi] == 1)
            re = 1;
    }
    return re;
}
```
## 7-4 01迷宫
### 题面

有一个仅由数字0与1组成的n * n格迷宫。若你位于一格0上，那么你可以移动到相邻4格中的某一格1上，同样若你位于一格1上，那么你可以移动到相邻4格中的某一格0上。
你的任务是：对于给定的迷宫，询问从某一格开始能移动到多少个格子（包含自身）。

**输入格式:**
第1行为两个正整数n,m。

下面n行，每行n个字符，字符只可能是0或者1，字符之间没有空格。

接下来m行，每行2个用空格分隔的正整数i,j，对应了迷宫中第i行第j列的一个格子，询问从这一格开始能移动到多少格。 （n <= 1000, m <= 100000）

**输出格式:**
m行，对于每个询问输出相应答案。

**输入样例:**
```
2 2
01
10
1 1
2 2
结尾无空行
```
**输出样例:**
```
4
4
结尾无空行
```
### 思路
BFS+记忆化

### 代码
```c++
#include <bits/stdc++.h>
int n, m, a[1000001][3], cnt, aa[100001], k;
int x[4] = {0, 1, 0, -1}, y[4] = {1, 0, -1, 0}, d[1001][1001];
bool b[1001][1001];
inline void bfs(int i, int j)
{
    cnt++;
    d[i][j] = k;
    int fm = 1, lt = 2;
    a[2][1] = i, a[2][2] = j;
    while (fm < lt)
    {
        fm++;
        for (register int q = 0; q <= 3; q++)
        {
            int xa = a[fm][1] + x[q];
            int ya = a[fm][2] + y[q];
            if (xa > 0 && xa <= n && ya > 0 && ya <= n && !d[xa][ya] && b[a[fm][1]][a[fm][2]] != b[xa][ya])
            {
                cnt++;
                lt++;
                a[lt][1] = xa;
                a[lt][2] = ya;
                d[xa][ya] = k;
            }
        }
    }
    aa[k] = cnt;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (register int i = 1; i <= n; i++)
        for (register int j = 1; j <= n; j++)
        {
            char c;
            scanf(" %c", &c);
            if (c == '1')
                b[i][j] = 1;
        }
    for (register int i = 1; i <= m; i++)
    {
        int xb, yb;
        scanf("%d%d", &xb, &yb);
        k++;
        if (d[xb][yb])
            cnt = aa[d[xb][yb]];
        else
            bfs(xb, yb);
        printf("%d\n", cnt);
        cnt = 0;
    }
}
```