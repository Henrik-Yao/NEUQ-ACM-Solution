## **7-1 词典**

*你刚从滑铁卢搬到了一个大城市，这里的人们讲一种难以理解的外语方言。幸运的是，你有一本字典来帮助你理解它们。*

**没啥说的，map完事**

```#include<iostream>
#include<map>
using namespace std;
map<string,string> dic;
int main()
{
    int n,m;cin>>n>>m;
    while(n--)
    {
        string lsz1,lsz2;cin>>lsz1>>lsz2;
        dic[lsz2]=lsz1;
    }
    while(m--)
    {
        string lsz;cin>>lsz;
        if(dic[lsz]=="")cout<<"eh"<<endl;
        else cout<<dic[lsz]<<endl;
    }
}
```



## **7-2 神秘密码**

*传说二战时X国收到了上帝的一串密码，只有解开密码，才能阻止战争的继续进行，世界才会恢复和平。解开密码的第一道工序就是解压缩密码，上帝对于连续的若干个相同的子串"X"会压缩为"[DX]"的形式(D是一个整数且1<=D<=99),比如说字符串"CBCBCBCB"就压缩为"[4CB]"或者"[2[2CB]]",类似于后面这种压缩之后再压缩的称为二重压缩。如果是"[2[2[2CB]]]"则是三重的。现在我们给你上帝发送的密码，请你对其进行解压缩。*

**申请多个字符串存放子串，最终构造解压完成的母串**

```#include <iostream>
using namespace std;
int len, en;
int cd[100000];
string a, lsz[100000];
int main() 
{
	cin >> a;
	len = a.length();//原字符串长度
	lsz[0] = "";//处理后字符串
	for (int i = 0; i < len; ) 
	{
		if (a[i] == '[') 
		{
			en++;
			lsz[en] = "";
			i++;
			for (cd[en] = 0; a[i]<='9'&&a[i]>='0'; i++)
				cd[en] = cd[en] * 10 + a[i] - 48;
		}
		else if (a[i] == ']') 
		{
			for (int j = 1; j <= cd[en];j++) 
				lsz[en - 1] += lsz[en];
			en--;
			i++;
		}
		else 
		{
			lsz[en] += a[i];
			i++;
		}
	}
	cout << lsz[0];
	return 0;
}
```



## **7-3 删除公共字符**

*输入两个字符串，从第一个字符串中删除第二个字符串中的所有字符。例如，输入“They are students.”和“aeiou”，则删除之后的第一个字符串变成“Thy r stdnts”。*

**用一个数组存一下要删的字符，对主串输出时判定一下就好了**

**注意：多组输入**

```#include <iostream>
#include<string.h>
using namespace std;
int len;
char s1[1000000], s2[10000];
bool vis[200];
int main() 
{
	while (cin.getline(s1, 1000000)) 
	{
		cin.getline(s2, 10000);
		len = strlen(s1);
		memset(vis, 0, 200);
		for (int i = 0; s2[i]; i++)
			vis[int(s2[i])] = 1;
		for (int i = 0; i < len; i++) 
			if (!vis[int(s1[i])])
				putchar(s1[i]);
		puts("");
	}
}
```



## **7-4 最长有序子序列**

*对于给定一个数字序列 (*a*1，*a*2，…，*a**n*) ，如果满足*a*1<*a*2<…<an，则称该序列是有序的。若在序列(*a*1，*a*2，…，*a*n*) 中删除若干元素得到的子序列是有序的，则称该子序列为一个有序子序列。有序子序列中长度最大的即为最长有序子序列。*

**~~过于经典，没啥说的~~**

**用数组存一下每个数之后最长有序子列的长度，取最大即答案**

```
#include <iostream>
using namespace std;
int t;
int a[10000], gs[10000];
int main()
{
    cin >> t;
    for(int qw=0;qw<t;qw++)
    {
        if(qw)cout<<endl;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            gs[i] = 1;
        }
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j < i; j++) 
            {
                if (a[j] < a[i]) 
                    gs[i] = max(gs[i], gs[j] + 1);
            }
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) 
            ans = max(ans, gs[i]);
        cout << ans << endl;
    }
}
```



## **7-5 0-1背包问题**

*给定n种物品（每种仅一个）和一个容量为c的背包，要求选择物品装入背包，使得装入背包中物品的总价值最大。*

**经典背包问题**

~~贪心算法并不太稳定哦~~

```#include <iostream>
#include<string.h>
using namespace std;
int n, m;
int weight[10000], value[10000], f[10000];
int main()
{
    while (cin >> n >> m)
    {
        memset(weight, 0, 10000);
        memset(value, 0, 10000);
        memset(f, 0, 10000);
        for (int i = 0; i < n; i++) 
            cin >> weight[i];
        for (int i = 0; i < n; i++) 
            cin >> value[i];
        for (int i = 0; i < n; i++) 
        {
            for (int j = m; j >= weight[i]; j--)
                f[j] = max(f[j], f[j - weight[i]] + value[i]);
        }
        cout << f[m] << endl;
    }
}