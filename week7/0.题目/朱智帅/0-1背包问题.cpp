#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int value[405], weight[405];
int main()
{
	int n, c, i, j;
	while (scanf("%d%d",&n, &c)!=EOF)
	{
		int allweightvalue[1505] = { 0 };
		for (i = 0; i < n; i++)
		{
			cin >> weight[i];
		}
		for (i = 0; i < n; i++)
		{
			cin >> value[i];
		}
		for (i = 0; i < n; i++)
		{
			for (j = c; j >= weight[i]; j--)
			{
				if (allweightvalue[j - weight[i]] + value[i] > allweightvalue[j]) allweightvalue[j] = allweightvalue[j - weight[i]] + value[i];
			}
			//for (j = 0; j <= c; j++)
				//cout << "allweightvalue[" << j << "]: " << allweightvalue[j] << endl;
			//cout << endl;
		}
		cout << allweightvalue[c] << endl;
	}
	return 0;
}/*
4 9
2 3 4 5
3 4 5 7
12
*/