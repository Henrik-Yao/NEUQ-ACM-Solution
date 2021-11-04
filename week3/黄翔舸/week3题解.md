week3

双周赛：

汉诺塔一：汉诺塔是一个递归问题，且有一个思想很关键，即对于n个圆盘的移动，上面的n-1个圆盘需要翻转两次，从而使其上下与最初时的一致，最后移动一步最下面的盘子即可。

代码：

#include<iostream>
#include<cstring>//包含字符串的头文件

using namespace std;
int main()
{
	void han(int n, string a, string b, string c);//函数声明
	int n;
	cin >> n;
	string a, b, c;
	cin >> a >> b >> c;
	 han(n, a, b, c);


	return 0;

}
void han(int n, string a, string b, string c)//定义函数
{
	if (n == 1)
	{
		cout << a << "->" << c << endl;//如果n=1根据题意直接将其移到c即可
	}
	else//对于n个盘子，首先将n-1个盘子移动到b上（注意由于n=1是的定义是a到c的移动，所以在下面书写时要想a移动到b，应当是acb的书写）

​	       //接着执行最后一个盘子从a到c的移动

​           //完成后再将n-1个盘子移动上去即从b到c所以为bac

{
		han(n - 1, a, c, b);
		cout << a << "->" << c << endl;
		han(n - 1, b, a, c);
	}

}

二分查找：

法一：混过去的方法，使用一个数字j，每当有这样的m大于或者等于设定的数字，就加一。

法二:二分查找：定义一个新函数，利用左右极值得到middle，本题还要考虑相同的情况，所以要甄别满足条件的此项的前一项是否也满足，若满足则向前遍历即可。

#include<iostream>
using namespace std;
#define p 10000000
int num[p];

int main()
{
	int search(int num[], int size, int o);

	long long int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	int res;
	res=search(num, n, m);
	cout << res << endl;








	return 0;
}
int search(int num[], int size, int o)

{
	int left = 0;
	int right = size-1;
	
	while (right > left)
	{
		
		int middle = left + ((right - left) / 2);
		if (o > num[middle])
		{
			left = middle + 1;
		}
		else if (o <= num[middle])
		{
			while (num[middle - 1] >= o)
			{
				middle = middle - 1;
		}
			
				return middle + 1;
			
		}


​		
​		

	}


	return size + 1;



}

汉诺塔二：

们设g[i]g[i]为借助2个柱子移动i个盘子到某个柱子上所花费的步数，f[i]f[i]为借助1个柱子移动i个盘子到某个柱子所花费的步数，那么我们要移动n个盘子到第四根柱上，首先要把k个盘子借助中间两个柱子移动到第4个柱子上，然后把n-k个柱子借助中间一个柱子移动到第4个柱子上，然后把k个盘子借助剩下的两个柱子移动到第4个柱子上，也就是g[n]=min(g[n],2×g[k])+f[n−k](k=1...n−1)g[n]=min(g[n],2×g[k])+f[n−k](k=1...n−1),对于f[i]f[i]我们知道为2i−12i−1，递推处理出g[i]

参考：

https://blog.csdn.net/weixin_30639719/article/details/98958514?ops_request_misc=&request_id=&biz_id=102&utm_term=c++7-4%20%E6%B1%89%E8%AF%BA%E5%A1%94II%20%E7%BB%8F%E5%85%B8%E7%9A%84%E6%B1%89%E8%AF%BA%E5%A1%94%E9%97%AE%E9%A2%98%E7%BB%8F%E5%B8%B8%E4%BD%9C%E4%B8%BA%E4%B8%80%E4%B8%AA%E9%80%92%E5%BD%92%E7%9A%84&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-98958514.pc_search_result_control_group&spm=1018.2226.3001.4187

#include <iostream>

#include <cstring>

using namespace std;

int main() {
    long long int f[68];
    long long int g[68];
    f[0] = 0;
    for (int i = 1; i <= 63; i++) {
        f[i] = 2 * (f[i - 1] + 1) - 1;
    }
    long long inf = 9999999;
    fill(g + 1, g + 66, inf);
    g[1] = 1;
    g[2] = 3;
    for (int i = 3; i <= 64; i++) {
        for (int k = 1; k < i; k++) {
            if (i == 64 && k == 1)
                continue;
            g[i] = min(g[i], 2 * g[k] + f[i - k]);
        }
    }
    int n;
    while (cin >> n)
    {

        cout << g[n] << endl;
   }
    return 0;
}



汉诺塔三：

首先，设杆子从左到右为A（起始的杆子）B（中间的杆子）C（结束的杆子）设前n个盘子从A杆放到C杆次数为F（n）在放第n次的时候，要将第n+1项的盘子移到C杆，则前n个盘子需从A移至C，然后第n+1项盘子移到B，再将前n项盘子从C移向A（A移向C与C移向A这里其实是等效的），再将第n+1项的盘子移到C；最后再将前n项盘子移到C，。整个过程中，前n个盘子移动次数为3*F（n）；第n+1项盘子移动次数为1+1；

可列：F（n+1）=3*F（n）+2.通项易得 an=3^n-1

从而这个问题转化为一个数学问题

只需要利用公式，输入数字即可得到输出。

最大子段和：

使用遍历的暴力解法最简单，但是如果数据很多，显然这种方式效率不高，还有很多其他方法，如分治和动态规划。

#include<iostream>
using namespace std;

int main()
{
    int n;
    int num[1001];
    int i, j, k;
    int sum, max;
    while (cin>>n)
    {
        for (i = 0; i < n; i++)
            cin>>num[i];
        max = 0;
        for (i = 0; i < n; i++)
        {
            sum = 0;
            for (j = i; j < n; j++)
            {
                sum += num[j];
                if (sum > max)
                    max = sum;
            }
        }
        cout << max;
    }
    return 0;
}

参考：

https://blog.csdn.net/qq_42898536/article/details/108684656?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522163542290016780366574850%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=163542290016780366574850&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-1-108684656.pc_search_result_control_group&utm_term=c%2B%2B%E6%9C%80%E5%A4%A7%E5%AD%90%E6%AE%B5%E5%92%8C&spm=1018.2226.3001.4187

全排列：

使用next_permutation是一个全排列函数，从而将给出的字母输出全排列。

注意包含头文件algorithm

#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;
int main()
{
    char zimu[9];
    cin >> zimu;
    int n = strlen(zimu);
    
    sort(zimu, zimu + n);
    do
    {
        for (int i = 0; i < n; i++)
            cout << zimu[i] ;
        cout << endl;
    } 
    while (next_permutation(zimu, zimu + n));//n指的是要排列的数组长度，这个语句的意思是如果存在不同的排列就返回true，继续进行排列，反之结束。
    return 0;
}

参考：

next_permutation的用法：https://blog.csdn.net/sinat_24310873/article/details/53362908?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522163542325616780366526646%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=163542325616780366526646&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-4-53362908.pc_search_result_control_group&utm_term=next_permutation%28%29&spm=1018.2226.3001.4187



逆序个数：

参考：

（本题其实用不到）调用大数组导致数组堆栈的方法：https://blog.csdn.net/feeltouch/article/details/9400095?ops_request_misc=&request_id=&biz_id=102&utm_term=c++%E6%95%B0%E7%BB%84%E5%A0%86%E6%A0%88%E6%80%8E%E4%B9%88%E5%8A%9E&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-9400095.pc_search_result_control_group&spm=1018.2226.3001.4187



题解：要注意这道题不能在int函数内定义，会造成数组堆栈，导致段错误，所以应该在int外定义一个外部宏函数define 或者也可以consist int来设数组。逆序对可以用遍历的暴力求得结果。

#include <iostream>
using namespace std;
const int N=1000000;
int q[N];
typedef long long LL;
LL res;

LL merge_sort(int q[],int l,int r)
{
    if(l>=r)return 0;
    LL t=0;
    int mid=l+r>>1;
    t=merge_sort(q,l,mid)+merge_sort(q,mid+1,r);
    int k=0,i=l,j=mid+1;
    int tmp[r-l+1];
    while(i<=mid&&j<=r)
    {
        if(q[i]<=q[j])tmp[k++]=q[i++];
        else
        {
            t+=mid-i+1;
            tmp[k++]=q[j++];
        }
    }
    while(i<=mid)tmp[k++]=q[i++];
    while(j<=r)tmp[k++]=q[j++];
    for(int i=l,j=0;i<=r;i++,j++)q[i]=tmp[j];
    return t;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>q[i];
    res = merge_sort(q,0,n-1);
    cout<<res;
    return 0;
    
}

搜索与回溯：

7-1

思路：找到安全城市，其实就是使用邻接矩阵来存放安全城市的值，用一个二维数组存储，使用graph更改权值，并插入一个变量flag，从而根据flag输出。

#include <iostream>
using namespace std;
#define w 100

typedef struct
{
	int num[w][w];//邻接矩阵
	int dian, bian; //图当前的点数和边数
}Graph;

int main()
{
	int n;//n个安全城市
	Graph G;

	cin>>G.dian>>n>>G.bian;//输入城市的个数、安全城市的个数、路的个数
	int safecity[w];//安全城市
	for (int i = 0; i < n; i++)
	{
		cin>>safecity[i];
	}
	for (int i = 0; i < G.dian; i++)
	{
		for (int j = 0; j < G.dian; j++)
		{
			G.num[i][j] = 0;//初始化邻接矩阵为0
		}
	}
	for (int i = 0; i < G.bian; i++)
	{
		int x, y;
		cin>>x>>y;
		G.num[x][y] = 1;//将有路的城市之间权值变为1
		G.num[y][x] = 1;
	}
	int now, destination, flag = 0;//所在城市和目的地
	cin>>now>>destination;
	for (int i = 0; i < n; i++)
	{
		if (destination == safecity[i])//查询目的地是否为安全城市，做上标记
		{
			flag = 1;
			break;
		}
	}
	if (G.num[now][destination] == 1)
	{
		if (flag)//是安全城市并且有通路
			cout<< "The city " << destination <<" can arrive safely!" ;
		else //有通路但是不是安全城市
		{
			cout << "The city " << destination<<" is not safe!" ;
	
		}
	}
	else
	{
		if (flag)//是安全城市但是没有通路
			cout << "The city " << destination <<" can not arrive safely!" ;
		else cout<<"The city "<<destination<<" is not safe!" ;//不是安全城市也没有通路
	}
	return 0;
}

7-2那就别担心了

利用dfs定义一个节点函数，先设定一个节点为1，之后将此点能到达最终节点的个数返回给自己的上级节点，再度优化。上级节点接收自己的下属节点能到达最终节点的个数，更新自己。如果某个下属节点没有能到达最终节点则将自己已经更新好的返回给自己的上级节点最后设置最终节点到自己为1。

参考：https://blog.csdn.net/weixin_44417851/article/details/115920199

代码：
#include<iostream>
using namespace std;

int sou[510], path[510], vec[510][510];
int n, m, cnt, a, b;
int dfs(int x) {
    sou[x] = 1;
    if (path[x]) return path[x];
    for (int i = 1; i <= n; i++)
        if (vec[x][i])
            path[x] += dfs(i);
    return path[x];
}
int main() {
    int i;
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> a >> b;
        vec[a][b] = 1;
    }
    cin >> a >> b;
    path[b] = 1;
    cnt = dfs(a);
    int flag = 1;
    for (i = 1; i <= n; i++) {
        if (sou[i] && !path[i]) {
            flag = 0;
            break;
        }
    }
    cout << cnt<< " ";
    if (!flag)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}

7-3扫雷

思路：本题依据题意书写即可（设定bool，广度搜素），注意要求的格式，空行非常重要。

因为本体循环很多，换行的位置很关键。

#include<iostream>
#include<cstring>
using namespace std;
inline int jiansuo()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c>'9') 
    { if (c == '-')f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
    return x * f;
}
int n, m;
bool boom[25][25];

int er[25][25];
int stepx[4] = { -1,0,1 };
int stepy[4] = { -1,0,1 };

void dps(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            int nowx = x + stepx[i], nowy = y + stepy[j];
            if (nowx >= 0 && nowx < n && nowy >= 0 && nowy < m && !(nowx == x && nowy == y))
                if (boom[nowx][nowy])
                    cnt++;
        }
    }
    er[x][y] = cnt;
    if (cnt == 0)
    {
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j <= 2; j++)
            {
                int nowx = x + stepx[i], nowy = y + stepy[j];
                if (nowx >= 0 && nowx < n && nowy >= 0 && nowy < m && !(nowx == x && nowy == y))
                    if (er[x + stepx[i]][y + stepy[j]] == -1)
                        dps(x + stepx[i], y + stepy[j]);
            }
        }
    }
}
bool xunzhao()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (er[i][j] == -1 && boom[i][j] == false)
                return false;
    }
    return true;
}
int main()
{
    
    n = jiansuo(), m = jiansuo();
    int k = jiansuo(), l = jiansuo();
    memset(er, -1, sizeof(er));//memset将数组初始化
    for (int i = 1; i <= k; i++)
    {
        int x = jiansuo(), y = jiansuo();
        boom[x][y] = true;
    }
    for (int i = 1; i <= l; i++)
    {
       
        int x = jiansuo(), y = jiansuo();
        if (er[x][y] != -1) 
        { continue; }
        else if (boom[x][y])
        {
            
            cout << "You lose"<<endl; break; }
        dps(x, y);
        
        for (int i = 0; i < n; i++)
        {
            
            for (int j = 0; j < m; j++)
            {


​                
​               
                cout << er[i][j] << " ";
            }
            cout << endl;
    
        }
       
        if (xunzhao()) 
        {
            cout << "You win" <<endl;
        return 0; }
        cout << endl;
    }


}

7-4迷宫

参考：

#include<bits/stdc++.h>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int n,m,x,y,b[1001][1001],g,sc[100001];//b数组用于判断是否走过（值=-1）以及是在第几次询问时走的。sc数组代表该次询问总步数 
char a1[1001][1001];//用于输入 
void ddd(int x1,int y1,int z,int xc)//四个参数分别为横坐标、纵坐标、当前的值（0或1）、xc表示是第几次询问 
{
	if(x1<0||x1>=n||y1<0||y1>=n||b[x1][y1]!=(-1)||a1[x1][y1]-'0'!=z) return;
	//退出条件：1、越界；2、已访问过（b[i][j]!=-1);3、当前的值与上一个值一样
	//（因为在下面的递归中条件设为!z（即不一样，0变成1,1变成0） ,在这里再否定一下，双重否定为肯定，就是一样！ 
    b[x1][y1]=xc;//标记该点已经被第xc次询问走过 
	sc[xc]++; //第xc次询问的步数加一步。 
	ddd(x1-1,y1,!z,xc);//“!z”表示当前值必须与上一个值不同！ 
	ddd(x1+1,y1,!z,xc);
	ddd(x1,y1-1,!z,xc);
	ddd(x1,y1+1,!z,xc);
}
int main()
{
	//freopen("p1141.in","r",stdin);
    //freopen("p1141.out","w",stdout); 
	memset(b,-1,sizeof(b));  // b数组统一赋初值 
	cin>>n>>m;
	for(int i=0;i<=n-1;i++)
	for(int j=0;j<=n-1;j++)
	cin>>a1[i][j];
	for(int i=0;i<=m-1;i++)
	{
		cin>>x>>y;
		x--;y--;//因为数组默认都是从0开始的，而题目输出给定的要求是“第i行第j列”中的i和j明显从1开始，所以，一开始横纵坐标全部回调1
		//为什么不能直接从第1行第1列开始输入？因为第0行第0列的值不好判断，如果从1行第1列开始输入，那么第0行第0列的初始值不论是什么都与其他格子的值不同，这样就不好判断了 
		if(b[x][y]==-1) ddd(x,y,a1[x][y]-'0',i);//如果这个格子没有被走过，则开始DFS 
		else sc[i]=sc[b[x][y]];	//如果这个格子已经被走过，则直接输出走过的值，因为所有走过的都是相通的。 
	}
	for(int i=0;i<=m-1;i++) 
    { if(i==m-1)
    {cout<<sc[i];}
     else
        cout<<sc[i]<<endl;}
	return 0;
}



