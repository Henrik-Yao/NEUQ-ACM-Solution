# 双周赛 题解
## 7-1 最大子段和
### 题面

给定n个整数（可能为负数）组成的序列a[1],a[2],a[3],…,a[n]，求该序列如a[i]+a[i+1]+…+a[j]的子段和的最大值。当所给的整数均为负数时，定义子段和为0。

要求算法的时间复杂度为O(n)。

**输入格式:**
输入有两行：

第一行是n值（1<=n<=10000)；

第二行是n个整数。

**输出格式:**

输出最大子段和。

**输入样例:**
在这里给出一组输入。例如：
```
6
-2 11 -4 13 -5 -2
结尾无空行
```
**输出样例:**
在这里给出相应的输出。例如：
```
20
结尾无空行
```
### 思路
用了一个假dp，max存最大值

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, flag = 0;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > 0)
            flag = 1;
    }
    int b[n + 1][n + 1];
    memset(b, 0, sizeof(b));
    int i, j;
    int maxn = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {

            b[i][j] = max(b[i][j - 1], b[i - 1][j] + a[i]);
            if (b[i][j] > maxn)
                maxn = b[i][j];
        }
    }
    if (flag)
        cout << maxn;
    else
        cout << "0";
    return 0;
}
```
## 7-2 汉诺塔问题
### 题面

给定一个由n个圆盘组成的塔，这些圆盘按照大小递减的方式套在第一根桩柱上。现要将整个塔移动到另一根桩柱上，每次只能移动一个圆盘，且较大的圆盘在移动过程中不能放置在较小的圆盘上面。

**输入格式:**
输入由四行： 第一行是圆盘数量n(1<=n<=10); 第二行到第四行分别是三根桩柱的名字(字符串)，n个盘子套在第一根桩柱上。

**输出格式:**
输出移动步骤，每行输出一步。

**输入样例:**
在这里给出一组输入。例如：
```
2
a
b
c
结尾无空行
```
**输出样例:**
在这里给出相应的输出。例如：
```
a->b
a->c
b->c
结尾无空行
```
### 思路
把挪n个圆盘的大问题拆解成挪n-1个圆盘和挪第n个圆盘的小问题，要注意n==1时的特殊情况

### 代码
```c++
#include<iostream>
using namespace std;
void hanoi(string now,string target,string temp,int time)
{
	if(time==2)
	{
		cout<<now<<"->"<<temp<<endl;
		cout<<now<<"->"<<target<<endl;
		cout<<temp<<"->"<<target<<endl;
	}
	else if(time==1)
	{
		cout<<now<<"->"<<target<<endl;
	}
	else
	{
		hanoi(now,temp,target,--time);
		cout<<now<<"->"<<target<<endl;
		hanoi(temp,target,now,time);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	string a,b,c;
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	hanoi(a,c,b,n);
	return 0;
}
```

## 7-3 汉诺塔3
### 题面

约19世纪末，在欧州的商店中出售一种智力玩具，在一块铜板上有三根杆，最左边的杆上自上而下、由小到大顺序串着由64个圆盘构成的塔。目的是将最左边杆上的盘全部移到右边的杆上，条件是一次只能移动一个盘，且不允许大盘放在小盘的上面。 现在我们改变游戏的玩法，不允许直接从最左(右)边移到最右(左)边(每次移动一定是移到中间杆或从中间移出)，也不允许大盘放到下盘的上面。 Daisy已经做过原来的汉诺塔问题和汉诺塔II，但碰到这个问题时，她想了很久都不能解决，现在请你帮助她。现在有N个圆盘，她至少多少次移动才能把这些圆盘从最左边移到最右边？

**输入格式:**
包含多组数据，每次输入一个N值(1<=N=35)。

**输出格式:**
对于每组数据，输出移动最小的次数。

**输入样例:**
```
1
3
12
结尾无空行
```
**输出样例:**
```
2
26
531440
结尾无空行
```

### 思路

根据递龟特性推出3 * hanoi3(x - 1) + 2公式直接计算

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
long long hanoi3(long long x);
int main()
{
    long long n;
    while (scanf("%lld", &n) != EOF)
    {
        cout << hanoi3(n) << endl;
    }
    return 0;
}
long long hanoi3(long long x)
{
    long long re;
    if (x == 1)
    {
        re = 2;
    }
    else
    {
        re = 3 * hanoi3(x - 1) + 2;
    }
    return re;
}
```

## 7-4 汉诺塔2
### 题面

经典的汉诺塔问题经常作为一个递归的经典例题存在。可能有人并不知道汉诺塔问题的典故。汉诺塔来源于印度传说的一个故事，上帝创造世界时作了三根金刚石柱子，在一根柱子上从下往上按大小顺序摞着64片黄金圆盘。上帝命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一回只能移动一个圆盘。有预言说，这件事完成时宇宙会在一瞬间闪电式毁灭。也有人相信婆罗门至今仍在一刻不停地搬动着圆盘。恩，当然这个传说并不可信，如今汉诺塔更多的是作为一个玩具存在。Gardon就收到了一个汉诺塔玩具作为生日礼物。 　　Gardon是个怕麻烦的人（恩，就是爱偷懒的人），很显然将64个圆盘逐一搬动直到所有的盘子都到达第三个柱子上很困难，所以Gardon决定作个小弊，他又找来了一根一模一样的柱子，通过这个柱子来更快的把所有的盘子移到第三个柱子上。下面的问题就是：当Gardon在一次游戏中使用了N个盘子时，他需要多少次移动才能把他们都移到第三个柱子上？很显然，在没有第四个柱子时，问题的解是2^N-1，但现在有了这个柱子的帮助，又该是多少呢？

**输入格式:**
包含多组数据，每个数据一行，是盘子的数目N(1<=N<=64)。

**输出格式:**
对于每组数据，输出一个数，到达目标需要的最少的移动数。

**输入样例:**
```
1
3
12
结尾无空行
```
**输出样例:**
```
1
5
81
结尾无空行
```

### 思路
找规律，第二第三项比其前项多2，第四、五、六项比其前项多4，第七八九十比前项多8，以此类推

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int i = 1, flag = 2, cnt = 1;
        int re = 1;
        while (cnt++ < n)
        {
            if (i++ <= flag)
                re += pow(2, flag - 1);

            else
            {
                flag++;
                i = 1;
                cnt--;
            }
        }
        printf("%d\n", re);
    }
    return 0;
}
```


## 7-5 简单归并
### 题面

已知数组A和B各有m、n个元素，且元素按值非递减排列，现要求把A和B归并为一个新的数组C，且C中的数据元素仍然按值非递减排列。 例如，若A=(3，5，8，11)，B=(2，6，8，9，11，15，20)， 则C=(2，3，5，6，8，8，9，11，11，15，20)

**输入格式:**
首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。 每组测试数据输入两行，其中第一行首先输入A的元素个数m（1≤m≤100），然后输入m个元素。第2行首先输入B的元素个数n（1≤n≤100），然后输入n个元素。

**输出格式:**
对于每组测试数据。分别输出将A、B合并后的数组C的全部元素。输出的元素之间以一个空格分隔（最后一个数据之后没有空格）。

**输入样例:**
```
1
4 3 5 8 11
7 2 6 8 9 11 15 20
结尾无空行
```
**输出样例:**

```
2 3 5 6 8 8 9 11 11 15 20
结尾无空行
```

### 思路
虚伪的归并，把两个数组输到一起冒了个泡

### 代码
```c++
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int zushu;
	scanf("%d",&zushu);
	while(zushu)
	{
		int m,n,i=0;
		scanf("%d",&m);
		int a[m];
		while(i<m)
		{
			scanf("%d",&a[i]);
			i++;
		}
		scanf("%d",&n);
		i=0;
		int b[n+m];
		while(i<n)
		{
			scanf("%d",&b[i]);
			i++;
		}
		for(int i=0;i<m;++i)
		{
			b[n+i]=a[i];
		}
		for(int i=0;i<m+n;++i)
		{
			for(int j=0;j<m+n-i-1;++j)
			{
				if(b[j]>b[j+1])
				{
					swap(b[j],b[j+1]);
				}
			}
		}
		
		for(int i=0;i<m+n;++i)
		{
			if(!i) printf("%d",b[i]);
			else 
				printf(" %d",b[i]);
		}
        cout<<endl;
		zushu--;
	}
	
	return 0;
}
```

## 7-6 字符串的全排列
### 题面

给定一个全由小写字母构成的字符串，求它的全排列，按照字典序从小到大输出。

**输入格式:**
一行，一个字符串，长度不大于8。

**输出格式:**
输出所有全排列，每行一种排列形式，字典序从小到大。

**输入样例:**
```
abc
结尾无空行
```
**输出样例:**
```
abc
acb
bac
bca
cab
cba
结尾无空行
```

### 思路
用c++内置的permutation直接就可解出来,我好像手写了一个

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
void permu(string s, int begin);
int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length() - 1; ++i)
    {
        for (int j = 0; j < s.length() - i - 1; ++j)
        {
            if (s[j] > s[j + 1])
            {
                swap(s[j], s[j + 1]);
            }
        }
    }

    permu(s, 0);
    return 0;
}
void permu(string s, int begin)
{
    if (begin == s.length())
        cout << s << endl;

    else
        for (int i = begin; i < s.length(); ++i)
        {
            swap(s[i], s[begin]);
            permu(s, begin + 1);
        }
}
```
## 7-7 逆序对
### 题面

求逆序对

**输入格式:**
第一行是一个整数n，（n<=1000,000）表示输入序列的长度，接下来一行是n个整数(每个数的绝对值小于10 9)。

**输出格式:**
一个数，表示逆序对个数(逆序即任意一对数前面的数比后面的数大即为一对逆序对)。

**输入样例:**
```
10
1 3 5 7 9 8 4 2 6 10
结尾无空行
```
**输出样例:**
```
14
结尾无空行
```

### 思路
贪心归并可解

### 代码
```c++
#include <bits/stdc++.h>
#define N 1000001
long long a[N], b[N];
long long find(long long a[], long long b[], long long first, long long last)
{
    long long i, j, k = 0, mid;
    long long num = 0;
    if (first >= last)
    {
        return 0;
    }
    mid = (first + last) / 2;
    k = i = first;
    j = mid + 1;
    num = find(a, b, i, mid) + find(a, b, j, last);
    while ((i <= mid) && (j <= last))
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
            num += j - mid - 1;
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
        num += j - mid - 1;
    }
    while (j <= last)
    {
        b[k++] = a[j++];
    }
    for (i = first; i <= last; ++i)
    {
        a[i] = b[i];
    }
    return num;
}

int main()
{
    long long n;
    scanf("%lld", &n);
    for (long long i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    long long re = find(a, b, 0, n - 1);
    printf("%lld", re);

    return 0;
}
```
## 7-8 二分查找
### 题面

请实现有重复数字的有序数组的二分查找。

输出在数组中第一个大于等于查找值的位置，如果数组中不存在这样的数，则输出数组长度加一。

**输入格式:**
输入第一行有两个数，第一个数为数组长度n（≤10^6），第二个数为需要查找的数。

接下来有n个整数，以空格或换行符分隔。

**输出格式:**
输出待查找的数的位置。

**输入样例:**
```
5 4
1 2 4 4 5
结尾无空行
```
**输出样例:**
```
3
结尾无空行
```
### 思路

输入数据的同时查找，找到结果直接跳出

### 代码
```c++
#include<bits/stdc++.h>
using namespace std;
#define N 1000001
int a[N];
int main()
{
	int n,m,t,flag=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		if(m<=a[i]&&!flag)
		{
			cout<<i+1;
			flag=1;
            break;
		}
	}
	if(!flag)
	{
		cout<<n+1;
	}
    
	return 0;
}
```
