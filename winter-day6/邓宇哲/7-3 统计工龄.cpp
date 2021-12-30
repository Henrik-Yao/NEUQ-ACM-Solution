#include <iostream>
#include <algorithm>
using namespace std;
int list[100005];
main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> list[i];
	}
	sort(list, list + n);
	for (int i = 0; i < n;)
	{
		int t = list[i], numb = 0;
		while (i < n && list[i] == t)
		{
			i++;
			numb++;
		}
		cout << t << ":" << numb << endl;
	}
}