#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int main()
{
	int left, right, i, j, cnt, tag[100001];
	while (cin >> left >> right)
	{
		cnt = 0;
		for (i = left; i < right + 1; i++)
		{
			bool flag = true;
			int k = sqrt(i) + 1;
			for (j = 2; j < k; j++)
			{
				if (i % j == 0)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				tag[cnt++] = i;
			}
		}
		for (i = 0; i < cnt-1; i++)
		{
			cout << tag[i] << " ";
		}
		cout << tag[i] << endl;
	}
	return 0;
}