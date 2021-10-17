#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<set>
#include<list>
#include<queue>
#include<string.h>
char moshichuan[50001];
char cc[21];
using namespace std;
int main()
{
	int n, len;
	cin >> n;
	cin >> moshichuan;
	len = strlen(moshichuan);
	while (n--)
	{
		cin >> cc;
		int lencc = strlen(cc);
		int i, cnt = 0;
		for (i = 0; i < len - lencc + 1;)
		{
			int s1 = i, s2 = 0;
			while (1)
			{
				if (moshichuan[s1] == cc[s2])
				{
					s2 = s2 + 1;
					s1 = s1 + 1;
					if (s2 == lencc)
					{
						s2 = 0;
						cnt++;
						i = i + 1;
						break;
					}
				}
				else
				{
					i++;
					s2 = 0;
					s1 = 0;
					break;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}