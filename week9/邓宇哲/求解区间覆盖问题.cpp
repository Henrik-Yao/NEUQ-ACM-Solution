#include <algorithm>
#include <fstream>
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
