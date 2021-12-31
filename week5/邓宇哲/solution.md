# 7-1 愿天下有情人都是失散多年的兄妹
我TMD真的不会广度优先搜索，我只能用深度优先搜索，要记录层数，超过5层就要回退，网上说这叫做深度受限搜索(DLS)，骚的一批，网上没模板，气死人。

要记得“父母”也会结婚，我真的没想到，所以在录入数据的时候要记得给父母标上性别，不然父母结婚会变成同性恋233333


设 人 类，保存性别、父亲索引、母亲索引。
~~~c++
#include <algorithm>
#include <iostream>
using namespace std;//要深度遍历两个人，所以要两个缓存区
int path1[100] = {0};//深度遍历的缓存，储存遍历数据
int path2[100] = {0};
int depth1 = 0, deep1 = 0;//分别是深度遍历缓存的指针、深度遍历的层数
int depth2 = 0, deep2 = 0;
void bfs(int, int);
struct people
{
    char sex;
    int fid = -1;
    int mid = -1;
};
people guy[100000];
main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;
        cin >> guy[id].sex >> guy[id].fid >> guy[id].mid;
        if (guy[id].fid != -1)//这里最好给父母亲标好性别，有的人只存在ID
        {
            guy[guy[id].fid].sex = 'M';
        }
        if(guy[id].mid!=-1)
        {
            guy[guy[id].mid].sex = 'F';
        }
    }
    cin >> n;
    int i;
    for (i = 0; i < n; i++)
    {
        depth1 = 0, depth2 = 0;//归零开始新一轮的工作
        int g1, g2;
        cin >> g1 >> g2;
        if (guy[g1].sex == guy[g2].sex)//同性恋
        {
            cout << "Never Mind" << endl;
            continue;
        }
        bfs(g1, 1), bfs(g2, 2);//对双方分别遍历
        deep1 = 0, deep2 = 0;//归零以备下次调用
        bool done = 0;          //优化，用于跳出循环节省时间
        for (int k = 0; k < depth1; k++)
        {
            for (int l = 0; l < depth2; l++)
            {
                if (path1[k] == path2[l])
                {
                    done = 1;//优化
                    break;
                }
            }
            if (done == 1)//优化
            {
                break;
            }
        }
        if (i != n - 1)//对输出格式的调整
        {
            if (done == 1)
            {
                cout << "No" << endl;
            }
            else
                cout << "Yes" << endl;
        }
        else
        {
            if (done == 1)
            {
                cout << "No";
            }
            else
                cout << "Yes";
        }
    }
}
void bfs(int s, int j)//不是广度优先，是深度优先
{
    if (s == -1)
    {
        return;//此人无法考证，返回
    }
    if ((deep1 == 5 && j == 1) || (deep2 == 5 && j == 2))
    {
        return;//超过5层，停止搜索，返回
    }

    if (j == 1)
    {
        path1[depth1++] = s;//记录在缓存中
        deep1++;//遍历前，层数增肌
        bfs(guy[s].fid, 1);//对父母遍历
        bfs(guy[s].mid, 1);
        deep1--;//关键，层数回退
    }
    else        //同理
    {
        path2[depth2++] = s;
        deep2++;
        bfs(guy[s].fid, 2);
        bfs(guy[s].mid, 2);
        deep2--;
    }
}
~~~
# 7-2 哥德巴赫最新猜想
本程序采用 米勒-罗宾 素性检验的方法，概率性的检验一个数是否是素数，函数的第2个参数为n，即正确率为$(3/4)^n$,这里取1，得到短的运行时间。，运行时间为4ms。
```c++
#include <iostream>
using namespace std;
long long mod_mul(long long a, long long b, long long mod);
long long mod_pow(long long a, long long n, long long mod);
bool isprime(long long ,int);
main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n;i++)
	{
		long long a;
		cin >> a;
		if (a % 2 == 0)             //偶数
		{
			cout << 2 << endl;
		}
		else if (isprime(a,1))      //质数
		{
			cout << 1 << endl;
		}
		else if(isprime(a-2,1))     //a-2是质数
		{
			cout << 2 << endl;
		}
		else                        //其他情况
			cout << 3 << endl;
	}
}
long long mod_mul(long long a, long long b, long long mod) //快速乘法取余
{
	long long res = 0;
	while (b)
	{
		if (b % 2)
			res = (res + a) % mod;
		a = (a + a) % mod;
		b /= 2;
	}
	return res;
}

long long mod_pow(long long a, long long n, long long mod) //快速幂取余
{
	long long ans = 1;
	while (n > 0)
	{
		if (n % 2)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		n /= 2;
	}
	return ans;
}
bool isprime(long long n, int rate)    // Miller-Rabin随机算法检测n是否为素数,并且测试rate次
{
    srand((int)time(0));                    //产生随机数种子
    if (n == 2)                             //是2就返回true
        return true;
    if (n < 2 || !(n % 2))                  //小于2或者是2的倍数返回false
        return false;
    long long m = n - 1, k = 0;             //对于给定的n，找到k、m使得"n-1=(2^k)*m"成立
    while (!(m % 2))                        //保证m是奇数
    {
        k++;
        m /= 2;
    }
    for (int i = 1; i <= rate; i++)         // Miller-Rabin测试rate次
    {
        long long a = rand() % (n - 1) + 1; //随机从[1,n-1]中选取a
        long long x = mod_pow(a, m, n);     //求出(a^m)%n
        long long y;
        for (int j = 1; j <= k; j++)        //对x不断进行(平方后对n取模)操作，取遍[1,k]
        {
            y = mod_mul(x, x, n);
            if (y == 1 && x != 1 && x != n - 1) 
                return false;               //只要得到1，就未能通过检验，是合数
            x = y;                          //赋值并进行新一轮检验
        }
        if (y != 1)                         //取遍后如果y!=1,则是合数
            return false;
    }
    return true;                            //检验过程中没有return false,数字n通过检验
}
```
# 7-3 图的深度优先遍历
设点类，保存 连接的点、是否被完成过、编号等信息。记得在对子节点遍历前先给子节点排序。
```c++
#include <algorithm>
#include <iostream>
using namespace std;
int path[20000]={0};//记录遍历路径
int depth = 0;//对路径元素进行操作的指针
void dfs(int);
struct node
{
    int connect[500] = {0};
    bool done = 0;
    int num = 0;
};
node nodes[20000];
main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    +++{
        int k;
        cin >> k;
        cin >> nodes[k].connect[nodes[k].num];
        nodes[k].num++;
    }
    for (int i = 0; i < n; i++)
    {
        if(nodes[i].done==0)
        {
            dfs(i);
        }
    }
    for (int i = 0; i < depth;i++)
    {
        cout << path[i] << ' ';
    }
}
void dfs(int s)
{
    if (nodes[s].done)
    {
        return;//探索过，返回
    }
    path[depth++] = s;//记录
    nodes[s].done = 1;//标记
    sort(nodes[s].connect, nodes[s].connect + nodes[s].num;//遍历前先给子节点排序
    for (int i = 0; i < nodes[s].num; i++)
    {
        dfs(nodes[s].connect[i]);
    }
}
```
# 7-4 山
和走迷宫的题好像啊。属于遍历、标记、连接块方面的题目。
```c++
#include <algorithm>
#include <iostream>
using namespace std;
struct node
{
    int num = 0;
    bool done = 0;
};
node nodes[2002][2002];
void dfs(int, int);
int sum=0;
main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <=n;j++)
        {
            cin >> nodes[i][j].num;
        }
    }
    for (int i = 1; i <= m;i++)
    {
        for (int j = 1; j <=n;j++)
        {
            if((!nodes[i][j].done)&&nodes[i][j].num==1)//如果没被标记过且数值为1，就进行深度优先遍历
            {
                dfs(i, j);
                sum++;//山的数量增加
            }
        }
    }
    cout << sum;
}
void dfs(int i ,int j)
{
    if (nodes[i][j].done==1)
    {
        return;
    }
    nodes[i][j].done = 1;
    if(nodes[i+1][j].num==1)
    {
        dfs(i + 1, j);
    }
    if(nodes[i-1][j].num==1)
    {
        dfs(i - 1, j);
    }
    if(nodes[i][j+1].num==1)
    {
        dfs(i, j+1);
    }
    if(nodes[i][j-1].num==1)
    {
        dfs(i , j-1);
    }
}
```
# 7-5 跳跃
低难度基本深度优先搜索，属于能否到达终点一类的题，注意控制不要让数组越界。
~~~c++
#include <iostream>
using namespace std;
long m[50001];
bool done[50001];
bool dfs(long);
bool out(int);
long s;
long n;
main()
{
    cin >> n;
    for (long i = 0; i < n; i++)
    {
        cin >> m[i];
    }
    cin >> s;
    if (dfs(s))
    {
        cout << "True";
    }
    else
        cout << "False";
}
bool out(int i)
{
    return (i < 0 || i >= n);
}
bool dfs(long s)
{
    if (m[s] == 0)
    {
        return true;
    }
    done[s] = 1;
    if (!out(s + m[s]) && !done[s + m[s]])
    {
        if (dfs(s + m[s]))
        {
            return true;
        }
    }
    if (!out(s - m[s]) && !done[s - m[s]])
    {
        if (dfs(s - m[s]))
        {
            return true;
        }
    }
    return false;
}
~~~ 