# ACM第二次双周赛总结

j了，给我答蒙了，下次能给错误的测试样例吗？emmm

#### 7-1 愿天下有情人都是失散多年的兄妹 

###### 题目描述：

呵呵。大家都知道五服以内不得通婚，即两个人最近的共同祖先如果在五代以内（即本人、父母、祖父母、曾祖父母、高祖父母）则不可通婚。本题就请你帮助一对有情人判断一下，他们究竟是否可以成婚？

###### 输入格式：

输入第一行给出一个正整数`N`（2 ≤ `N` ≤104），随后`N`行，每行按以下格式给出一个人的信息：

```
本人ID 性别 父亲ID 母亲ID
```

其中`ID`是5位数字，每人不同；性别`M`代表男性、`F`代表女性。如果某人的父亲或母亲已经不可考，则相应的`ID`位置上标记为`-1`。

接下来给出一个正整数`K`，随后`K`行，每行给出一对有情人的`ID`，其间以空格分隔。

注意：题目保证两个人是同辈，每人只有一个性别，并且血缘关系网中没有乱伦或隔辈成婚的情况。

###### 输出格式：

对每一对有情人，判断他们的关系是否可以通婚：如果两人是同性，输出`Never Mind`；如果是异性并且关系出了五服，输出`Yes`；如果异性关系未出五服，输出`No`。

###### c++代码：
```c++
#include<iostream>
#include<cstring>
using namespace std;

bool judge;
bool jud[200005];
int elem, fu[200005], mu[200005];
char sex[200005];

void relative(int n, int era)
{
    if (era > 5 || n == -1 || n == 0) return;
    if (jud[n]) judge = 1;
    jud[n] = 1;
    relative(fu[n], era + 1);
    relative(mu[n], era + 1);
    return;
}

int main()
{
    int n;
    cin >> n;
    while (n--) cin >> elem >> sex[elem] >> fu[elem] >> mu[elem];
    int k, male, female;
    cin >> k;
    while (k--)
    {
        cin >> male >> female;
        if (sex[male] == sex[female])
        {
            cout << "Never Mind" << endl;
            continue;
        }
        judge = 0;
        memset(jud, 0, sizeof(jud));
        relative(male, 1);
        relative(female, 1);
        if (judge == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
```


#### 7-2 哥德巴赫最新猜想 

这就是判断素数的问题。

###### 题目详情：

X遇到一个关于素数的问题需要你这位大牛帮他解决。素数（prime  number）又称质数。一个大于1的自然数，除了1和它本身外，不能整除以其他自然数，换句话说就是该数除了1和它本身以外不再有其他的因数，否则称为合数。哥德巴赫是德国数学家。出生于格奥尼格斯别尔格（现名加里宁城）。曾在英国牛津大学学习。原学法学，由于在欧洲各国访问期间结识了贝努利家族，所以对数学研究产生了兴趣。曾担任中学教师。1725年，到了俄国，同年被选为彼得堡科学院院士。1725年~1740年担任彼得堡科学院会议秘书。1742年，移居莫斯科，并在俄国外交部任职。1742年，哥德巴赫在教学中发现，每个不小于6的偶数都是两个素数之和。如6＝3＋3，14＝3＋11等等。公元1742年6月7日哥德巴赫写信给当时的大数学家欧拉，欧拉在6月30日给他的回信中说，他相信这个猜想是正确的，但他不能证明。叙述如此简单的问题，连欧拉这样首屈一指的数学家都不能证明，这个猜想便引起了许多数学家的注意。我们不需要你去证明哥德巴赫猜想。我们假设哥德巴赫猜想是正确的，一个不小于6的偶数，都是两个素数之和。例如14＝3＋11，也可以表示为14=7+7。现在的问题是给定一个正整数N，求N是最少几个素数的和。。

###### 输入格式:

首先输入一个正整数N，代表测试数据的组数，接下来输入N个正整数，分别代表要处理的数，每组一个正整数满足在：6 ~ 1000000000 范围。。

###### 输出格式:

输出将会有N行，每行对应一个数的歌德巴赫最新猜想这个数时候需要的最少素数个数。。

###### 解题思路：

接受数据后，除了2和4以外的所有偶数都符合哥德巴赫猜想，而4也是两个素数（2+2）的和。奇数可以拆为2和一个素数或者一个偶数（除了2以外）和一个素数，如果前者成立则为两个，否则为三个。

###### c++代码：

```c++
#include<iostream>
#include<math.h>
using namespace std;

bool primenum(int n) {
      for(int i = 2;i <= sqrt(n);i++){
          if(n % i == 0) return false;
      }
      return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int temp;
        cin>>temp;
        if(temp % 2 == 0) cout<<2<<endl;
        else if(primenum(temp)) cout<<1<<endl;
        else if(primenum(temp - 2)) cout<<2<<endl;
        else cout<<3<<endl;
    }
}
```

#### 7-3 图深度优先遍历

这题目描述的，跟没描述差不多。。。看了半天才看懂

###### 题目详情：

编写程序对给定的有向图（不一定连通）进行深度优先遍历，图中包含n个顶点，编号为0至n-1。本题限定在深度优先遍历过程中，如果同时出现多个待访问的顶点，则优先选择编号最小的一个进行访问，以顶点0为遍历起点。

###### 输入格式:

输入第一行为两个整数n和e，分别表示图的顶点数和边数，其中n不超过20000，e不超过50。接下来e行表示每条边的信息，每行为两个整数a、b，表示该边的端点编号，但各边并非按端点编号顺序排列。

###### 输出格式:

输出为一行整数，每个整数后一个空格，即该有向图的深度优先遍历结点序列。

###### 解题思路：

根据输入的n，从0到n遍历节点头，再将分支的节点从小到大输出即可（以后打竞赛的题目都这么不明不白吗？）。

###### c++代码：

```c++
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Point {
    int start;
    int next;
    bool thought;
};

Point rope[51];
bool num[20001] = { 0 };
int n, e;

bool cmp(Point a, Point b) {
    if (a.start == b.start)return a.next < b.next;
    else return a.start < b.start;
}

void search(int a) {
    for (int i = 0; i < e; i++) {
        if (!rope[i].thought) continue;
        if (rope[i].start == a) {
            rope[i].thought = false;
            int temp = rope[i].next;
            if (num[temp]) {
                cout << temp << " " ;
                num[temp] = false;
            }
            search(temp);
        }

    }

}

int main() {
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        cin >> rope[i].start >> rope[i].next;
        rope[i].thought = true;
    }
    for (int i = 0; i <= n; i++) num[i] = true;
    sort(rope, rope + e, cmp);
    for (int i = 0; i < n; i++){
        if(num[i]){
            cout << i <<" ";
            num[i] = false;
        }
        search(i);
    }

}
```

#### 7-4 山 

使用数组存储特定顺序的数字，在使用它是使用循环逐个调用是极好的做法。（莫名其妙的段错误就没了）

###### 题目详情：

**Drizzle** 前往山地统计大山的数目，现在收到这片区域的地图，地图中用`0（平地）`和`1（山峰）`绘制而成，请你帮忙计算其中的大山数目
山总是被平地四面包围着，每一座山只能在水平或垂直方向上连接相邻的山峰而形成。一座山峰四面被平地包围，这个山峰也算一个大山
另外，你可以假设地图的四面都被平地包围着。

###### 要求:

输入：第一行输入M,N分别表示地图的行列，接下来M行每行输入N个数字表示地图
输出：输出一个整数表示大山的数目

###### 解题思路：

输入时计算‘1’的个数，然后从数组内有‘1’的地方出发，进行递归：从数组内有‘1’的地方出发，像四个方向移动，将经过‘1’的的地方变为零。每将一个‘1’变为‘0’，就将‘1’的个数减一。最后剩余的‘1’的个数即为答案。

###### c++代码：

```c++
#include<iostream>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1,0,-1,0 };
int hill[2001][2001];
int x, y;
long long int ans = 0;

void mountain(int a, int b) {
    hill[a][b] = 0;
    for (int i = 0; i < 4; i++) {
        int xx = a + dx[i], yy = b + dy[i];
        if (xx < 0 || xx > x - 1 || yy < 0 || yy > y - 1)continue;
        if (hill[xx][yy]) {
            ans--;
            mountain(xx, yy);
        }
    }
}

int main() {
    cin >> x >> y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> hill[i][j];
            if (hill[i][j]) {
                ans++;
            }
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (hill[i][j])mountain(i, j);
        }
    }
    cout << ans;
}
```

#### 7-5 跳跃 

下标和第几个之间的区别。

###### 题目详情：

Drizzle 被困到一条充满数字的方块路中，假设这条路由一个非负的整数数组`m`组成，Drizzle 最开始的位置在下标 `start` 处，当他位于下标`i`位置时可以向前或者向后跳跃`m[i]`步数，已知元素值为`0`处的位置是出口，且只能通过出口出去，不可能数组越界，请你通过编程计算出Drizzle能否逃出这里。

###### 要求:

输入：第一行输入数组`m`的长度`n`  第二行输入数组元素，空格分割开 第三行输入起始下标`start` 

###### 解题思路：

就是按照他可能跳往的方向进行搜索就行了，这里用的深度搜索。

###### c++代码：

```c++
#include<iostream>
using namespace std;

int road[100001];
int OK[10001];
bool flag = false;

void jumping(int a) {
    OK[a] = false;
    if (road[a] == 0) {
        flag = true;
        return;
    }
    else {
        if (a - road[a] > 0 && OK[a - road[a]]) jumping(a - road[a]);
        if (a + road[a] > 0 && OK[a + road[a]]) jumping(a + road[a]);
    }
}

int main() {
    int n,start;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        OK[i] = true;
        cin >> road[i];
    }
    cin >> start;
    jumping(++start);//需要加1
    if (flag) cout << "True";
    else cout << "False";
}
```



#### 7-6 求素数个数

这道题就是两周前一摸一样的题。



###### 题目详情：

求素数的个数。本题要求编写一个程序，求1~n的素数个数。 要求至少给出两种解法，对于相同的n，给出这两种解法的结果，通过相关数据进行测试，目的是通过对比同一问题不同解法的绝对执行时间体会如何设计“好”的算法。

###### 输入格式:

输入在一行中给出1个整数n(<= 10 000 000)。

###### 输出格式:

对每一组输入，在一行中输出1~n的素数个数。

###### 解题思路：

欧拉筛，每个和数只能筛一次，普通筛是绝对不行的（枚举就更不行了）。

###### c++代码：

```c++
#include<iostream>
using namespace std;

bool num[10000001] = { false };
int prime[10000001] = { 0 };

int main() {
    int n, pos = 2, ans = 0;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (!num[i]) prime[pos++] = i;
        //欧拉筛的精妙之处：
        for (int j = 2; j < pos && i * prime[j] <= n; j++) {
            num[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!num[i]) ans++;
    }
    cout << ans;
}
```

