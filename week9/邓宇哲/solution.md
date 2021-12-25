# 求解区间覆盖问题
找空隙的长度，从最大的开始删。
```c++
#include <algorithm>
#include <iostream>
using namespace std;
int m;
main()
{
	int n;
	cin >> m >> n;
	int list[m];
	for (int i = 0; i < m; i++)
	{
		cin >> list[i];
	}
	sort(list, list + m);
	int space[m - 1];
	for (int i = 0; i < m-1; i++)
	{
		space[i] = list[i + 1] - list[i] - 1;
	}
	sort(space, space + (m - 1));
	int len=list[m - 1] - list[0] + 1;
	for (int i = 0; i < n-1;i++)
	{
		len -= space[m-2-i];
	}
	cout << len<<endl;
}
```
# 铺满方格
动态规划。  
list[i] = list[i - 1] + list[i - 2] + list[i - 3]
```c++
#pragma GCC optimize(3)
#include <iostream>
using namespace std;
long long list[51] = {0, 1, 2, 4};
int function(int);
main()
{

	for (int i = 4; i < 51; i++)
	{
		list[i] = list[i - 1] + list[i - 2] + list[i - 3];
	}
	int n;
	while (cin >> n)
		cout << list[n]<<endl;
}
```