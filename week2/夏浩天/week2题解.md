## 7-1 **汉诺塔问题**

*给定一个由n个圆盘组成的塔，这些圆盘按照大小递减的方式套在第一根桩柱上。现要将整个塔移动到另一根桩柱上，每次只能移动一个圆盘，且较大的圆盘在移动过程中不能放置在较小的圆盘上面。*

**~~汉诺塔问题过于经典有什么好说的(･ω･｀*)~~**

**考虑将n-1个圆盘移至第三盘，然后将第n个盘移至目标盘，随后将n-1个盘移过去**

```#include<iostream>
#include<string.h>
using namespace std;
int hlt(int n, string a, string b, string c)
{
	if (n == 1)
	{
		cout << a << "->" << c<<endl;
		return 0;
	}
	else
	{
		hlt(n - 1, a, c, b);
		hlt(1, a, b, c);
		hlt(n - 1, b, a, c);
	}

}
int main()
{
	int n;
	string a, b, c;
	cin >> n>>a>>b>>c;
	hlt(n, a, b, c);
}
```





## 7-2 **分而治之**

*分而治之，各个击破是兵家常用的策略之一。在战争中，我们希望首先攻下敌方的部分城市，使其剩余的城市变成孤立无援，然后再分头各个击破。为此参谋部提供了若干打击方案。本题就请你编写程序，判断每个方案的可行性。*

**用一个数组记录城市状态能有效节省运行时间(ฅ◑ω◑ฅ) **

~~小心第10000座城市哟(ฅ◑ω◑ฅ)~~

**记录道路两端城市编号，记录城市状态，攻击结束后询问道路两端是否均完好**

****

```#include<iostream>
using namespace std;
int cs1[10000], cs2[10000];//道路旁城市编号
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++)//写入cs12（城市编号)
	{
		cin >> cs1[i] >> cs2[i];
	}
	int k;
	cin >> k;//k组数据
	for (int i = 0;i < k;i++)
	{
		int cszt[10001] = { 0 };//城市状态，0正常1被炸
		int n1;
		cin >> n1;//n1个城市编号
		int bh;//城市编号
		for (int j = 0; j < n1; j++)
		{
			cin >> bh;
			cszt[bh] = 1;
		}
		int pdqz = 0;//判断是否全部断掉,0全断
		for (int i = 0; i < m; i++)
		{
			if (cszt[cs1[i]] == 0 && cszt[cs2[i]] == 0)
			{
				pdqz = 1;
				cout << "NO" << endl;
				break;
			}
		}
		if (pdqz == 0)
			cout << "YES" << endl;
	}
}
```





## 7-3 **归并排序**

*知识点：归并排序 给定你一个长度为 n 的整数数列，请你使用归并排序对这个数列按照从小到大进行排序，并将排好序的数列按顺序输出。*

~~建议直接sort (ฅ◑ω◑ฅ)~~

**归并排序，分而治，并而排。**~~话说这是不是算废话~~

**将数组分割，每次分割均分割为两半，若数组元素小于3则排序。随后开始合并并排序数组（比较俩数组第一个值大小，小的值成为新数组第一值，小值所在数组开始比较下一位）**

```#include <iostream>
using namespace std;
void bgpx(int*a, int q1, int q2,int*c)//[q1,q2]
{
	if (q2 - q1 == 1)//两元素
	{
		if (a[q1] > a[q2])
		{
			int zj = a[q1];
			a[q1] = a[q2];
			a[q2] = zj;
		}
		return;
	}
	else if (q2 - q1 > 1)
	{
		bgpx(a, q1, (q1 + q2) / 2, c);//左
		bgpx(a, (q1 + q2) / 2 + 1, q2, c);//右
		int fgx = (q2 + q1) / 2+1;//分割线,[q1,fgx)[fgx,q2]
		int qw = q1, qw1 = q1;
		while (qw1 < (q2 + q1) / 2+1 && fgx < q2 + 1)
		{
			//对分别已经排好序的左区间和右区间进行合并
			if (a[qw1] <= a[fgx])
			{
				c[qw] = a[qw1];
				qw++;
				qw1++;
			}
			else
			{
				c[qw] = a[fgx];
				qw++;
				fgx++;
			}
		}
		
		while (qw1 < (q2 + q1) / 2+1)//此时fgx已经等于q2+1
		{
			c[qw] = a[qw1];
			qw++;
			qw1++;
		}
		while (fgx < q2 + 1)//此时q1已经等于(q2 + q1) / 2+1
		{
			c[qw] = a[fgx];
			qw++;
			fgx++;
		}
		for (int i = q1;i < q2 + 1;i++)
			a[i] = c[i];
	}
	else
		return;
}
int c[100000];
int a[100000];
int main()
{
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];
	int q1 = 0, q2 = n-1;
	bgpx(a, q1, q2, c);
	for (int i = 0;i < n;i++)
		cout << c[i] << " ";
}