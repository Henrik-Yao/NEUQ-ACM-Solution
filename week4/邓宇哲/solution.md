# 素数
采用欧拉筛法，结果保存至bool类型的数组里，遍历数组输出
```c++
#include <iostream>
using namespace std;
bool ispri[10011] = {1, 1};
int pri[10000] = {0};
main()
{
	int point = 0;          //要定义一个指针，指向最新加入的素数的位置。
	for (int i = 2; i <= 10000; i++)
	{
		if (ispri[i] == 0)  //如果是0代表是素数
		{
			pri[point] = i; //保存至int类型数组
			point++;
		}
		for (int j = 0; j < point; j++)
		{
			if (i * pri[j] > 10000)//不用太大，防止越界
				break;
			ispri[i * pri[j]] = 1;//标记为合数
			if (i % pri[j] == 0)//已经找到下次所需要的所有素数
				break;
		}
	}
	int n, m;
	while (cin >> n >> m)
	{
		int a[10000],k=0;
		for (int i = n; i <= m; i++)
		{
			if (ispri[i] == 0)
			{
				a[k] = i;
				k++;
			}
		}
		for (int i = 0; i < k-1;i++)
		{
			cout << a[i] << ' ';

		}
		cout << a[k - 1] << endl;
	}
}
```
# 炒鸡楼梯
数列递推

sign[ i ] = sign[ i - 1 ] + sign[ i - 2 ];
```c++
#include <iostream>
using namespace std;
main()
{
    long long sign[41] = {0, 0,1,2};
    for (int i = 4; i <= 40;i++)
    {
        sign[i] = sign[i - 1] + sign[i - 2];
    }
        int n;
    cin >> n;
    for (int p = 0; p < n;p++)
    {
        int a;
        cin >> a;
        cout << sign[a]<<endl;
    }
}
```
# 素数个数
同理第一题
```c++
#include <iostream>
using namespace std;
bool ispri[10000005] = {1, 1};
long pri[1000000] = {0};
long point = 0;
main()
{
	
	for (long i = 2; i <= 10000000; i++)
	{
		if (ispri[i] == 0)
		{
			pri[point] = i;
			point++;
		}
		for (long j = 0; j < point; j++)
		{
			if (i * pri[j] > 10000000)
				break;
			ispri[i * pri[j]] = 1;
			if (i % pri[j] == 0)
				break;
		}
	}
	long n,sum=0;
	cin>>n;
	for (long i = 1; i <=n;i++)
	{
		if(ispri[i]==0)
		{
			sum++;
		}
	}
	cout << sum;
}
```
# 幂次取余
见注释
```c++
#include <iostream>
using namespace std;
unsigned long long fast(unsigned long long, unsigned long long,unsigned long long);
main()
{
    int n;
    cin >> n;
    unsigned long long a, b, c;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        cout << fast(a, b,c)  << endl;
    }
}
unsigned long long fast(unsigned long long a, unsigned long long b, unsigned long long c)
{
    int ans = 1;        //初始化为1
    a = a % c;          //先取余
    while(b>0) {
        if(b % 2 == 1)  //分奇偶讨论
        ans = (ans * a) % c;
        b = b/2;
        a = (a * a) % c;
    }
    return ans;
}
```